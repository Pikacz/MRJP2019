//
//  TestUnit.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "TestUnit.hpp"

#include <cstdio>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

TestUnit::TestUnit(string name) noexcept: name(name) {}


void TestUnit::assertTrue(bool expr) {
    if (!expr) {
        throw 1;
    }
}


void TestUnit::assertFalse(bool expr) {
    if (expr) {
        throw 1;
    }
}


string TestUnit::getName() const noexcept {
    return name;
}


void TestUnit::createLatteLib() noexcept {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;
    
    ofstream headerFile("latte_lib.hpp");
    headerFile << "void printInt(long long int l);" << endl;
    headerFile << "void printString(void *);" << endl;
    headerFile << "void error();" << endl;
    headerFile << "long long int readInt();" << endl;
    headerFile << "void * readString();" << endl;
    headerFile << "void * concatStrings(void * s1, void * s2);" << endl;
    headerFile << "void deleteString(char * s);" << endl;
    headerFile << "void checkDelete();" << endl;
    headerFile << "void * getMemory(long long int size);" << endl;
    headerFile << "void freeMemory(void * mem);" << endl;
    headerFile << "void * wrapDestructable(void * ptr, long long int isString);" << endl;
    headerFile << "void * wrapUndestructable(void * ptr, long long int isString);" << endl;
    headerFile << "void * getValue(void * ptr);" << endl;
    headerFile << "void incCounter(void * ptr);" << endl;
    headerFile << "void decCounter(void * ptr);" << endl;
    headerFile << "" << endl;
    headerFile.close();
    
    ofstream codeFile("latte_lib.cpp");
    codeFile << "#include \"latte_lib.hpp\"" << endl;
    codeFile << "" << endl;
    codeFile << "#include <iostream>" << endl;
    codeFile << "#include <string>" << endl;
    codeFile << "#include <cstring>" << endl;
    codeFile << "#include <cassert>" << endl;
    codeFile << "#include <cstdlib>" << endl;
    codeFile << "#include <sstream>" << endl;
    codeFile << "#include <cstdio>" << endl;
    codeFile << "#include <cstring>" << endl;
    codeFile << "" << endl;
    codeFile << "using namespace std;" << endl;
    codeFile << "" << endl;
    codeFile << "static int string_count;" << endl;
    codeFile << "static int mem_count;" << endl;
    codeFile << "" << endl;
    codeFile << "void init_mem_count() {" << endl;
    codeFile << "    static bool initialized = false;" << endl;
    codeFile << "    if (initialized) return;" << endl;
    codeFile << "    initialized = true;" << endl;
    codeFile << "    string_count = 0;" << endl;
    codeFile << "    mem_count = 0;" << endl;
    codeFile << "    initialized = true;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void printInt(long long int i) {" << endl;
    codeFile << "    cout << i << endl;" << endl;
    codeFile << "    cout.flush();" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void printString(void * ss) {" << endl;
    codeFile << "    char* s = (char *) getValue(ss);" << endl;
    codeFile << "    cout << s << endl;" << endl;
    codeFile << "    cout.flush();" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void error() {" << endl;
    codeFile << "    assert(false);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "long long int readInt() {" << endl;
    codeFile << "    long long int val;" << endl;
    codeFile << "    cin >> val;" << endl;
    codeFile << "    return val;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void * readString() {" << endl;
    codeFile << "    string str;" << endl;
    codeFile << "    cin >> str;" << endl;
    codeFile << "    char * cstr = new char [str.length()+1];" << endl;
    codeFile << "    strcpy(cstr, str.c_str());" << endl;
    codeFile << "    init_mem_count();" << endl;
    codeFile << "    string_count++;" << endl;
    codeFile << "    return wrapDestructable(cstr, true);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "" << endl;
    codeFile << "void * concatStrings(void * ss1, void * ss2) {" << endl;
    codeFile << "    init_mem_count();" << endl;
    codeFile << "    stringstream ss;" << endl;
    codeFile << "    char* s1 = (char *) getValue(ss1);" << endl;
    codeFile << "    char* s2 = (char *) getValue(ss2);" << endl;
    codeFile << "    ss << s1 << s2;" << endl;
    codeFile << "    string  str = ss.str();" << endl;
    codeFile << "    char * cstr = new char [str.length()+1];" << endl;
    codeFile << "    strcpy(cstr, str.c_str());" << endl;
    codeFile << "    string_count++;" << endl;
    codeFile << "    return wrapDestructable(cstr, true);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "long long int stringsEqual(void * ss1, void * ss2) {" << endl;
    codeFile << "    char* s1 = (char *) getValue(ss1);" << endl;
    codeFile << "    char* s2 = (char *) getValue(ss2);" << endl;
    codeFile << "    if (strcmp( s1, s2 ) == 0) {" << endl;
    codeFile << "        return 1;" << endl;
    codeFile << "    } else {" << endl;
    codeFile << "        return 0;" << endl;
    codeFile << "    }" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "long long int stringsNotEqual(void * ss1, void * ss2) {" << endl;
    codeFile << "    char* s1 = (char *) getValue(ss1);" << endl;
    codeFile << "    char* s2 = (char *) getValue(ss2);" << endl;
    codeFile << "    if (strcmp( s1, s2 ) == 0) {" << endl;
    codeFile << "        return 0;" << endl;
    codeFile << "    } else {" << endl;
    codeFile << "        return 1;" << endl;
    codeFile << "    }" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void deleteString(char * s) {" << endl;
    codeFile << "    assert(string_count > 0);" << endl;
    codeFile << "    delete s;" << endl;
    codeFile << "    string_count--;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void checkDelete() {" << endl;
    codeFile << "    if (string_count != 0) {" << endl;
    codeFile << "        cout << \"nieusunieteNapisy: \" << string_count << endl;" << endl;
    codeFile << "    }" << endl;
    codeFile << "    assert(string_count == 0);" << endl;
    codeFile << "    assert(mem_count == 0);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void * getMemory(long long int size) {" << endl;
    codeFile << "    mem_count++;" << endl;
    codeFile << "    return malloc(size);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void freeMemory(void * mem) {" << endl;
    codeFile << "    assert(mem_count > 0);" << endl;
    codeFile << "    mem_count--;" << endl;
    codeFile << "    free(mem);" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "struct LattePointer {" << endl;
    codeFile << "    size_t counter;" << endl;
    codeFile << "    bool desctructable;" << endl;
    codeFile << "    bool isString;" << endl;
    codeFile << "    void * value;" << endl;
    codeFile << "};" << endl;
    codeFile << "" << endl;
    codeFile << "void * wrapDestructable(void * ptr, long long int isString) {" << endl;
    codeFile << "    LattePointer * obj = new LattePointer();" << endl;
    codeFile << "    obj->counter = 1;" << endl;
    codeFile << "    obj->desctructable = true;" << endl;
    codeFile << "    obj->isString = isString != 0;" << endl;
    codeFile << "    obj->value = ptr;" << endl;
    codeFile << "    return obj;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void * wrapUndestructable(void * ptr, long long int isString) {" << endl;
    codeFile << "    LattePointer * obj = new LattePointer();" << endl;
    codeFile << "    obj->counter = 1;" << endl;
    codeFile << "    obj->desctructable = false;" << endl;
    codeFile << "    obj->isString = isString != 0;" << endl;
    codeFile << "    obj->value = ptr;" << endl;
    codeFile << "    return obj;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void * getValue(void * ptr) {" << endl;
    codeFile << "    LattePointer * obj = (LattePointer *) ptr;" << endl;
    codeFile << "    return obj->value;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void incCounter(void * ptr) {" << endl;
    codeFile << "    LattePointer * obj = (LattePointer *) ptr;" << endl;
    codeFile << "    obj->counter++;" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "void decCounter(void * ptr) {" << endl;
    codeFile << "    LattePointer * obj = (LattePointer *) ptr;" << endl;
    codeFile << "    obj->counter--;" << endl;
    codeFile << "    if (obj->counter == 0) {" << endl;
    codeFile << "        if (obj->desctructable) {" << endl;
    codeFile << "            if (obj->isString) {" << endl;
    codeFile << "                deleteString((char *) obj->value);" << endl;
    codeFile << "            } else {" << endl;
    codeFile << "                freeMemory(obj->value);" << endl;
    codeFile << "            }" << endl;
    codeFile << "        }" << endl;
    codeFile << "        delete obj;" << endl;
    codeFile << "    }" << endl;
    codeFile << "}" << endl;
    codeFile << "" << endl;
    codeFile << "" << endl;
    codeFile << "" << endl;
    
    
    codeFile.close();
    
    
    
    system("clang++  -O3 latte_lib.hpp latte_lib.cpp -c");
}
