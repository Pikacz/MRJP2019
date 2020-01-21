//
//  ExprNull.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprNull.hpp"

#include "../../staticCheck/types/TypeNotAnObject.hpp"



using namespace std;

static CustomType const * _getType(Type const * type, size_t line, size_t column) noexcept(false) {
    auto t = dynamic_cast<CustomType const *>(type);
    if (t == nullptr) {
        throw TypeNotAnObject(line, column, type->getName());
    }
    return t;
}



ExprNull::ExprNull(
    size_t line,
    size_t column,
    Type const * type
) noexcept(false): objType(_getType(type, line, column)), Expression(type, line, column) {
}


bool ExprNull::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprNull const *>(node)) {
        return objType->getName() == nd->objType->getName();
    }
    return false;
}


void ExprNull::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "null expr is not implemented yet";
}
