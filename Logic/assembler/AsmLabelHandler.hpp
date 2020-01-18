//
//  AsmLabelHandler.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmLabelHandler_hpp
#define AsmLabelHandler_hpp

#include <string>
#include <memory>

#include "instructions/AsmLabel.hpp"

class AsmLabelHandler final {
public:
    AsmLabelHandler() noexcept;
    
    
    std::unique_ptr<const AsmLabel> getNextLbl(std::string info = "") noexcept;
private:
    size_t counter;
};

#endif /* AsmLabelHandler_hpp */
