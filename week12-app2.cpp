// tuples: how to design our own new dialect tuple structure? A case-study

// unique_ptr, shared_ptr, make_unique, make_shared
// = default, = delete, std::declval
// static_cast<T>, dynamic_cast<T>, reinterpret_cast<T>, const_cast<T>
// tag dispatching trick
// CRTP: curiously recurring template pattern
// lambdas capturing local variables: this includes local parameter packs as well
// storing parameter packs: an elegant storage container; get_first, get_size, get_tail impl.
// std::optional<T>
// duck typing? type erasure: std::function
// ADL: argument dependent lookup, friend functions
// SFINAE: enable_if, and its relation with concepts

#include <iostream>
#include <variant>

using namespace std;

template <typename First, typename ... Rest>
struct Tuple {
    First value;
    Tuple<Rest...> rest;

    template<int wanted_index>
    auto get() const {
        if constexpr(wanted_index == 0)
            return value;
        else
            return rest.template get<wanted_index-1>();
    }

    template<typename WantedType>
    auto get() const {
        if constexpr(std::is_same_v<First, WantedType>)
            return value;
        else
            return rest.template get<WantedType>();
    }

};

template <typename T>
struct Tuple<T> {
    T value;

    template<int index>
    auto get() const {
        // check how to write static assert here
        if constexpr(index == 0)
            return value;
    }

    template<typename WantedType>
    auto get() const {
        // check how to write static assert here
        if constexpr(std::is_same_v<T, WantedType>)
            return value;
    }
};

template<int index, typename ... Ts>
auto get(const Tuple<Ts...>& t) {
    return t.template get<index>();
}

template<typename T, typename ... Ts>
auto get(const Tuple<Ts...>& t) {
    return t.template get<T>();
}

// struct Foo {
//     int i;
//     float f;
//     double d;
// };

int main()
{
    auto t = Tuple<int, float, double, double>{2, 1.1f, 3.14, 6.28};
    // cout << t.get<2>() << endl;

    // homework: try to implement an ambiguity check if type is used more than once
    // here we have two double types in our Tuple definition
    // so, get which double?
    // it must generate a compile time error
    // but it returns the value of the first double we find right now
    // cout << t.get<double>() << endl;
    cout << get<double>(t) << endl;

    // // cout << t.get<3>() << endl;
    // cout << get<0>(t) << endl;
    // cout << get<double>(t) << endl;
    // // cout << t.get<double>() << endl;

    return 0;
}
