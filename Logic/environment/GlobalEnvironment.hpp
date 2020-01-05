//
//  GlobalEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef GlobalEnvironment_hpp
#define GlobalEnvironment_hpp

#include <memory>
#include <map>
#include <string>
#include <list>

#include "Environment.hpp"
#include "types/builtin/LatteBool.hpp"
#include "types/builtin/LatteInt.hpp"
#include "types/builtin/LatteString.hpp"
#include "types/builtin/LatteVoid.hpp"
#include "../assembler/instructions/AsmInstruction.hpp"

class GlobalEnvironment final: public Environment {
public:
    GlobalEnvironment() noexcept;
    
    // MARK: functions
    Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    Function * declareFunction(
        FunctionInitializer initializer, size_t line, size_t column
    ) noexcept(false);
    
    
    // MARK: types
    Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    
    // MARK: compilation
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept(false);
private:
    std::map<std::string, std::unique_ptr<const Type>> types;
    
    std::map<std::string, std::unique_ptr<const Function>> functions;
    
    bool hasMain;
    
};

#endif /* GlobalEnvironment_hpp */
