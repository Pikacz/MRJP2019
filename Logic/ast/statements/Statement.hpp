//
//  Statement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Statement_hpp
#define Statement_hpp

#include <stdio.h>
#include "../AstNode.hpp"
#include "../../environment/types/Type.hpp"

class Statement: public AstNode {
public:
    using AstNode::AstNode;
    
    virtual bool isTerminatingWith(Type const * type) const noexcept(false) = 0;
};

#endif /* Statement_hpp */
