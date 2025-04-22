// decltype(auto)
// aggregate construction
// Function objects, operator() overloads and multiple inheritance
// lambda equivalents and the "struct overloaded { ... }" trick
// std::variant

#include <iostream>
#include <array>

using namespace std;

int foo() { return 5; }
int& bar() {
    static auto a = 5;
    return a;
}

template<typename ...>
struct TypeDisplay;

struct Simple {
    int x;
    int y;
    int z;

    // Simple(int x, int y, int z) : x(x), y(y), z(z) { }
    // Simple(std::initializer_list<int> il) {
    //     x = il.begin()[0];
    //     y = il.begin()[1];
    //     z = il.begin()[2];
    // }
};

int main(int argc, char* argv[])
{
    auto arr = array<int, 6>{};
    auto simple = Simple{1, 2, 3}; // aggregate c-tor is working

    auto a = foo();
    auto b = bar();
    decltype(auto) c = foo();
    decltype(auto) d = bar();
    // auto t = TypeDisplay<decltype(a), decltype(b), decltype(c), decltype(d)>{};

    return 0;
}
