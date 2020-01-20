//
//  FunctionEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionEnvironment_hpp
#define FunctionEnvironment_hpp

#include <stdio.h>
#include "BlockEnvironment.hpp"

#include <map>
#include <vector>
#include <memory>
#include <string>



class FunctionEnvironment final: public BlockEnvironment {
public:
    FunctionEnvironment(
        Environment const * parent,
        FunctionInitializer initializer,
        bool isMain
    ) noexcept(false);
    
    // MARK: variables
    Variable const * getVariableNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    Variable const * getNextFakeVariable() const noexcept override;
    
    void declareFakeVariables(size_t count) noexcept;
    
    void releaseFakeVariable(
        Variable const * var,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept override;
    
    // MARK: compilation
    void initializeVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept override;
    
    void cleanVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept override;
    
    void compileVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler
    ) const noexcept;
    
protected:
    virtual size_t getSize() const noexcept override;
    
    virtual void setVariables(
        size_t firstAt
    ) const noexcept override;
    
private:
    void compileParameters(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    void declareParameterVariable(
        std::string name,
        Type const * type,
        size_t line,
        size_t column
    ) noexcept(false);
    
    std::vector<
        std::pair<std::string, std::unique_ptr<Variable>>
    > parameters;
    
    const bool isMain;
    
    mutable std::map<std::string, std::pair<Variable const *, bool>> fakeVars;
};


#endif /* FunctionEnvironment_hpp */
