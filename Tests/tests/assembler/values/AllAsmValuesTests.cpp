//
//  AllAsmValuesTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllAsmValuesTests.hpp"

#include "AsmRegisterTests.hpp"
#include "AsmIntConstantTests.hpp"
#include "AsmMemoryTests.hpp"

void runAllAsmValuesTests(std::string prefix) noexcept {
    AsmRegisterTests t1("AsmRegisterTests");
    t1.run(prefix);
    AsmIntConstantTests t2("AsmIntConstantTests");
    t2.run(prefix);
    AsmMemoryTests t3("AsmMemoryTests");
    t3.run(prefix);
}
