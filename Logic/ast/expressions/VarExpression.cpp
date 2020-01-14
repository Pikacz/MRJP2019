//
//  VarExpression.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "VarExpression.hpp"

using namespace std;


VarExpression::VarExpression(
    size_t line, size_t column, Variable const * var
) noexcept:
    var(var),
    LExpression(var->getType(), line, column)
{
};


void VarExpression::compile(
    AssemblerValue::Size type,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    loadValueInto(
        destination,
        type,
        compiled,
        env,
        handler
    );
}

unique_ptr<const AssemblerValue> VarExpression::getAddress(
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler
) const noexcept {
    return var->getAddress(size, compiled, env, handler);
}


bool VarExpression::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<VarExpression const *>(node)) {
        return var->isEqualTo(nd->var);
    }
    return false;
}
