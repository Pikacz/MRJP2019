//
//  DeclareStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "DeclareStatement.hpp"


DeclareStatement::  DeclareStatement(
    size_t line,
    size_t column,
    BlockEnvironment * env,
    Type const * type,
    std::string varName
) noexcept(false): type(type), varName(varName), Statement(line, column) {
    
    env->declareVariable(varName, type, line, column);
}


bool DeclareStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<DeclareStatement const *>(node)) {
        return type->isKindOf(nd->type) && nd->type->isKindOf(type) && varName == nd->varName;
    }
    return false;
}


void DeclareStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    
}
