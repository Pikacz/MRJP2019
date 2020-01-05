//
//  AstNode.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AstNode.hpp"

AstNode::AstNode(size_t line, size_t column) noexcept: line(line), column(column) {}

AstNode::~AstNode() {}

size_t AstNode::getLine() const noexcept {
    return line;
}

size_t AstNode::getColumn() const noexcept {
    return column;
}
