//
//  VariableRedeclaration.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef VariableRedeclaration_hpp
#define VariableRedeclaration_hpp

#include "../StaticCheckError.hpp"

class VariableRedeclarationError final: public StaticCheckError {
public:
    VariableRedeclarationError(
        size_t line, size_t column, std::string varName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string varName;
};

#endif /* VariableRedeclaration_hpp */
