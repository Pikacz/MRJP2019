//
//  ExprCompareObjects.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprCompareObjects.hpp"
#include "../../staticCheck/types/InvalidType.hpp"

using namespace std;

ExprCompareObjects::ExprCompareObjects(
    Environment const * env,
    size_t line,
    size_t column,
    std::unique_ptr<const Expression> _lhs,
    std::unique_ptr<const Expression> _rhs,
    bool equal
) noexcept(false): checkIfEqual(equal), Expr2Arg(env->getLatteBool(), line, column, move(_lhs), move(_rhs)) {
    auto lType = lhs->getType();
    auto rType = rhs->getType();
    
    bool ok = lType->isKindOf(rType) || rType->isKindOf(lType);
    if (!ok) {
        throw InvalidType(
            line,
            column,
            lType->getName(),
            rType->getName()
        );
    }
}


bool ExprCompareObjects::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprCompareObjects const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


void ExprCompareObjects::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "compare objects is not implemented yet";
}
