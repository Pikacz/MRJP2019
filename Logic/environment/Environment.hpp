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
#include "../assembler/instructions/AsmLabel.hpp"
#include "../assembler/values/AsmData.hpp"
#include "../assembler/AsmLabelHandler.hpp"
#include "../assembler/AsmRegistersHandler.hpp"

class Function;
class Variable;
class FunctionInitializer;
class FuncVariable;

class Environment {
protected:
    Environment() noexcept;
    
public:
    // MARK: variables
    virtual Variable const * getVariableNamed(
        std::string name, bool expectingFunction, size_t line, size_t column
    ) const noexcept(false);
    
    virtual Variable const * getNextFakeVariable() const noexcept;
    
    virtual void releaseFakeVariable(
        Variable const * var,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept;
    
    
    // MARK: functions
    virtual Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false);
    
    virtual void markFuncCall(size_t parameters_count) noexcept;
    
    virtual FuncVariable const * getConcatStrings() const noexcept;
    
    // MARK: types
    virtual Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false);
    
    // MARK: string
    virtual AsmLabel const * registerString(std::string str) const noexcept = 0;
    
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
