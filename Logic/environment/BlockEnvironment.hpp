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


class BlockEnvironment: public Environment {
public:
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
    
    // MARK: types
    virtual Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: compilation
    virtual void compileVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept;
    
    virtual void cleanVariables(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept;

protected:
    std::map<std::string, std::unique_ptr<const Variable>> variables;
    
    const Environment * const parent;
    
};


#endif /* BlockEnvironment_hpp */
