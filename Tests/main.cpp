//
//  main.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include <iostream>
#include "tests/AllTests.hpp"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>

using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


void foo() {
    std::ofstream o("tmp.s");
    o << "    .section    __TEXT,__text,regular,pure_instructions" << endl;
    o << "    .build_version macos, 10, 15    sdk_version 10, 15" << endl;
    o << "    .globl    _main                   ## -- Begin function main" << endl;
    o << "    .p2align    4, 0x90" << endl;
    o << "_main:                                  ## @main" << endl;
    o << "    .cfi_startproc" << endl;
    o << "## %bb.0:" << endl;
    o << "    pushq    %rbp" << endl;
    o << "    .cfi_def_cfa_offset 16" << endl;
    o << "    .cfi_offset %rbp, -16" << endl;
    o << "    movq    %rsp, %rbp" << endl;
    o << "    .cfi_def_cfa_register %rbp" << endl;
    o << "    movl    $0, -4(%rbp)" << endl;
    o << "    movl    $10, -8(%rbp)" << endl;
    o << "    movl    -8(%rbp), %eax" << endl;
    o << "    popq    %rbp" << endl;
    o << "    retq" << endl;
    o << "    .cfi_endproc" << endl;
    o << "                                        ## -- End function" << endl;
    o << "" << endl;
    o << ".subsections_via_symbols" << endl;

    o.close();
    
    system("clang++ tmp.s -o elo");
    int status = system("./elo > xx.txt");
    cout << WEXITSTATUS(status) << endl;;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    runAllTests("");
    return 0;
}
