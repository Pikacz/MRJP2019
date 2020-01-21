//
//  InvalidMember.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef InvalidMember_hpp
#define InvalidMember_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class InvalidMember: public StaticCheckError {
public:
    InvalidMember(
        size_t line,
        size_t column,
        std::string type,
        std::string member
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string type;
    const std::string member;
};

#endif /* InvalidMember_hpp */
