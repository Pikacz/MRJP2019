//
//  ExprNewObject.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprNewObject.hpp"

#include "../../staticCheck/types/TypeNotAnObject.hpp"



using namespace std;

static CustomType const * _getType(Type const * type, size_t line, size_t column) noexcept(false) {
    auto t = dynamic_cast<CustomType const *>(type);
    if (t == nullptr) {
        throw TypeNotAnObject(line, column, type->getName());
    }
    return t;
}


ExprNewObject::ExprNewObject(
    Type const * type, size_t line, size_t column
) noexcept(false): objType(_getType(type, line, column)), Expression(type, line, column) {
}


bool ExprNewObject::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprNewObject const *>(node)) {
        return objType->getName() == nd->objType->getName();
    }
    return false;
}


void ExprNewObject::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "new object expr is not implemented yet";
}
