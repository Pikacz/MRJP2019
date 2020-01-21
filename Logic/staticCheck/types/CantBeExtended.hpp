//
//  CantBeExtended.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CantBeExtended_hpp
#define CantBeExtended_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class CantBeExtended: public StaticCheckError {
public:
    CantBeExtended(
        size_t line,
        size_t column,
        std::string type
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string type;
};

#endif /* CantBeExtended_hpp */
