//
//  CompareGreater.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareGreater.hpp"
#include "../../../../assembler/instructions/AsmJg.hpp"

using namespace std;

bool CompareGreater::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareGreater const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareGreater::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJg>(lblTrue);
}
