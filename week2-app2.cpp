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

// C way
// typedef struct { int x; int y; } Vector2d;


struct Vector2d {
    static inline auto numVector2d = 0;

    int x = 0;
    int y = 0;

    Vector2d(/* Vector2d* v, */int x, int y) {
        numVector2d++;
        this->x = x;
        this->y = y;
    }

    ~Vector2d() {
        numVector2d--;
    }

    auto add(/*Vector2d a, */Vector2d b) {
        Vector2d c(0, 0);
        c.x = this->x + b.x;
        c.y = this->y + b.y;
        return c;
    }

    auto operator+(/*Vector2d left, */Vector2d right) {
        Vector2d c(0, 0);
        c.x = this->x + right.x;
        c.y = this->y + right.y;
        return c;
    }

};

// auto operator+(Vector2d left, Vector2d right) {
//     Vector2d c(0, 0);
//     c.x = left.x + right.x;
//     c.y = left.y + right.y;
//     return c;
// }




// int Vector2d::numVector2d = 0;

// void init2dVector(
//     Vector2d* v,
//     int x, int y) {
//     v->x = x;
//     v->y = y;
// }

// struct { int x; int y; } XY;
// struct { int x; int y; } XY2;


void inform() {
    cout << "active vector2ds: " << Vector2d::numVector2d << endl;
}


int main(int argc, char* argv[])
{
    auto a = Vector2d(1, 10);
    inform();

    // init2dVector(&a, 1, 10);
    // a.init2dVector(1, 10);

    auto b = Vector2d(-5, -2);
    inform();
    // b.init2dVector(-5, -2);

    // Vector2d c = add2dVectors(a, b);
    // auto c = a.add(b);
    // auto c = a + b;
    auto c = a.operator+(b);
    inform();

    {
        auto d = Vector2d(-5, -2);
    }
    inform();

    // 5 + 10;
    // operator+(5, 10);

    cout << "cx = " << c.x << endl;
    cout << "cy = " << c.y << endl;

    return 0;
}
