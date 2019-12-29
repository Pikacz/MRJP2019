//
//  FunctionRedeclarationError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionRedeclarationError_hpp
#define FunctionRedeclarationError_hpp

#include "../StaticCheckError.hpp"

class FunctionRedeclarationError final: public StaticCheckError {
public:
    FunctionRedeclarationError(
        size_t line, size_t column, std::string funcName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string funcName;
};


#endif /* FunctionRedeclarationError_hpp */
