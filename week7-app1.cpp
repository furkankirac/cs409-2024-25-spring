// CORE:
// const, constexpr, if constexpr

// OOP:
// std::array
// function objects / lambdas

// GENERICS:
// Compile time type debugging: TypeDisplayer<T>
// reference collapsing
//  is_lvalue_ref
// T&&, auto&&
// perfect forwarding
// parameter packs, fold expressions

// GENERICS + FUNCTIONAL
// metaprogramming:
//  add<a, b>, value-traits, type-traits, remove_ref<T>


#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

struct Foo {
    int value = 14;

    Foo() {}
    Foo(int value) : value(value) { }
    Foo(std::initializer_list<int> il) : value(15) {
        // ...
    }

    void print() const {
        cout << "my value is " << value << endl;
    }

    void operator() () const {
        cout << "my value is " << value << endl;
    }
};

template<typename T>
void print_container(const T& container) {
    // for(auto iter = container.begin(); iter != container.end(); iter++) {
    //     const auto& item = *iter;
    //     cout << item << " ";
    // }

    for(const auto& item : container)
        cout << item << " ";

    cout << endl;
}


int main(int argc, char* argv[])
{
    auto foo = Foo{}; // 1 byte
    auto foo2 = Foo{1000};
    cout << sizeof(Foo) << endl;
    cout << foo2.value << endl;
    foo2.print();
    // foo2.operator()();
    foo2();

    auto v1 = std::vector<float>{1.1f, 2.2f, 3.3f};
    auto v2 = std::list<int>{1, 2, 3};
    print_container(v1);
    print_container(v2);

    // constexpr int x = 5;  // x is a compile-time constant with value 5
    // constexpr double pi = 3.14159;

    // int a = 5;             // not computed at compile time
    // constexpr int b = 5;   // Constant and computed at compile time
    // // int arr1[a];
    // // auto arr1 = array<int, a>{}; // Error: a is not a constant expression
    // auto arr2 = array<int, b>{}; // OK: b is a constant expression

    // constexpr auto algo = 1;
    // if constexpr(algo == 1) {
    //     cout << "algorithm 1" << endl;
    // } else {
    //     cout << "algorithm 2" << endl;
    // }
}
