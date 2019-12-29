//
//  NoSuchTypeError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef NoSuchTypeError_hpp
#define NoSuchTypeError_hpp

#include "../StaticCheckError.hpp"

class NoSuchTypeError final: public StaticCheckError {
public:
    NoSuchTypeError(
        size_t line, size_t column, std::string typeName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string typeName;
};

#endif /* NoSuchTypeError_hpp */
