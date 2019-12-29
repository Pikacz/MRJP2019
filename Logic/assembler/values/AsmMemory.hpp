//
//  AsmMemory.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmMemory_hpp
#define AsmMemory_hpp

#include <memory>
#include <optional>

#include "AssemblerValue.hpp"
#include "registers/AsmRegister.hpp"

class AsmMemory final: public AssemblerValue {
public:
    enum ScaleT {
        one = 1,
        two = 2,
        four = 4,
        eight = 8
    };

    AsmMemory(
        int displacement,
        std::optional<std::shared_ptr<const AsmRegister>> base,
        std::optional<std::shared_ptr<const AsmRegister>> index,
        ScaleT scale
    ) noexcept;

    void write(
        std::stringstream &ss, AssemblerValue::Size size
    ) const noexcept override;

    bool isEqualTo(AssemblerValue const * val) const noexcept override;

private:
    const int displacement;
    const std::optional<std::shared_ptr<const AsmRegister>> base;
    const std::optional<std::shared_ptr<const AsmRegister>> index;
    const ScaleT scale;
};

#endif /* AsmMemory_hpp */
