//
//  BoolOrExpr.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "BoolOrExpr.hpp"

#include "../../constants/BoolConstant.hpp"
#include "../../../../assembler/instructions/AsmJmp.hpp"
#include "../../../../assembler/instructions/AsmJne.hpp"
#include "../../../../assembler/instructions/AsmCmp.hpp"
#include "../../../../assembler/instructions/AsmMov.hpp"

using namespace std;


void BoolOrExpr::compile(
    AssemblerValue::Size type,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    auto resultTrue = lblHandler.getNextLbl();
    auto resultFalse = lblHandler.getNextLbl();
    auto end = lblHandler.getNextLbl();
    
    
    lhs.get()->compile(type, compiled, env, handler, lblHandler, destination);
    compiled.push_back(make_unique<AsmCmp>(
        type,
        BoolConstant::getFalse(),
        make_unique<AsmRegister>(destination))
    );
    compiled.push_back(
        make_unique<AsmJne>(resultTrue.get())
    );
    // licz prawa strone
    rhs.get()->compile(type, compiled, env, handler, lblHandler, destination);
    compiled.push_back(make_unique<AsmCmp>(
        type,
        BoolConstant::getFalse(),
        make_unique<AsmRegister>(destination))
    );
    compiled.push_back(
        make_unique<AsmJne>(resultTrue.get())
    );
    // wynik
    compiled.push_back(move(resultFalse));
    compiled.push_back(
        make_unique<AsmMov>(
            type,
            BoolConstant::getFalse(),
            make_unique<AsmRegister>(destination)
        )
    );
    compiled.push_back(make_unique<AsmJmp>(end.get()));
    compiled.push_back(move(resultTrue));
    compiled.push_back(
        make_unique<AsmMov>(
            type,
            BoolConstant::getTrue(),
            make_unique<AsmRegister>(destination)
        )
    );
    compiled.push_back(move(end));
}


bool BoolOrExpr::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<BoolOrExpr const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}
