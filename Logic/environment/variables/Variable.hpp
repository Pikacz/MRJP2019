//
//  Variable.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include <stdio.h>

class Type;

class Variable {
public:
    Variable(Type const * type);
    
private:
    const Type * const type;
};

#endif /* Variable_hpp */
