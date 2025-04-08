// C++11 dialect: parameter packs, pack expansions
// C++14 dialect: ...
// C++17 dialect: fold expressions (easier pack expansion recursion logic)

#include <iostream>
#include <vector>

using namespace std;

// variadic template representation

// template<typename T> auto sum(T t) { return t; }
// template<typename T, typename U> auto sum(T t, U u) { return t + u; }
// template<typename T, typename U, typename R> auto sum(T t, U u, R r) { return t + u + r; }

// call it like this
// sum(10.1, 20, 30.3f)
// Ts is smt like double|int|float
// Ts ... ts ---->   double, int, float ---> 10.1|20|30.3f
// Ts = double|int|float
// ts = 10.1|20|30.3f

// template<typename T>
// auto sum(T t) { return t; }

// template<typename First, typename ... Rest>
// auto sum(First first, Rest ... rest) {
//     return first + sum(rest...);
// }

// template<typename First, typename ... Rest>
// auto sum(First first, Rest ... rest) {
//     if constexpr(sizeof...(rest) == 0)
//         return first;
//     else
//         return first + sum(rest...); //pack expansion
// }

template<typename ... Ts>
auto sum(Ts ... ts) {
    // fold expression, expands parameter pack by putting + operator in between
    // you can use most of the available operators
    return (ts + ...);
}




// sum(10.1, 20, 30.3) ---> 10.1 + sum(20, 30.3) ---> 10.1 + 20 + sum(30.3)
// ----> 10.1 + 20 + 30.3



int main(int argc, char* argv[])
{
    // cout << sum(5, 6) << endl;
    // cout << sum("hello"s, "there"s) << endl;
    cout << sum(10.1, 20, 30.3f) << endl;
}
