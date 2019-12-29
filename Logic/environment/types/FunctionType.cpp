//
//  FunctionType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 25/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "FunctionType.hpp"

#include <cassert>
#include <sstream>

using namespace std;


FunctionType::FunctionType(
    Type const * returnType,
    vector<Type const *> parameters
) noexcept: returnType(returnType), parameters(parameters) {}


bool FunctionType::isKindOf(Type const * type) const noexcept {
    if (auto rhs = dynamic_cast<FunctionType const *>(type)) {
        if (parameters.size() == rhs->parameters.size()) {
            for (size_t i = 0; i < parameters.size(); ++i) {
                if (!rhs->parameters[i]->isKindOf(parameters[i])) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}


string FunctionType::getName() const noexcept {
    stringstream ss;
    ss << returnType->getName() << "(";
    for (size_t i = 0; i < parameters.size(); ++i) {
        ss << parameters[i]->getName();
        if (i < parameters.size() - 1) {
            ss << ",";
        }
    }
    ss << ")";
    return ss.str();
}

size_t FunctionType::pointerSize() const noexcept {
    assert(false);
}


Type const * FunctionType::getReturnType() const noexcept {
    return returnType;
}


vector<Type const *> FunctionType::getParameters() const noexcept {
    return parameters;
}
