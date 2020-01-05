//
//  ExpectedReturn.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExpectedReturn_hpp
#define ExpectedReturn_hpp

#include "../StaticCheckError.hpp"

class ExpectedReturn final: public StaticCheckError {
public:
    ExpectedReturn(
        size_t line, size_t column,
        std::string functionName, std::string typeName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string functionName;
    const std::string typeName;
};

#endif /* ExpectedReturn_hpp */
