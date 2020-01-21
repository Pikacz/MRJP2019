//
//  CantBeSubscripted.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CantBeSubscripted_hpp
#define CantBeSubscripted_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class CantBeSubscripted: public StaticCheckError {
public:
    CantBeSubscripted(
        size_t line,
        size_t column,
        std::string type
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string type;
};

#endif /* CantBeSubscripted_hpp */
