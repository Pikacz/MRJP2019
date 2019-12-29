//
//  Logic.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include <iostream>
#include "Logic.hpp"
#include "LogicPriv.hpp"

void Logic::HelloWorld(const char * s)
{
    LogicPriv *theObj = new LogicPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void LogicPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

