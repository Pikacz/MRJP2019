//
//  WhileStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "WhileStatement.hpp"

#include "../../staticCheck/types/InvalidType.hpp"
#include "../../assembler/instructions/AsmJne.hpp"
#include "../../assembler/instructions/AsmCmp.hpp"
#include "../../assembler/instructions/AsmJmp.hpp"
#include "../expressions/constants/BoolConstant.hpp"

using namespace std;

WhileStatement::WhileStatement(
    size_t line,
    size_t column,
    Environment const * env,
    std::unique_ptr<const Expression> _expr,
    std::unique_ptr<const Statement> _body
) noexcept(false):
expr(move(_expr)), body(move(_body)), Statement(line, column) {
    if (! this->expr.get()->isKindOf(env->getLatteBool())) {
        throw InvalidType(line, column, env->getLatteBool(), this->expr.get()->getType());
    }
}


bool WhileStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<WhileStatement const *>(node)) {
        return expr.get()->isEqualTo(nd->expr.get()) &&
            body.get()->isEqualTo(nd->body.get());
    }
    return false;
}

void WhileStatement::compile(
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    AsmRegistersHandler regHandler;

    auto end = handler.getNextLbl("while_end");
    auto compare = handler.getNextLbl("while_expr");
    auto body = handler.getNextLbl("while_body");
    
    
    compiled.push_back(
        make_unique<AsmJmp>(compare.get())
    );
    auto bodyLbl = body.get();
    
    compiled.push_back(move(body));
    this->body.get()->compile(compiled, env, handler, exitLabel);
    
    
    compiled.push_back(move(compare));
    expr.get()->compile(
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler,
        handler,
        AsmRegister::Type::rax
    );
    
    compiled.push_back(
        make_unique<AsmCmp>(
            AssemblerValue::Size::bit64,
            BoolConstant::getFalse(),
            make_unique<AsmRegister>(AsmRegister::Type::rax)
        )
    );
    compiled.push_back(
        make_unique<AsmJne>(bodyLbl)
    );
    compiled.push_back(move(end));
}


bool WhileStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    body.get()->isTerminatingWith(type);
    return expr.get()->isTerminating();
}


size_t WhileStatement::fakeVariablesCount() const noexcept {
    size_t result = expr->fakeVariablesCount();
    result = max(result, body->fakeVariablesCount());
    return result;
}
