//
//  NoSuchFunctionError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef NoSuchFunctionError_hpp
#define NoSuchFunctionError_hpp

#include "../StaticCheckError.hpp"

class NoSuchFunctionError final: public StaticCheckError {
public:
    NoSuchFunctionError(
        size_t line, size_t column, std::string funcName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string funcName;
};

#endif /* NoSuchFunctionError_hpp */
