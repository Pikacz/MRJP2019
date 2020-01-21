//
//  ExprDot.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprDot.hpp"

using namespace std;



ExprDot::ExprDot(
    size_t line,
    size_t column,
    std::unique_ptr<const Expression> lhs,
    std::unique_ptr<const Expression> rhs
) noexcept(false): rhs(move(rhs)), lhs(move(lhs)), Expression(rhs->getType(), line, column) {
    throw "TODO";
}


bool ExprDot::isTerminating() const noexcept {
    return false;
}


bool ExprDot::isEqualTo(AstNode const * node) const noexcept {
    throw "TODO";
}

void ExprDot::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "TODO";
}


size_t ExprDot::fakeVariablesCount() const noexcept {
    throw "TODO";
}
