// GENERICS + FUNCTIONAL
// metaprogramming:
//  add<a, b>, value-traits, type-traits, remove_ref<T>

// GENERICS:
// Compile time type debugging: TypeDisplayer<T>
// reference collapsing
//  is_lvalue_ref
// T&&, auto&&
// perfect forwarding
// parameter packs, fold expressions

#include <iostream>

using namespace std;

// the metaprogramming trick
struct Foo {
    static constexpr bool value = true;
};

using INT = int;

struct Bar {
    using type = int;
};


template<typename T> struct IsInteger      { static constexpr bool value = false; };
template<>           struct IsInteger<int> { static constexpr bool value = true; };

// struct IsInteger_int {
//     static constexpr bool value = true;
// };

// struct IsInteger_float {
//     static constexpr bool value = false;
// };

template<typename T>
void print() {
    if constexpr(IsInteger<T>::value) {
        cout << "T is an integer" << endl;
    } else {
        cout << "T is NOT an integer" << endl;
    }
}

void print_int() {
    cout << "T is an integer" << endl;
}

void print_float() {
    cout << "T is NOT an integer" << endl;
}

template<int a, int b>
struct Add {
    static constexpr auto value = a + b;
};

struct Add_10_20 {
    static constexpr auto value = 10 + 20;
};

template<int a, int b> struct Divide { static constexpr auto value = a / b; };
template<int a>        struct Divide<a, 0> { static constexpr auto value = 0; };


int main(int argc, char* argv[])
{
    // Foo::value;
    // Bar::type a = 5;
    // INT b = 5;

    cout << IsInteger<int>::value << endl;
    cout << IsInteger<float>::value << endl;

    print<int>();
    print<int>();
    print<float>();
    print<string>();
    // 3 different print functions got created
    // one for int, one for float, one for string

    cout << Add<10, 20>::value << endl;
    cout << Divide<10, 0>::value << endl;
}
