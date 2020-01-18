//
//  BlockEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef BlockEnvironment_hpp
#define BlockEnvironment_hpp

#include "Environment.hpp"

#include <map>
#include <vector>
#include <memory>
#include <string>


class FunctionEnvironment;

class BlockEnvironment: public Environment {
public:
    friend class FunctionEnvironment;
    
    BlockEnvironment(
        Environment const * parent
    ) noexcept;
    
    // MARK: variables
    virtual void declareVariable(
        std::string name, Type const * type, size_t line, size_t column
    ) noexcept(false);
    
    virtual Variable const * getVariableNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: functions
    virtual Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    virtual void markFuncCall(size_t parameters_count) noexcept override;
    
    FuncVariable const * getConcatStrings() const noexcept override;
    
    // MARK: types
    virtual Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: string
    AsmLabel const * registerString(std::string str) const noexcept override;
    
    // MARK: compilation
    virtual void initializeVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept;
    
    virtual void cleanVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept;
protected:
    
    
    size_t func_params;
    
    virtual size_t getFuncParams() const noexcept;
    
    virtual size_t getSize() const noexcept;
    
    
    virtual void setVariables(
        size_t firstAt
    ) const noexcept;
    
    std::map<std::string, std::unique_ptr<Variable>> variables;
    
    const Environment * const parent;
    
    void addChild(BlockEnvironment const * child) const noexcept;
    mutable std::vector<BlockEnvironment const *> children;
private:
    
    
};


#endif /* BlockEnvironment_hpp */
