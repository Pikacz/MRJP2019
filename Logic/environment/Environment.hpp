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
#include <vector>
#include <string>

#include "types/Type.hpp"
#include "types/ArrayType.hpp"
#include "types/builtin/LatteBool.hpp"
#include "types/builtin/LatteInt.hpp"
#include "types/builtin/LatteString.hpp"
#include "types/builtin/LatteVoid.hpp"
#include "variables/Variable.hpp"

class Function;
class FunctionInitializer;

class Environment {
protected:
    Environment() noexcept;
    
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
    
    
    ArrayType const * getArrayOfType(Type const * type) noexcept;

    
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
    
private:
    std::vector<std::unique_ptr<const ArrayType>> arrays;
};

#endif /* Environment_hpp */
