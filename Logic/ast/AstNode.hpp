//
//  AstNode.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AstNode_hpp
#define AstNode_hpp

#include <stdio.h>

class AstNode {
public:
    virtual ~AstNode();
    
    virtual bool isEqualTo(AstNode const * node) const noexcept = 0;
};

#endif /* AstNode_hpp */
