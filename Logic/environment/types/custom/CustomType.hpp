//
//  CustomType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CustomType_hpp
#define CustomType_hpp

#include <optional>
#include <map>

#include "../Type.hpp"
#include "../../TypeEnvironment.hpp"


class CustomType final: public Type {
public:
    CustomType(std::string name, Environment const * globalEnv) noexcept;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
    
    void setParent(
        Type const * parent, size_t line, size_t column
    ) noexcept(false);
    
    
    TypeEnvironment * getEnvironment() const noexcept;
    
    virtual void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmLabelHandler & handler
    ) const noexcept;
    
    virtual Variable const * getMemberNamed(std::string name, size_t line, size_t column) const noexcept(false) override;
    
    void markAsDeclared() noexcept;
    
    bool isDeclared() const noexcept;
    
    void markAsCompleted() noexcept;
    
    bool isCompleted() const noexcept;
    
    std::optional<CustomType const *> getParent() const noexcept;
    
protected:
    bool hasMemberNamed(std::string name) const noexcept;
    
    size_t getVarFooset() const noexcept;

private:
    
    const std::string name;
    std::optional<CustomType const *> parentType;
    
    const std::unique_ptr<TypeEnvironment> env;
    
    bool _isDeclared;
    bool _idCompleted;
};


#endif /* CustomType_hpp */
