//
//  CyclicDependency.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CyclicDependency_hpp
#define CyclicDependency_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class CyclicDependency: public StaticCheckError {
public:
    CyclicDependency(
        size_t line,
        size_t column,
        std::string type,
        std::string parentType
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string type;
    const std::string parentType;
};

#endif /* CyclicDependency_hpp */
