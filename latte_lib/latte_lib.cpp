#include "latte_lib.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

static int string_count;
static int mem_count;

void init_mem_count() {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;
    string_count = 0;
    mem_count = 0;
    initialized = true;
}

void printInt(long long int i) {
    cout << i << endl;
    cout.flush();
}

void printString(void * ss) {
    char* s = (char *) getValue(ss);
    cout << s << endl;
    cout.flush();
}

void error() {
    assert(false);
}

long long int readInt() {
    long long int val;
    cin >> val;
    return val;
}

void * readString() {
    string str;
    cin >> str;
    char * cstr = new char [str.length()+1];
    strcpy(cstr, str.c_str());
    init_mem_count();
    string_count++;
    return wrapDestructable(cstr, true);
}


void * concatStrings(void * ss1, void * ss2) {
    init_mem_count();
    stringstream ss;
    char* s1 = (char *) getValue(ss1);
    char* s2 = (char *) getValue(ss2);
    ss << s1 << s2;
    string  str = ss.str();
    char * cstr = new char [str.length()+1];
    strcpy(cstr, str.c_str());
    string_count++;
    return wrapDestructable(cstr, true);
}

long long int stringsEqual(void * ss1, void * ss2) {
    char* s1 = (char *) getValue(ss1);
    char* s2 = (char *) getValue(ss2);
    if (strcmp( s1, s2 ) == 0) {
        return 1;
    } else {
        return 0;
    }
}

long long int stringsNotEqual(void * ss1, void * ss2) {
    char* s1 = (char *) getValue(ss1);
    char* s2 = (char *) getValue(ss2);
    if (strcmp( s1, s2 ) == 0) {
        return 0;
    } else {
        return 1;
    }
}

void deleteString(char * s) {
    assert(string_count > 0);
    delete s;
    string_count--;
}

void checkDelete() {
    if (string_count != 0) {
        cout << "nieusunieteNapisy: " << string_count << endl;
    }
    assert(string_count == 0);
    assert(mem_count == 0);
}

void * getMemory(long long int size) {
    mem_count++;
    return malloc(size);
}

void freeMemory(void * mem) {
    assert(mem_count > 0);
    mem_count--;
    free(mem);
}

struct LattePointer {
    size_t counter;
    bool desctructable;
    bool isString;
    void * value;
};

void * wrapDestructable(void * ptr, long long int isString) {
    LattePointer * obj = new LattePointer();
    obj->counter = 1;
    obj->desctructable = true;
    obj->isString = isString != 0;
    obj->value = ptr;
    return obj;
}

void * wrapUndestructable(void * ptr, long long int isString) {
    LattePointer * obj = new LattePointer();
    obj->counter = 1;
    obj->desctructable = false;
    obj->isString = isString != 0;
    obj->value = ptr;
    return obj;
}

void * getValue(void * ptr) {
    LattePointer * obj = (LattePointer *) ptr;
    return obj->value;
}

void incCounter(void * ptr) {
    LattePointer * obj = (LattePointer *) ptr;
    obj->counter++;
}

void decCounter(void * ptr) {
    LattePointer * obj = (LattePointer *) ptr;
    obj->counter--;
    if (obj->counter == 0) {
        if (obj->desctructable) {
            if (obj->isString) {
                deleteString((char *) obj->value);
            } else {
                freeMemory(obj->value);
            }
        }
        delete obj;
    }
}



