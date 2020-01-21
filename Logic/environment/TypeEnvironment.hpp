//
//  TypeEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef TypeEnvironment_hpp
#define TypeEnvironment_hpp

#include "EnvWithFunctions.hpp"
#include <map>



class TypeEnvironment final: public EnvWithFunctions {
public:
    TypeEnvironment(Environment const * global) noexcept;
    
    // MARK: variables
    virtual Variable const * getVariableNamed(
        std::string name, bool expectingFunction, size_t line, size_t column
    ) const noexcept(false) override;
    
    virtual void declareVariable(
        std::string name, Type const * type, size_t line, size_t column
    ) noexcept(false);
    
    // MARK: functions
    virtual Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    virtual FuncVariable const * getConcatStrings() const noexcept override;
    virtual FuncVariable const * getEqualStrings() const noexcept override;
    virtual FuncVariable const * getNotEqualStrings() const noexcept override;
    
    virtual Function * declareFunction(
        FunctionInitializer initializer, size_t line, size_t column
    ) noexcept(false) override;
    
    // MARK: types
    virtual Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: string
    AsmLabel const * registerString(std::string str) const noexcept override;
    
    
    void setParent(TypeEnvironment const * parent) noexcept;
    
private:
    TypeEnvironment const * parent;
    
    const Environment * const global;
    
//    std::map<std::string, >
};



#endif /* TypeEnvironment_hpp */
