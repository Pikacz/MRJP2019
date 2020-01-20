//
//  TypeEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef TypeEnvironment_hpp
#define TypeEnvironment_hpp

#include "Environment.hpp"


class TypeEnvironment final: public Environment {
public:
    
    // MARK: string
    AsmLabel const * registerString(std::string str) const noexcept override;
private:
    TypeEnvironment const * parent;
    
    const Environment * const global;
};



#endif /* TypeEnvironment_hpp */
