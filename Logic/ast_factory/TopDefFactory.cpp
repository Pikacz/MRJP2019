//
//  TopDefFactory.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "TopDefFactory.hpp"

#include <sstream>
#include <vector>

#include "../parser/LatteLexer.h"
#include "../parser/LatteParser.h"
#include "../staticCheck/ParserError.hpp"

#include "../environment/function/Function.hpp"
#include "../environment/EnvWithFunctions.hpp"

#include "stmts/DecFactory.hpp"
#include "stmts/StatementFactory.hpp"

using namespace std;
using namespace antlr4;


class ThrowingErrorListener: public BaseErrorListener {
    void syntaxError(
        Recognizer *recognizer,
        Token *offendingSymbol,
        size_t line,
        size_t charPositionInLine,
        const std::string &msg,
        std::exception_ptr e
    ) override {
        stringstream ss;
        ss << "parsing error at " << line << ":" << charPositionInLine << " " << msg << endl;
        throw ParserError(ss.str());
    }
};


static void declareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    EnvWithFunctions * gEnv,
    vector<LatteParser::TopDefContext *> & topDefs
) noexcept(false);

static void declareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    EnvWithFunctions * gEnv
) noexcept(false);


static void defineFunctions(
    vector<LatteParser::FunctionContext *> const & funcs,
    vector<Function *> const & incompleteFuncs
) noexcept(false);

static void declareTypes(
    vector<LatteParser::TypeContext *> & types,
    vector<CustomType *> & incompleteTypes,
    GlobalEnvironment * gEnv,
    vector<LatteParser::TopDefContext *> & topDefs
) noexcept(false);


static void defineTypes(
    vector<LatteParser::TypeContext *> const & types,
    vector<CustomType *> & incompleteTypes
) noexcept(false);


unique_ptr<const GlobalEnvironment> TopDefFactory::createFrom(string code) noexcept(false) {
    unique_ptr<GlobalEnvironment> env = make_unique<GlobalEnvironment>();
    
    ANTLRInputStream input(code);
    
    unique_ptr<ThrowingErrorListener> errorHandeler = make_unique<ThrowingErrorListener>();
    
    LatteLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(errorHandeler.get());
    
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    LatteParser parser(&tokens);
    
    vector<LatteParser::TopDefContext *> topDefs;
    auto m = parser.main();
    if (m != nullptr) {
        topDefs = m->topDef();
    }
    
    // declare types here
    vector<LatteParser::TypeContext *> types;
    vector<CustomType *> incompleteTypes;
    
    declareTypes(types, incompleteTypes, env.get(), topDefs);
    
    // declare functions
    vector<LatteParser::FunctionContext *> funcs;
    vector<Function *> incompleteFuncs;
    
    declareFunctions(
        funcs, incompleteFuncs, env.get(), topDefs
    );
    
    // complete types
    defineTypes(types, incompleteTypes);
    
    // define functions
    defineFunctions(funcs, incompleteFuncs);

//    lexer.removeErrorListeners();
    return move(env);
}

// MARK: - declare types
static void declareTypes(
    vector<LatteParser::TypeContext *> & types,
    vector<CustomType *> & incompleteTypes,
    GlobalEnvironment * gEnv,
    vector<LatteParser::TopDefContext *> & topDefs
) noexcept(false) {
    
    for (auto & def : topDefs) {
        auto type = def->type();
        if (type != nullptr) {
            string name = type->Identifier()->getText();
            auto token = type->Identifier()->getSymbol();
            incompleteTypes.push_back(
                gEnv->declareType(
                    name, token->getLine(), token->getCharPositionInLine()
                )
            );
            types.push_back(type);
        }
    }
    
    for (size_t i = 0; i < types.size(); ++i) {
        auto extend = types[i]->extendBlock();
        if (extend != nullptr) {
            string nm = extend->Identifier()->getText();
            auto token = extend->Identifier()->getSymbol();
            incompleteTypes[i]->setParent(
                gEnv->getTypeNamed(
                    nm, token->getLine(), token->getCharPositionInLine()
                ),
                token->getLine(),
                token->getCharPositionInLine()
            );
        }
    }
    
}


// MARK: - define types

static void declareMembers(
    LatteParser::TypeContext * type,
    CustomType * incompleteType,
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs
) noexcept(false);

static void completeType(
    LatteParser::TypeContext * type,
    CustomType * incompleteType,
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs
) noexcept(false);

static void defineTypes(
    vector<LatteParser::TypeContext *> const & types,
    vector<CustomType *> & incompleteTypes
) noexcept(false) {
    size_t declaredTypes = 0;
    size_t i = 0;
    
    vector<vector<LatteParser::FunctionContext *>> funcs(types.size());
    vector<vector<Function *>> incompleteFuncs(types.size());
    
    // koeljność ważna bo mogą być błędy w dziedziczeniu
    while (declaredTypes != types.size()) {
        if (!incompleteTypes[i]->isDeclared()) {
            auto pType = incompleteTypes[i]->getParent();
            bool canBeDeclared = (pType == nullopt || (*pType)->isDeclared());
            if (canBeDeclared) {
                declareMembers(types[i], incompleteTypes[i], funcs[i], incompleteFuncs[i]);
                incompleteTypes[i]->markAsDeclared();
                declaredTypes++;
            }
        }
        i = (i + 1) % types.size();
    }
    
    size_t completedTypes = 0;
    i = 0;
    while (completedTypes != types.size()) {
        if (!incompleteTypes[i]->isCompleted()) {
            auto pType = incompleteTypes[i]->getParent();
            bool canBeCompleted = (pType == nullopt || (*pType)->isCompleted());
            if (canBeCompleted) {
                completeType(types[i], incompleteTypes[i], funcs[i], incompleteFuncs[i]);
                incompleteTypes[i]->markAsCompleted();
                completedTypes++;
            }
        }
        i = (i + 1) % types.size();
    }
}


static void declareMembers(
    LatteParser::TypeContext * type,
    CustomType * incompleteType,
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs
) noexcept(false) {
    auto tEnv = incompleteType->getEnvironment();

    auto members = type->typeMember();
    for (auto & m : members) {
        auto var = m->typeVar();
        auto func = m->function();
        
        if (var != nullptr) {
            auto t = DecFactory::getType(tEnv, var->decType());
            auto nm = var->Identifier()->getText();
            auto token = var->Identifier()->getSymbol();
            tEnv->declareVariable(
                nm, t, token->getLine(), token->getCharPositionInLine()
            );
        }
        
        if (func != nullptr) {
            funcs.push_back(func);
        }
    }
    
    declareFunctions(funcs, incompleteFuncs, tEnv);
    
}

static void completeType(
    LatteParser::TypeContext * type,
    CustomType * incompleteType,
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs
) noexcept(false) {
    defineFunctions(funcs, incompleteFuncs);
}


// MARK: - declare functions
static FunctionInitializer::Parameter getParameter(
    Environment * env,
    LatteParser::ArgContext * arg
) noexcept(false);


static void declareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    EnvWithFunctions * gEnv
) noexcept(false) {
    for (size_t i = 0; i < funcs.size(); ++i) {
        auto func = funcs[i];
        string fName = func->Identifier()->getText();
        
        auto rType = DecFactory::getType(gEnv, func->decType());
        
        vector<FunctionInitializer::Parameter> params;
        auto paramsCtx = func->funcArgs()->arg();
        for (auto& param: paramsCtx) {
            params.push_back(getParameter(gEnv, param));
        }
        FunctionInitializer fInit(rType, fName, params);
        
        incompleteFuncs.push_back(
            gEnv->declareFunction(
                fInit,
                func->Identifier()->getSymbol()->getLine(),
                func->Identifier()->getSymbol()->getCharPositionInLine()
            )
        );
    }
}

static void declareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    EnvWithFunctions * gEnv,
    vector<LatteParser::TopDefContext *> & topDefs
) noexcept(false) {
    
    for (auto& def : topDefs) {
        auto func = def->function();
        if (func != nullptr) {
            funcs.push_back(func);
        }
    }
    declareFunctions(funcs, incompleteFuncs, gEnv);
}


static FunctionInitializer::Parameter getParameter(
    Environment * env,
    LatteParser::ArgContext * arg
) noexcept(false) {
    auto tCtx = arg->decType();
    auto type = DecFactory::getType(env, tCtx);
    
    auto nm = arg->Identifier();
    
    return FunctionInitializer::Parameter(
        type,
        nm->getText(),
        nm->getSymbol()->getLine(),
        nm->getSymbol()->getCharPositionInLine()
    );
}


// MARK: - define functions
static void defineFunctions(
    vector<LatteParser::FunctionContext *> const & funcs,
    vector<Function *> const & incompleteFuncs
) noexcept(false) {
    
    for (size_t i = 0; i < funcs.size(); ++i) {
        auto fEnv = incompleteFuncs[i]->getEnvironment();
        vector<unique_ptr<const Statement>> body;
        
        VarValues vals;
        
        StatementFactory::getStatements(fEnv, funcs[i]->block(), vals, body);
        incompleteFuncs[i]->completeWith(move(body));
        
    }
    
}
