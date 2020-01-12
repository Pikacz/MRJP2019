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
    std::string typeName,
    std::string varName
) noexcept(false): typeName(typeName), varName(varName), Statement(line, column) {
    
    auto type = env->getTypeNamed(typeName, line, column);
    env->declareVariable(varName, type, line, column);
}


bool DeclareStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<DeclareStatement const *>(node)) {
        return typeName == nd->typeName && varName == nd->varName;
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
