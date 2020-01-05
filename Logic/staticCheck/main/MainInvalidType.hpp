//
//  MainInvalidType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MainInvalidType_hpp
#define MainInvalidType_hpp

#include "../StaticCheckError.hpp"

class MainInvalidType final: public StaticCheckError {
public:
    MainInvalidType(size_t line, size_t column) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
};


#endif /* MainInvalidType_hpp */
