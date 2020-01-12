//
//  IfStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "IfStatement.hpp"

#include "../../staticCheck/types/InvalidType.hpp"
#include "../../assembler/instructions/AsmJne.hpp"
#include "../../assembler/instructions/AsmCmp.hpp"
#include "../../assembler/instructions/AsmJmp.hpp"
#include "../expressions/constants/BoolConstant.hpp"

using namespace std;

IfStatement::IfStatement(
    size_t line,
    size_t column,
    Environment const * env,
    std::unique_ptr<const Expression> _expr,
    std::unique_ptr<const Statement> _ifTrue,
    std::unique_ptr<const Statement> _ifFalse
) noexcept(false):
expr(move(_expr)), ifTrue(move(_ifTrue)), ifFalse(move(_ifFalse)),
Statement(line, column) {
    if (! this->expr.get()->isKindOf(env->getLatteBool())) {
        throw InvalidType(line, column, env->getLatteBool(), this->expr.get()->getType());
    }
}


bool IfStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<IfStatement const *>(node)) {
        return expr.get()->isEqualTo(nd->expr.get()) &&
            ifTrue.get()->isEqualTo(nd->ifTrue.get()) &&
            ifFalse.get()->isEqualTo(nd->ifFalse.get());
    }
    return false;
}


void IfStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    AsmRegistersHandler regHandler;
    expr.get()->compile(
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler,
        handler,
        AsmRegister::Type::rax
    );
    
    auto end = handler.getNextLbl();
    auto resultTrue = handler.getNextLbl();
    
    compiled.push_back(
        make_unique<AsmCmp>(
            AssemblerValue::Size::bit64,
            BoolConstant::getFalse(),
            make_unique<AsmRegister>(AsmRegister::Type::rax)
        )
    );
    compiled.push_back(
        make_unique<AsmJne>(resultTrue.get())
    );
    ifFalse.get()->compile(compiled, env, handler, exitLabel);
    compiled.push_back(
        make_unique<AsmJmp>(end.get())
    );
    compiled.push_back(
        move(resultTrue)
    );
    ifTrue.get()->compile(compiled, env, handler, exitLabel);
    compiled.push_back(move(end));
}


bool IfStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    return ifTrue.get()->isTerminatingWith(type)
        && ifFalse.get()->isTerminatingWith(type);
}
