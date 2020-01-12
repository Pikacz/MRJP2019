//
//  CompareGreaterEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareGreaterEqual.hpp"
#include "../../../../assembler/instructions/AsmJge.hpp"

using namespace std;

bool CompareGreaterEqual::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareGreaterEqual const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareGreaterEqual::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJge>(lblTrue);
}
