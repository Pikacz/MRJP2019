//
//  antlr4_runtime.cpp
//  antlr4-runtime
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include <iostream>
#include "antlr4_runtime.hpp"
#include "antlr4_runtimePriv.hpp"

void antlr4_runtime::HelloWorld(const char * s)
{
    antlr4_runtimePriv *theObj = new antlr4_runtimePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void antlr4_runtimePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

