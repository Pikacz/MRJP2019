//
//  CustomType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CustomType.hpp"

#include "../../../staticCheck/types/CyclicDependency.hpp"
#include "../../../staticCheck/types/CantBeExtended.hpp"
#include "../../variables/Variable.hpp"

#include <cassert>

using namespace std;


CustomType::CustomType(
    string name, Environment const * globalEnv
) noexcept:
    name(name),
    parentType(nullopt),
    env(make_unique<TypeEnvironment>(globalEnv)),
    _isDeclared(false),
    _idCompleted(false) {
        
}


bool CustomType::isKindOf(Type const * type) const noexcept {
    if (auto nd = dynamic_cast<CustomType const *>(type)) {
        if (nd->name == name) {
            return true;
        }
    }
    if (parentType != nullopt) {
        return (*parentType)->isKindOf(type);
    }
    return false;
}


string CustomType::getName() const noexcept {
    return name;
}


size_t CustomType::pointerSize() const noexcept {
    return 8;
}


void CustomType::setParent(
    Type const * _parent, size_t line, size_t column
) noexcept(false) {
    assert(parentType == nullopt);
    
    CustomType const * parent = dynamic_cast<CustomType const *>(_parent);
    if (parent == nullptr) {
        throw CantBeExtended(line, column, _parent->getName());
    }
    if (parent->isKindOf(this)) {
        throw CyclicDependency(line, column, this->getName(), parent->getName());
    }
    parentType = parent;
    env->setParent(parent->getEnvironment());
}


TypeEnvironment * CustomType::getEnvironment() const noexcept {
    return env.get();
}

Variable const * CustomType::getMemberNamed(std::string name, size_t line, size_t column) const noexcept(false) {
    return env->getVariableNamed(name, false, line, column);
}


void CustomType::compile(
    list<unique_ptr<const AsmInstruction>> & compiled,
    AsmLabelHandler & handler
) const noexcept {
    throw "TODO";
}


void CustomType::markAsDeclared() noexcept {
    _isDeclared = true;
}

bool CustomType::isDeclared() const noexcept {
    return _isDeclared;
}

void CustomType::markAsCompleted() noexcept {
    _idCompleted = true;
}

bool CustomType::isCompleted() const noexcept {
    return _idCompleted;
}

std::optional<CustomType const *> CustomType::getParent() const noexcept {
    return parentType;
}	
