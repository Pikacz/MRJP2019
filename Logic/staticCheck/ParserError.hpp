//
//  ParserError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ParserError_hpp
#define ParserError_hpp

#include <stdio.h>

#include <string>
#include <sstream>

class ParserError {
public:
    ParserError(std::string msg) noexcept;
    
    std::string what() const noexcept;
private:
    const std::string msg;
};

#endif /* ParserError_hpp */
