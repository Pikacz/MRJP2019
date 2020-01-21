//
//  TypeRedeclaration.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef TypeRedeclaration_hpp
#define TypeRedeclaration_hpp

#include "../StaticCheckError.hpp"

class TypeRedeclaration final: public StaticCheckError {
public:
    TypeRedeclaration(
        size_t line, size_t column, std::string typeName
    ) noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
private:
    const std::string typeName;
};


#endif /* TypeRedeclaration_hpp */
