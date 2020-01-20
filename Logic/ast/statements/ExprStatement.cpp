//
//  ExprStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprStatement.hpp"
#include "../../assembler/GarbageCollector.hpp"


using namespace std;

ExprStatement::ExprStatement(
    size_t line,
    size_t column,
    std::unique_ptr<const Expression> _expr
) noexcept(false): expr(move(_expr)), Statement(line, column) {
}


bool ExprStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprStatement const *>(node)) {
        return expr.get()->isEqualTo(nd->expr.get());
    }
    return false;
}


void ExprStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    AsmRegistersHandler regHandler;
    regHandler.freeRegister(
        AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled
    );
    expr.get()->compile(
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler,
        handler,
        AsmRegister::Type::rax
    );
    AsmRegistersHandler regHandler2;
    
    if (expr->getType()->isPointer()) {
        GarbageCollector::decCounter(
            AsmRegister::Type::rax, compiled, env, regHandler2, handler
        );
    }
}


bool ExprStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    return expr.get()->isTerminating();
}


size_t ExprStatement::fakeVariablesCount() const noexcept {
    return expr->fakeVariablesCount();
}
