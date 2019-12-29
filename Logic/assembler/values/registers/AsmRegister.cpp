//
//  AsmRegister.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmRegister.hpp"
#include <string>

using namespace std;

AsmRegister::AsmRegister(
    Type type
): type(type), AssemblerValue() {}


bool AsmRegister::isEqualTo(AssemblerValue const * val) const noexcept {
    if (auto rhs = dynamic_cast<AsmRegister const *>(val)) {
        return type == rhs->type;
    }
    return false;
}

AsmRegister::Type AsmRegister::getType() const noexcept {
    return type;
}

bool AsmRegister::operator< (const AsmRegister& rhs) const {
    return type < rhs.type;
}

bool AsmRegister::operator== (const AsmRegister& rhs) const {
    return type == rhs.type;
}

inline static string get8BitName(AsmRegister::Type type) noexcept {
    switch (type) {
        case AsmRegister::rax:
            return "al";
        case AsmRegister::rbx:
            return "bl";
        case AsmRegister::rcx:
            return "cl";
        case AsmRegister::rdx:
            return "dl";
        case AsmRegister::rsi:
            return "sil";
        case AsmRegister::rdi:
            return "dil";
        case AsmRegister::rsp:
            return "spl";
        case AsmRegister::rbp:
            return "bpl";
        case AsmRegister::r8:
            return "r8b";
        case AsmRegister::r9:
            return "r9b";
        case AsmRegister::r10:
            return "r10b";
        case AsmRegister::r11:
            return "r11b";
        case AsmRegister::r12:
            return "r12b";
        case AsmRegister::r13:
            return "r13b";
        case AsmRegister::r14:
            return "r14b";
        case AsmRegister::r15:
            return "r15b";
    }
}

inline static string get16BitName(AsmRegister::Type type) noexcept {
    switch (type) {
        case AsmRegister::rax:
            return "ax";
        case AsmRegister::rbx:
            return "bx";
        case AsmRegister::rcx:
            return "cx";
        case AsmRegister::rdx:
            return "dx";
        case AsmRegister::rsi:
            return "si";
        case AsmRegister::rdi:
            return "di";
        case AsmRegister::rsp:
            return "sp";
        case AsmRegister::rbp:
            return "bp";
        case AsmRegister::r8:
            return "r8w";
        case AsmRegister::r9:
            return "r9w";
        case AsmRegister::r10:
            return "r10w";
        case AsmRegister::r11:
            return "r11w";
        case AsmRegister::r12:
            return "r12w";
        case AsmRegister::r13:
            return "r13w";
        case AsmRegister::r14:
            return "r14w";
        case AsmRegister::r15:
            return "r15w";
    }
}

inline static string get32BitName(AsmRegister::Type type) noexcept {
    switch (type) {
        case AsmRegister::rax:
            return "eax";
        case AsmRegister::rbx:
            return "ebx";
        case AsmRegister::rcx:
            return "ecx";
        case AsmRegister::rdx:
            return "edx";
        case AsmRegister::rsi:
            return "esi";
        case AsmRegister::rdi:
            return "edi";
        case AsmRegister::rsp:
            return "esp";
        case AsmRegister::rbp:
            return "ebp";
        case AsmRegister::r8:
            return "r8d";
        case AsmRegister::r9:
            return "r9d";
        case AsmRegister::r10:
            return "r10d";
        case AsmRegister::r11:
            return "r11d";
        case AsmRegister::r12:
            return "r12d";
        case AsmRegister::r13:
            return "r13d";
        case AsmRegister::r14:
            return "r14d";
        case AsmRegister::r15:
            return "r15d";
    }
}


inline static string get64BitName(AsmRegister::Type type) noexcept {
    switch (type) {
        case AsmRegister::rax:
            return "rax";
        case AsmRegister::rbx:
            return "rbx";
        case AsmRegister::rcx:
            return "rcx";
        case AsmRegister::rdx:
            return "rdx";
        case AsmRegister::rsi:
            return "rsi";
        case AsmRegister::rdi:
            return "rdi";
        case AsmRegister::rsp:
            return "rsp";
        case AsmRegister::rbp:
            return "rbp";
        case AsmRegister::r8:
            return "r8";
        case AsmRegister::r9:
            return "r9";
        case AsmRegister::r10:
            return "r10";
        case AsmRegister::r11:
            return "r11";
        case AsmRegister::r12:
            return "r12";
        case AsmRegister::r13:
            return "r13";
        case AsmRegister::r14:
            return "r14";
        case AsmRegister::r15:
            return "r15";
    }
}


void AsmRegister::write(
    stringstream & ss, AssemblerValue::Size size
) const noexcept {
    ss << "%";
    switch (size) {
        case AssemblerValue::Size::bit8:
            ss << get8BitName(type);
            break;
        case AssemblerValue::Size::bit16:
            ss << get16BitName(type);
            break;
        case AssemblerValue::Size::bit32:
            ss << get32BitName(type);
            break;
        case AssemblerValue::Size::bit64:
            ss << get64BitName(type);
            break;
    }
}
