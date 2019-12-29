//
//  AssemblerValue.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AssemblerValue_hpp
#define AssemblerValue_hpp

#include <string>
#include <sstream>

class AssemblerValue {
public:
    enum Size {
        bit8,
        bit16,
        bit32,
        bit64
    };
    
    virtual ~AssemblerValue();
    
    virtual void write(
        std::stringstream & ss, Size size
    ) const noexcept = 0;
    
    virtual bool isEqualTo(AssemblerValue const * val) const noexcept = 0;
};


#endif /* AssemblerValue_hpp */
