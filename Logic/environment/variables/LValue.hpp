//
//  LValue.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef LValue_hpp
#define LValue_hpp

#include <memory>
#include <list>


#include "../../assembler/values/registers/AsmRegister.hpp"
#include "../../assembler/instructions/AsmInstruction.hpp"
#include "../../assembler/AsmRegistersHandler.hpp"


class Type;
class Environment;

class LValue {
public:
    virtual ~LValue();
    
    virtual void saveValueFrom(
        AsmRegister::Type source,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    
    virtual void loadValueInto(
        AsmRegister::Type destination,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    virtual std::unique_ptr<const AssemblerValue> getAddress(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept = 0;
    
    virtual Type const * getType() const noexcept = 0;
    
    virtual bool isEqualTo(LValue const * node) const noexcept = 0;
};

#endif /* LValue_hpp */
