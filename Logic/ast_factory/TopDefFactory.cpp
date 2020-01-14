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


static void delcareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    GlobalEnvironment * gEnv,
    LatteParser * parser
) noexcept(false);


static void defineFunctions(
    vector<LatteParser::FunctionContext *> const & funcs,
    vector<Function *> const & incompleteFuncs
) noexcept(false);



unique_ptr<const GlobalEnvironment> TopDefFactory::createFrom(string code) noexcept(false) {
    unique_ptr<GlobalEnvironment> env = make_unique<GlobalEnvironment>();
    
    ANTLRInputStream input(code);
    
//    unique_ptr<ThrowingErrorListener> errorHandeler = make_unique<ThrowingErrorListener>();
    
    LatteLexer lexer(&input);
//    lexer.removeErrorListeners();
//    lexer.addErrorListener(errorHandeler.get());
    
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    LatteParser parser(&tokens);
    
//    auto m = parser.main();
//    auto defs = m->topDef();
    
    // declare types here
    
    // declare functions
    vector<LatteParser::FunctionContext *> funcs;
    vector<Function *> incompleteFuncs;
    
    delcareFunctions(
        funcs, incompleteFuncs, env.get(), &parser
    );
    
    // complete types
    
    // define functions
    defineFunctions(funcs, incompleteFuncs);

//    lexer.removeErrorListeners();
    return move(env);
}


// MARK: - declare functions
static FunctionInitializer::Parameter getParameter(
    Environment * env,
    LatteParser::ArgContext * arg
) noexcept(false);


static void delcareFunctions(
    vector<LatteParser::FunctionContext *> & funcs,
    vector<Function *> & incompleteFuncs,
    GlobalEnvironment * gEnv,
    LatteParser * parser
) noexcept(false) {
    auto m = parser->main();
    if (m == nullptr) { return; }
    auto defs = m->topDef();
    
    
    for (auto& def : defs) {
        auto func = def->function();
        if (func != nullptr) {
            
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
            
            funcs.push_back(func);
        }
    }
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
        
        StatementFactory::getStatements(fEnv, funcs[i]->block(), body);
        incompleteFuncs[i]->completeWith(move(body));
        
    }
    
}
