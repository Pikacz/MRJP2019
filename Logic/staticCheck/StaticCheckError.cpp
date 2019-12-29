//
//  StaticCheckError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "StaticCheckError.hpp"

using namespace std;


StaticCheckError::StaticCheckError(
    size_t line, size_t column
) noexcept: line(line), column(column) {}


string StaticCheckError::what() const noexcept {
    stringstream ss;
    ss << "Error in line " << line << ":" << column << "  ";
    description(ss);
    ss << endl;
    return ss.str();
}
