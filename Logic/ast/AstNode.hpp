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
    AstNode(size_t line, size_t column) noexcept;
    
    virtual ~AstNode();
    
    virtual bool isEqualTo(AstNode const * node) const noexcept = 0;
    
    size_t getLine() const noexcept;
        
    size_t getColumn() const noexcept;
private:
    const size_t line, column;
};

#endif /* AstNode_hpp */
