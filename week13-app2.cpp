// comma operator
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

using namespace std;

auto func() {
    return (cout << "bye" << endl), 20, "hi there";
}

// 10, 20, "hi", 3.14
template<typename ... Ts> // Ts = int|int|const char[3]|double
void print(const Ts& ... ts) { // ts = 10|20|"hi"|3.14
    // ts...; // this is only suitable for to be put into function call context
    // func(10, 20, "hi", 3.14) // like this one
    // func(ts...);
    // (ts + ...); // 10 + 20 + "hi" + 3.14
    ((cout << ts << endl), ...);
    // (cout << 10 << endl), (cout << 20 << endl), (cout << "hi" << endl), (cout << 3.14 << endl);
}


int main() {
    cout << "hello" << endl;

    // int j = 0;
    // for(int i=0; i<10; i++, j++) {
    // }

    cout << func() << endl;

    print(10, 20, "hi", 3.14);

    return 0;
}
