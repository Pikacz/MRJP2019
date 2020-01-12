//
//  CompareLessEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareLessEqual.hpp"

#include "../../../../assembler/instructions/AsmJle.hpp"

using namespace std;

bool CompareLessEqual::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareLessEqual const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareLessEqual::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJle>(lblTrue);
}
