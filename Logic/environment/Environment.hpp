//
//  Environment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <memory>
#include <map>
#include <string>

#include "types/Type.hpp"
#include "types/builtin/LatteBool.hpp"
#include "types/builtin/LatteInt.hpp"
#include "types/builtin/LatteString.hpp"
#include "types/builtin/LatteVoid.hpp"
#include "variables/Variable.hpp"
#include "function/Function.hpp"


class Environment {
protected:
    Environment();
    
public:
    // MARK: variables
    virtual Variable const * getVariableNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false);
    
    
    // MARK: functions
    virtual Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false);
    
    
    // MARK: types
    virtual Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false);
    
    LatteBool const * getLatteBool() const noexcept;
    
    LatteInt const * getLatteInt() const noexcept;
    
    LatteString const * getLatteString() const noexcept;
    
    LatteVoid const * getLatteVoid() const noexcept;
protected:
    // MARK: map keys
    static std::string keyForVariableNamed(std::string name) noexcept;

    static std::string keyForFunctionNamed(std::string name) noexcept;

    static std::string keyForTypeNamed(std::string name) noexcept;
    
    static std::string boolName() noexcept;
    static std::string intName() noexcept;
    static std::string stringName() noexcept;
    static std::string voidName() noexcept;
};

#endif /* Environment_hpp */
