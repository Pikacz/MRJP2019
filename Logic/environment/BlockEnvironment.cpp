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
) noexcept: parent(parent), func_params(0), Environment() {
    
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

void BlockEnvironment::markFuncCall(size_t parameters_count) noexcept {
    func_params = max(parameters_count + 1, func_params);
}

FuncVariable const * BlockEnvironment::getConcatStrings() const noexcept {
    return parent->getConcatStrings();
}

// MARK: - types
Type const * BlockEnvironment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getTypeNamed(name, line, column);
}


// MARK: - string
AsmLabel const * BlockEnvironment::registerString(string str) const noexcept {
    return parent->registerString(str);
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


size_t BlockEnvironment::getSize() const noexcept {
    size_t result = 0;
    
    for (auto& it : variables) {
        result += it.second.get()->getType()->pointerSize();
    }
    size_t children_size = 0;
    
    for (auto& child : children) {
        children_size = max(children_size, child->getSize());
    }
    
    return result + children_size;
}


size_t BlockEnvironment::getFuncParams() const noexcept {
    size_t result = func_params;
    for (auto& child : children) {
        result = max(result, child->getFuncParams());
    }
    return result;
}


void BlockEnvironment::setVariables(
    size_t firstAt
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
    for (auto& child : children) {
        child->setVariables(firstAt);
    }
}



void BlockEnvironment::addChild(BlockEnvironment const * child) const noexcept {
    children.push_back(child);
}
