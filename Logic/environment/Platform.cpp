//
//  Platform.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "Platform.hpp"


#if __APPLE__
bool isLinux() { return false; }
bool isOSx() { return true; }
#else
bool isLinux() { return true; }
bool isOSx() { return false; }
#endif
