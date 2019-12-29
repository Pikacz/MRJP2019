//
//  StaticCheckError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef StaticCheckError_hpp
#define StaticCheckError_hpp

#include <stdio.h>

#include <string>
#include <sstream>

class StaticCheckError {
public:
    StaticCheckError(size_t line, size_t column) noexcept;
    
    std::string what() const noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept = 0;
private:
    const size_t line;
    const size_t column;
};


#endif /* StaticCheckError_hpp */
