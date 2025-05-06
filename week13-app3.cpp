// lambdas capturing local variables: this includes local parameter packs as well
// storing parameter packs: an elegant storage container; get_first, get_size, get_tail impl.
// tag dispatching trick
// CRTP: curiously recurring template pattern

// std::declval
// static_cast<T>, dynamic_cast<T>, reinterpret_cast<T>, const_cast<T>
// std::optional<T>
// ADL: argument dependent lookup, friend functions
// SFINAE: enable_if, and its relation with concepts

#include <iostream>
#include <tuple>

using namespace std;

// struct Whatever {
//     int i = 10;
//     auto operator() () const {
//         cout << i << endl;
//     }
// };

// template<typename ... Ts> // int|double|const char[3]
// auto mylist(const Ts& ... ts) { // 10|3.14|"hi"
//     return [ts...](auto accessor) {
//         // return std::tuple<Ts...>(ts...);
//     };
// };

auto mylist(const auto& ... ts) {
    return [ts...](auto accessor) {
        return accessor(ts...);
    };
};

// struct ... {
//     template<>
//     operator()
// }


auto get_first() {
    return [](const auto first, const auto& ... rest) {
        return first;
    };
}

auto get_tail_aslist() {
    return [](const auto first, const auto& ... rest) {
        return mylist(rest...);
    };
}

// auto get_first(const auto first, const auto& ... rest) {
//     return first;
// };


int main() {
    auto i = 10;
    // auto whatever = Whatever{};
    auto lambda = [&i]() { cout << i << endl; };

    auto l = mylist(10, 3.14, "hi"s);
    cout << l( get_first() ) << endl;

    auto l_tail = l(get_tail_aslist());
    cout << l_tail( get_first() ) << endl;


    // cout << std::get<0>(l(  )) << endl;


    return 0;
}
