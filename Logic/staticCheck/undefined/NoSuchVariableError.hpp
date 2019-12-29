//
//  NoSuchVariableError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef NoSuchVariableError_hpp
#define NoSuchVariableError_hpp

#include "../StaticCheckError.hpp"

class NoSuchVariableError final: public StaticCheckError {
public:
    NoSuchVariableError(
        size_t line, size_t column, std::string varName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string varName;
};

#endif /* NoSuchVariableError_hpp */
