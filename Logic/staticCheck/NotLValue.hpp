//
//  NotLValue.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef NotLValue_hpp
#define NotLValue_hpp

#include "StaticCheckError.hpp"
#include "../ast/expressions/Expression.hpp"


class NotLValue final: public StaticCheckError {
public:
    using StaticCheckError::StaticCheckError;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
};

#endif /* NotLValue_hpp */
