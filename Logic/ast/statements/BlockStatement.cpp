//
//  BlockStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 06/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "BlockStatement.hpp"

#include "../../assembler/instructions/AsmJmp.hpp"
#include "../../assembler/instructions/AsmPop.hpp"
#include "../../assembler/instructions/AsmPush.hpp"

#include <cassert>

using namespace std;


BlockStatement::BlockStatement(
    size_t line,
    size_t column,
    Environment const * env
) noexcept: env(make_unique<BlockEnvironment>(env)), isCompleted(false), Statement(line, column) {
}


BlockEnvironment * BlockStatement::getEnvironment() const noexcept {
    assert(!isCompleted);
    return env.get();
}


bool BlockStatement::isTerminatingWith(Type const * type) const noexcept(false) {
    assert(isCompleted);
    bool finishes = false;
    
    for (size_t i = 0; i < statements.size(); ++i) {
        if (statements[i].get()->isTerminatingWith(type)) {
            finishes = true;
        }
    }
    return finishes;
}


void BlockStatement::completeWith(
    vector<unique_ptr<const Statement>> statements
) noexcept {
    assert(!isCompleted);
    isCompleted = true;
    this->statements = move(statements);
}


void BlockStatement::compile(
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    this->env.get()->initializeVariables(compiled);
    
    unique_ptr<const AsmLabel> newExitLbl = handler.getNextLbl("block_exit");
    unique_ptr<const AsmLabel> leaveLbl = handler.getNextLbl("block_leave");
    
    for (size_t i = 0; i < statements.size(); ++i) {
        statements[i].get()->compile(
            compiled, this->env.get(), handler, newExitLbl.get()
         );
    }
    unique_ptr<const AsmInstruction> leave = make_unique<AsmJmp>(leaveLbl.get());
    compiled.push_back(move(leave));
    
    compiled.push_back(move(newExitLbl));
    // rax jest ustawione i cenne
    AsmRegistersHandler regHandler1;
    
    for (size_t i = 0; i < 2; ++i) {
        compiled.push_back(
            make_unique<AsmPush>(
                AssemblerValue::Size::bit64,
                make_unique<AsmRegister>(AsmRegister::Type::rax)
            )
        );
    }
    this->env.get()->cleanVariables(compiled, regHandler1, handler);
    for (size_t i = 0; i < 2; ++i) {
        compiled.push_back(
            make_unique<AsmPop>(
                AssemblerValue::Size::bit64,
                make_unique<AsmRegister>(AsmRegister::Type::rax)
            )
        );
    }
    unique_ptr<const AsmInstruction> exit = make_unique<AsmJmp>(exitLabel);
    // opuszczam blok z powodu return
    compiled.push_back(move(exit));
    
    compiled.push_back(move(leaveLbl));
    // tutaj wszystkie rejestry są puste
    AsmRegistersHandler regHandler2;
    this->env.get()->cleanVariables(compiled, regHandler2, handler);
    
}


bool BlockStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<BlockStatement const *>(node)) {
        if (statements.size() == nd->statements.size()) {
            for (size_t i = 0; i < statements.size(); ++i) {
                if (!statements[i].get()->isEqualTo(nd->statements[i].get())) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}


size_t BlockStatement::fakeVariablesCount() const noexcept {
    size_t result = 0;
    for (auto & stmt: statements) {
        result = max(result, stmt->fakeVariablesCount());
    }
    return result;
}
