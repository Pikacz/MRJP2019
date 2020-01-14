//
//  TopDefFactory.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef TopDefFactory_hpp
#define TopDefFactory_hpp

#include <string>
#include <memory>

#include "../environment/GlobalEnvironment.hpp"

class TopDefFactory final {
public:
    static std::unique_ptr<const GlobalEnvironment>
        createFrom(std::string code) noexcept(false);
};

#endif /* TopDefFactory_hpp */
