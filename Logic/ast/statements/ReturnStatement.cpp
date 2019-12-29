//
//  ReturnStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "ReturnStatement.hpp"
#include "../../staticCheck/types/InvalidReturnType.hpp"

using namespace std;

ReturnStatement::ReturnStatement(
    optional<unique_ptr<const Expression>> expr
) noexcept: expr(move(expr)), Statement() {
    
}


bool ReturnStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ReturnStatement const *>(node)) {
        if (expr != nullopt && nd->expr != nullopt) {
            return expr->get()->isEqualTo(nd->expr->get());
        } else {
            return expr == nullopt && nd->expr == nullopt;
        }
    }
    return false;
}

//
//bool ReturnStatement::isTerminatingWith(Type const * type) const noexcept(false) {
//    if (expr.has_value()) {
//        if (!expr->get()->isKindOf(type)) {
//            throw InvalidReturnType(
//        }
//        return expr->get()
//    }
//}
