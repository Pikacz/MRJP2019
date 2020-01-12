//
//  BlockEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "BlockEnvironment.hpp"

#include "../staticCheck/redeclaration/VariableRedeclarationError.hpp"

#include "../assembler/values/AsmIntConstant.hpp"
#include "../assembler/instructions/AsmAdd.hpp"
#include "../assembler/instructions/AsmSub.hpp"
#include "../assembler/instructions/AsmMov.hpp"
#include "../assembler/instructions/AsmPop.hpp"
#include "../assembler/instructions/AsmPush.hpp"
#include "../assembler/values/AsmMemory.hpp"

#include "function/Function.hpp"
#include "function/FunctionInitializer.hpp"

#include <optional>
#include <algorithm>

using namespace std;


BlockEnvironment::BlockEnvironment(
    Environment const * parent
) noexcept: parent(parent), Environment() {
    
    if (auto p = dynamic_cast<BlockEnvironment const *>(parent)) {
        p->addChild(this);
    }
}


// MARK: - variables
void BlockEnvironment::declareVariable(
    string name, Type const * type, size_t line, size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        throw VariableRedeclarationError(line, column, name);
    }
    variables[key] = make_unique<Variable>(type, this);
}


Variable const * BlockEnvironment::getVariableNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        return search->second.get();
    }
    return parent->getVariableNamed(name, line, column);
}


// MARK: - functions
Function const * BlockEnvironment::getFunctionNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getFunctionNamed(name, line, column);
}


// MARK: - types
Type const * BlockEnvironment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getTypeNamed(name, line, column);
}


// MARK: - compilation
void BlockEnvironment::initializeVariables(
    list<unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
}


void BlockEnvironment::cleanVariables(
    list<unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
}


int BlockEnvironment::getSize() const noexcept {
    size_t result = 0;
    
    for (auto& it : variables) {
        result += it.second.get()->getType()->pointerSize();
    }
    
    return (int)result;
}


void BlockEnvironment::setVariables(
    list<unique_ptr<const AsmInstruction>> & compiled, int firstAt
) const noexcept {
    
    for (auto& it : variables) {
        firstAt -= it.second.get()->getType()->pointerSize();
        it.second.get()->setMemory(
            make_unique<AsmMemory>(
                firstAt,
                make_unique<AsmRegister>(AsmRegister::Type::rbp),
                nullopt,
                AsmMemory::ScaleT::one
            )
        );
        
    }
}

int BlockEnvironment::childMaxSize() const noexcept {
    int result = 0;
    for (auto & child : children) {
        result = max(result, child->getSize());
    }
    return result;
}



void BlockEnvironment::addChild(BlockEnvironment const * child) const noexcept {
    children.push_back(child);
}
