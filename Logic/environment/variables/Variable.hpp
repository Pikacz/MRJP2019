//
//  Variable.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include <stdio.h>

#include <optional>

#include "../Environment.hpp"
#include "../../assembler/values/AsmMemory.hpp"
#include "../../assembler/AsmRegistersHandler.hpp"


class Type;
class Environment;

class Variable {
public:
    Variable(Type const * type, Environment const * env);
    
    std::unique_ptr<const AssemblerValue> getAddress(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    virtual Type const * getType() const noexcept;
    
    virtual bool isEqualTo(Variable const * node) const noexcept;
    
    void setMemory(std::unique_ptr<const AsmMemory> memory) noexcept;
    
    virtual bool isMemberVar() const noexcept;
private:
    const Type * const type;
    
    std::optional<std::unique_ptr<const AsmMemory>> location;
};

#endif /* Variable_hpp */
