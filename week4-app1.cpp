// constness: east/west const, pointers and const
// C++ reference vs pointers

// l-value binding, r-value binding
// new, new[], delete, delete[]

// copy c-tor, copy assignment
// move-ctor, move-assignment (delayed)

// Generics / Templates:
// function, class, variable, type templates

// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    auto a = 10;
    cout << sizeof(a) << endl; // 4 bytes for my architecture
    cout << sizeof(long int) << endl; // 8 bytes for my architecture
    cout << sizeof(int*) << endl; // 8 bytes for my architecture
    cout << sizeof(char*) << endl; // 8 bytes for my architecture

    // 32bits of memory addressing
    // 2^32 = 4billion ~ 4GB
    // 2^64 = 4billion*4billion
    // cout << (long int)&a << endl;
    cout << &a << endl;

    // west const, east const

    int * const a_ptr = &a; // auto will now deduce int, int* a_ptr = &a;
    // auto a2_ptr = &a; // auto will now deduce int*, int* a_ptr = &a;
    cout << a_ptr << endl;

    *a_ptr = 20;

    auto& a_ref = a;
    a_ref = 20; // effectively the same thing with writing a=20;


    return 0;
}
