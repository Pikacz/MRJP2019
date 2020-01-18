//
//  WholeProgramTestCaseUnit.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef WholeProgramTestCaseUnit_hpp
#define WholeProgramTestCaseUnit_hpp

#include "Logic.hpp"
#include "../../../testCase/TestUnit.hpp"


class WholeProgramTestCaseUnit: public TestUnit {
public:
    using TestUnit::TestUnit;

    
    void run() noexcept override;
protected:
    
    virtual void fillCode(std::ostream & ss) const noexcept = 0;
    
    virtual void fillInput(std::ostream & ss) const noexcept;
    virtual void fillOutput(std::ostream & ss) const noexcept;
    
    virtual int expectedExitCode() const noexcept;
    
};

#endif /* WholeProgramTestCaseUnit_hpp */
