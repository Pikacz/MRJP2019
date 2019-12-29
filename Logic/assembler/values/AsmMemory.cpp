//
//  AsmMemory.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmMemory.hpp"

#include <cassert>

using namespace std;

AsmMemory::AsmMemory(
    int displacement,
    optional<shared_ptr<const AsmRegister>> base,
    optional<shared_ptr<const AsmRegister>> index,
    ScaleT scale
) noexcept: displacement(displacement), base(base), index(index), scale(scale) {
    
    if (index) {
        if ((*index)->getType() == AsmRegister::Type::rsp) {
            assert(false);
        }
    }
}


void AsmMemory::write(
    stringstream &ss, AssemblerValue::Size size
) const noexcept {
    ss << displacement;
    if (base || index) {
        ss << "(";
    }
    
    if (base) {
        (*base)->write(ss, size);
    }
    if (index) {
        ss << ",";
        (*index)->write(ss, size);
        ss << ",";
        ss << scale;
    }
    if (base || index) {
        ss << ")";
    }
}


bool AsmMemory::isEqualTo(AssemblerValue const * val) const noexcept {
    if (auto rhs = dynamic_cast<AsmMemory const *>(val)) {
        if (displacement != rhs->displacement) {
            return false;
        }
        if (base) {
            if (rhs->base) {
                if (!(*base)->isEqualTo((*rhs->base).get())) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            if (rhs->base) {
                return false;
            }
        }
        
        if (index) {
            if (rhs->index) {
                if (!(*index)->isEqualTo((*rhs->index).get())) {
                    return false;
                }
            } else {
                return false;
            }
            
            if (scale != rhs->scale) {
                return false;
            }
        } else {
            if (rhs->index) {
                return false;
            }
        }
        
        return true;
    }
    return false;
}
