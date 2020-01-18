//
//  AsmRegister.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmRegister_hpp
#define AsmRegister_hpp

#include <stdio.h>

#include "../AssemblerValue.hpp"

class AsmRegister final: public AssemblerValue {
public:
    enum Type {
        rax,
        rbx,
        rcx,
        rdx,
        rsi,
        rdi,
        rsp,
        rbp,
        rip,
        r8,
        r9,
        r10,
        r11,
        r12,
        r13,
        r14,
        r15
    };
    
    AsmRegister(Type type, AssemblerValue::Size size = AssemblerValue::Size::bit64);
    
    void write(
        std::stringstream & ss, AssemblerValue::Size size
    ) const noexcept override;
    
    bool isEqualTo(AssemblerValue const * val) const noexcept override;
    
    Type getType() const noexcept;
    
    bool operator< (const AsmRegister& rhs) const;
    
    bool operator== (const AsmRegister& rhs) const;
    
    
private:
    const Type type;
    
    const AssemblerValue::Size size;
};

#endif /* AsmRegister_hpp */
