//
//  AssignementStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AssignementStatement.hpp"

#include "../../staticCheck/types/InvalidType.hpp"
#include "../../staticCheck/NotLValue.hpp"
#include "../expressions/VarExpression.hpp"
#include "../../assembler/instructions/AsmPush.hpp"
#include "../../assembler/instructions/AsmPop.hpp"
#include "../../assembler/GarbageCollector.hpp"

using namespace std;

static unique_ptr<const LExpression> getLVal(
    unique_ptr<const Expression> var
) noexcept(false) {
    if (auto ptr = dynamic_cast<LExpression const *>(var.get())) {
        var.release();
        return unique_ptr<const LExpression>(ptr);
    }
    throw NotLValue(var.get()->getLine(), var.get()->getColumn());
}

AssignementStatement::AssignementStatement(
    size_t line,
    size_t column,
    unique_ptr<const Expression> var,
    unique_ptr<const Expression> expr,
    bool first_association
) noexcept(false): var(getLVal(move(var))), expr(move(expr)), first_association(first_association), Statement(line, column) {
    if (! this->expr.get()->isKindOf(this->var->getType())) {
        throw InvalidType(line, column, this->var->getType()->getName(), this->expr.get()->getType()->getName());
    }
}


bool AssignementStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<AssignementStatement const *>(node)) {
        return var->isEqualTo(nd->var.get()) && expr.get()->isEqualTo(nd->expr.get());
    }
    return false;
}

bool AssignementStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    return expr.get()->isTerminating();
}

void AssignementStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    AsmRegistersHandler regHandler;
    
    if (expr->getType()->isPointer() && !first_association) {
        AsmRegistersHandler regHandler;
        var->loadValueInto(
            AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled, env, regHandler
        );
        for (size_t i = 0; i < 2; ++i) {
            compiled.push_back(
                make_unique<AsmPush>(
                    AssemblerValue::Size::bit64,
                    make_unique<AsmRegister>(AsmRegister::Type::rax)
                )
            );
        }
    }
    
    regHandler.freeRegister(AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled);
    expr.get()->compile(
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler,
        handler,
        AsmRegister::Type::rax
    );
    var->saveValueFrom(
        AsmRegister::Type::rax,
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler
    );
    
    if (expr->getType()->isPointer() && !first_association) {
        for (size_t i = 0; i < 2; ++i) {
            compiled.push_back(
                make_unique<AsmPop>(
                    AssemblerValue::Size::bit64,
                    make_unique<AsmRegister>(AsmRegister::Type::rax)
                )
            );
        }
        AsmRegistersHandler regHandler;
        GarbageCollector::decCounter(
            AsmRegister::Type::rax, compiled, env, regHandler, handler
        );
    }
}


size_t AssignementStatement::fakeVariablesCount() const noexcept {
    return expr->fakeVariablesCount();
}
