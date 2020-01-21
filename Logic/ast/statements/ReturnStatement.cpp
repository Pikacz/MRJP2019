//
//  ReturnStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "ReturnStatement.hpp"
#include "../../staticCheck/types/InvalidReturnType.hpp"

#include "../../environment/types/builtin/LatteVoid.hpp"

#include "../../assembler/instructions/AsmJmp.hpp"

using namespace std;


ReturnStatement::ReturnStatement(
    size_t line,
    size_t column,
    Environment const * env,
    optional<unique_ptr<const Expression>> expr
) noexcept: expr(move(expr)), voidType(env->getLatteVoid()), Statement(line, column) {}


bool ReturnStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ReturnStatement const *>(node)) {
        if (expr != nullopt && nd->expr != nullopt) {
            return expr->get()->isEqualTo(nd->expr->get());
        } else {
            return expr == nullopt && nd->expr == nullopt;
        }
    }
    return false;
}


bool ReturnStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    if (expr.has_value()) {
        if (!expr->get()->isKindOf(type)) {
            throw InvalidReturnType(
                getLine(),
                getColumn(),
                type->getName(),
                expr->get()->getType()->getName()
            );
        }
    } else {
        if (!voidType->isKindOf(type)) {
            throw InvalidReturnType(
                getLine(),
                getColumn(),
                type->getName(),
                voidType->getName()
            );
        }
    }
    
    return true;
}


void ReturnStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    if (expr != nullopt) {
        AsmRegistersHandler regHandler;
        expr->get()->compile(
            AssemblerValue::Size::bit64,
            compiled,
            env,
            regHandler,
            handler,
            AsmRegister::Type::rax
        );
    }
    unique_ptr<const AsmInstruction> exit = make_unique<AsmJmp>(exitLabel);
    compiled.push_back(move(exit));
}


size_t ReturnStatement::fakeVariablesCount() const noexcept {
    if (expr != nullopt) {
        return expr->get()->fakeVariablesCount();
    }
    return 0;
}
