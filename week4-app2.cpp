// C++ reference vs pointers
// l-value binding, r-value binding
// new, new[], delete, delete[]

// copy c-tor, copy assignment
// move ctor, move assignment

// Generics / Templates:
// function, class, variable, type templates

// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

#include <iostream>

using namespace std;


auto func(int* a) {
    // a++;
    (*a)++;
}

// auto func_cpp(int& a) { // l-value binding
//     cout << "l-value binding version" << endl;
//     a++;
// }
// auto func_cpp(float& a) { // l-value binding
//     cout << "l-value binding version" << endl;
//     a++;
// }


template<typename T>
auto func_cpp(T& a) { // l-value binding
    cout << "l-value binding version" << endl;
    a++;
}

auto func_cpp(auto&& a) { // r-value binding
    cout << "r-value binding version" << endl;
    a++;
}


int main(int argc, char* argv[])
{
    auto i = 100;
    // func(&i);
    // func_cpp(i);
    func_cpp(i);

    auto j = 3.14f;
    func_cpp(j);

    cout << i << endl;

    return 0;
}
