// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

// alignment, padding

// construction: initializer list
// function objects / lambdas

#include <iostream>
#include <vector>

using namespace std;

struct Foo {
    char c;  // 1
    // 3 byte padding
    int a;   // 4
    char c2; // 1
    // 3 byte padding
};

int main(int argc, char* argv[])
{
    cout << sizeof(Foo) << endl;
    // cout << sizeof(long long int) << endl; // 8
    // cout << sizeof(long int) << endl;      // 8
    // cout << sizeof(int) << endl;           // 4
    // cout << sizeof(short int) << endl;     // 2
    // cout << sizeof(char) << endl;          // 1
    // cout << sizeof(float) << endl;         // 4
    // cout << sizeof(double) << endl;        // 8

    auto v = vector<Foo>(10);

    return 0;
}
