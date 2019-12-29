//
//  main.cpp
//  Latte
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include <iostream>
#include "Logic.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Logic l;
    Environment e;
    l.HelloWorld("alo elo 3 2 1");
    std::cout << "Hello, World!\n";
    return 0;
}
