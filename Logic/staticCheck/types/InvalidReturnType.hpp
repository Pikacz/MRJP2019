//
//  InvalidReturnType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef InvalidReturnType_hpp
#define InvalidReturnType_hpp

#include <stdio.h>
#include "InvalidType.hpp"

class InvalidReturnType final: public InvalidType {
public:
    using InvalidType::InvalidType;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
};


#endif /* InvalidReturnType_hpp */
