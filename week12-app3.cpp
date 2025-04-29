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
#include <memory>

using namespace std;

struct Bar {
    // Bar(const Bar&) = delete;
    // Bar(const Bar&) = default;

};

void foo(Bar b)
{

}

void func(unique_ptr<Bar> x) {

}

int main()
{
    auto b = Bar{};
    foo(b);

    // auto up = unique_ptr<Bar>(new Bar());
    // auto sp = shared_ptr<Bar>(new Bar());
    auto up = make_unique<Bar>();
    auto sp = make_shared<Bar>();

    // I cannot copy construct a unique_ptr<T>
    // it's by design, it's forbidden
    // auto clone = up;

    func(std::move(up));

    return 0;
}
