// OOP:
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
#include <vector>
#include <list>

using namespace std;

template<typename T>
void print(const T& container) {
    for(const auto& item : container)
        cout << item << " ";
    cout << endl;
}

// template<typename T>
// void transform(T& container) {
//     for(auto& item : container) {
//         item++;
//     }
// }

template<typename T, typename F>
void transform(T& container, F funcobj) {
    for(auto& item : container) {
        funcobj(item);
    }
}

// struct Incrementor {
//     int value;

//     Incrementor(int value) : value(value) { }

//     void operator()(float& f) const {
//         f += value;
//     }
// };

int main(int argc, char* argv[])
{
    auto v1 = std::vector<float>{1.1f, 2.2f, 3.3f};
    auto v2 = std::list<int>{1, 2, 3};
    print(v1);
    print(v2);

    auto incrementor = [value=300](float& f) mutable {
        f += value;
        value += 10;
    };

    // auto incrementor = Incrementor(300);
    transform(v1, incrementor); //[value=300](float& f) { f += value; });
    // transform(v1, multiplier);
    // auto multiplier = Multiplier();
    // transform(v1, multiplier);
    print(v1);
}
