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

struct Foo {
    int i;
    float f;
    double d;
};

template<int index>
auto get(const Foo& foo) {
    if constexpr(index == 0) {
        return foo.i;
    } else if constexpr(index == 1) {
        return foo.f;
    } else if constexpr(index == 2) {
        return foo.d;
    }
}

template<typename T>
auto get(const Foo& foo) {
    if constexpr(is_same_v<T, int>) {
        return foo.i;
    } else if constexpr(is_same_v<T, float>) {
        return foo.f;
    } else if constexpr(is_same_v<T, double>) {
        return foo.d;
    }
}

std::variant<int, float, double> get(const Foo& foo, int index) {
    if (index == 0) {
        return foo.i;
    } else if (index == 1) {
        return foo.f;
    } else if (index == 2) {
        return foo.d;
    }
    return {};
}


// int get_0(const Foo& foo) { return foo.i; }
// float get_1(const Foo& foo) { return foo.f; }
// double get_2(const Foo& foo) { return foo.d; }

int main()
{
    auto foo = Foo{2, 1.1f, 3.14};
    cout << get<0>(foo) << endl; // must return 2 (int)
    cout << get<1>(foo) << endl; // must return 1.1f (float)
    cout << get<2>(foo) << endl; // must return 3.14 (double)

    cout << get<int>(foo) << endl; // must return 2 (int)
    cout << get<float>(foo) << endl; // must return 1.1f (float)
    cout << get<double>(foo) << endl; // must return 3.14 (double)


    // Homework, make this working
    // cout << get(foo, 0) << endl; // must return 2 (int)
    // cout << get(foo, 1) << endl; // must return 1.1f (float)
    // cout << get(foo, 2) << endl; // must return 3.14 (double)


    // auto t = tuple<int, float, double>{2, 1.1f, 3.14};

    // // cout << t.get<3>() << endl;
    // cout << get<0>(t) << endl;
    // cout << get<double>(t) << endl;
    // // cout << t.get<double>() << endl;

    return 0;
}
