//
//  CompareEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareEqual.hpp"
#include "../../../../assembler/instructions/AsmJe.hpp"

using namespace std;

bool CompareEqual::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareEqual const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareEqual::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJe>(lblTrue);
}
