//
//  GlobalEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef GlobalEnvironment_hpp
#define GlobalEnvironment_hpp

#include <memory>
#include <map>
#include <string>
#include <list>

#include "EnvWithFunctions.hpp"
#include "types/builtin/LatteBool.hpp"
#include "types/builtin/LatteInt.hpp"
#include "types/builtin/LatteString.hpp"
#include "types/builtin/LatteVoid.hpp"
#include "types/custom/CustomType.hpp"
#include "function/builtin/ConcatString.hpp"
#include "../assembler/instructions/AsmInstruction.hpp"


class GlobalEnvironment final: public EnvWithFunctions {
public:
    GlobalEnvironment() noexcept;
    
    // MARK: variables
    virtual Variable const * getVariableNamed(
        std::string name, bool expectingFunction, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: functions
    Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    Function * declareFunction(
        FunctionInitializer initializer, size_t line, size_t column
    ) noexcept(false) override;
    
    FuncVariable const * getConcatStrings() const noexcept override;
    virtual FuncVariable const * getEqualStrings() const noexcept override;
    virtual FuncVariable const * getNotEqualStrings() const noexcept override;
    
    
    // MARK: types
    Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    
    CustomType * declareType(
        std::string name, size_t line, size_t column
    ) noexcept(false);
    
    
    // MARK: string
    AsmLabel const * registerString(std::string str) const noexcept override;
    
    // MARK: compilation
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept(false);
private:
    std::map<std::string, std::unique_ptr<const Type>> types;
    
    std::map<std::string, std::unique_ptr<const Function>> functions;
    
    std::map<std::string, std::unique_ptr<Variable>> variables;
    
    bool hasMain;
    
    FuncVariable const * _concatString;
    FuncVariable const * _notEqualString;
    FuncVariable const * _equalString;
    
    mutable std::vector<std::unique_ptr<const AsmLabel>> stringLabels;
    mutable std::map<std::string, std::string> strings;
};

#endif /* GlobalEnvironment_hpp */
