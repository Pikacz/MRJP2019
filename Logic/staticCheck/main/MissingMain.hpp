//
//  MissingMain.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MissingMain_hpp
#define MissingMain_hpp

#include "../StaticCheckError.hpp"

class MissingMain: public StaticCheckError {
public:
    MissingMain() noexcept;
protected:
    virtual void description(std::stringstream & ss) const noexcept override;
};


#endif /* MissingMain_hpp */
