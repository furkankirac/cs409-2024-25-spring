// Brief intro. to C++ basics.

// C++: a VALUE SEMANTIC language.
//  we work with THE VALUE. we can get references to the values as well.
// Java/Python/Javascript/C#...:
//   everything is allocated in the heap memory (some exceptions of course)
//   everything is accessed via a reference (REFERENCE SEMANTIC language)

// variables and functions and scope
//   primitive types
//   local, global, static variables
//   free, member, static functions
//   function return types

// primitive types: char, int, bool, double, float, ... (because CPU knows about them in its native language)

// reflection
//   auto, sizeof, sizeof..., typeid (RTTI), decltype, ...
//   reflexpr (C++23) -->> introduce us Real Reflection in C++,
//      provide us with new core-features called MetaClasses (by Herb Sutter)
// almost always auto - aaa rule: move type to the right

// OOP: struct, class, ctor/dtor, inheritance
// this ptr, static functions
// functions vs function parameters
// methods vs objects

// --- OOP basics
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (not covered in CS321)
// inheritance (not covered in CS321)

// --- Functional Programming Basics
// function / operator overloading

#include <iostream>
// #include <stdio.h>

// global variable
int a;

namespace my_namespace {
    int a;
}

using namespace std;

int main(int argc, char* argv[])
{
    int a;
    a = 5;
    ::a = 6;
    my_namespace::a = 7;

    // int, char, short int, long int, float, double, long double
    // short -> short int
    // long -> long int

    cout << sizeof(long double) << endl; // for my arch. it's 8 bytes
    cout << sizeof(double) << endl; // for my arch. it's 8 bytes
    cout << sizeof(long long int) << endl; // for my arch. it's 8 bytes
    cout << sizeof(long int) << endl; // for my arch. it's 8 bytes again
    cout << sizeof(int) << endl; // for my arch. it's 4 bytes
    cout << sizeof(short) << endl; // for my arch. it's 2 bytes
    cout << sizeof(char) << endl; // for my arch. it's 1 byte


    return 0;
}
