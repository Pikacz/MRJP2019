//
//  CompareNotEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareNotEqual.hpp"
#include "../../../../assembler/instructions/AsmJne.hpp"

using namespace std;

bool CompareNotEqual::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareNotEqual const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareNotEqual::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJne>(lblTrue);
}
