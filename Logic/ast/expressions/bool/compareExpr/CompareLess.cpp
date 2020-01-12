//
//  CompareLess.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareLess.hpp"

#include "../../../../assembler/instructions/AsmJl.hpp"

using namespace std;

bool CompareLess::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<CompareLess const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


unique_ptr<const AsmInstruction> CompareLess::getJump(
    AsmLabel const * lblTrue
) const noexcept {
    return make_unique<AsmJl>(lblTrue);
}
