//
//  FunctionInitializer.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "FunctionInitializer.hpp"

using namespace std;

static shared_ptr<const FunctionType> getFunctionType(
    Type const * returnType,
    vector<FunctionInitializer::Parameter> parameters
) {
    vector<Type const *> params;
    for (auto p: parameters) {
        params.push_back(p.type);
    }
    return make_shared<const FunctionType>(returnType, params);
}


FunctionInitializer::FunctionInitializer(
    Type const * returnType,
    string name,
    vector<Parameter> parameters
) noexcept:
    type(getFunctionType(returnType, parameters)),
    name(name), parameters(parameters) {}


string FunctionInitializer::getName() const noexcept {
    return name;
}

shared_ptr<const FunctionType> FunctionInitializer::getType() const noexcept {
    return type;
}


vector<FunctionInitializer::Parameter> FunctionInitializer::getParameters() const noexcept {
    return parameters;
}
