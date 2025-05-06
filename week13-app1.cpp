// duck typing? type erasure: std::function
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
#include <string>
#include <functional>

using namespace std;

void foo(int i) { cout << "foo " << i << endl; }
void bar(int i) { cout << "bar " << i << endl; }

struct Foo {
    string title;
    void print1(int i) const { cout << "struct Foo/print1 " << title << " " << i << endl; }
    void print2(int i) const { cout << "struct Foo/print2 " << title << " " << i << endl; }
};

void print2(const Foo& self, int i) {
    cout << "struct Foo/print2 " << self.title << " " << i << endl;
}


// typedef void (*funcptr)(int);
// typedef int INT;
// int i;

// template<int times, typename FUNC>
// void repeat_it(const FUNC& func) {
//     for(int i=0; i<times; i++)
//         func();
// }

template<int times>
void repeat_it(const std::function<void(void)>& func) {
    for(int i=0; i<times; i++)
        func();
}


int main() {
    repeat_it<10>([]() { cout << "hi there" << endl; });
    repeat_it<50>([]() { cout << "hello" << endl; });

    using funcptr = void(*)(int);
    // funcptr ptr = nullptr; // C notation
    // auto ptr = &foo;
    auto ptr = funcptr{};
    // ptr = foo; // this also works, just the same
    ptr = &foo; // this is okay, and please use this notation

    // ptr(10); // this also works fine, because C helps you
    (*ptr)(10); // this is the correct way
    ptr = &bar;
    (*ptr)(10);

    auto f = Foo{"TITLE"};
    f.print1(100);
    f.print2(100);
    print2(f, 100);

    using memfuncptr = void(Foo::*)(int) const;
    memfuncptr mptr = &Foo::print1;
    (f.*mptr)(200);
    mptr = &Foo::print2;
    (f.*mptr)(200);

    auto FUNCPTR = std::function<void(int)>{};
    FUNCPTR = &foo;
    FUNCPTR(1000);
    FUNCPTR = &bar;
    FUNCPTR(1000);

    FUNCPTR = [](int k) { cout << "lambda " << k << endl; };
    FUNCPTR(3000);

    auto MEMFUNCPTR = std::function<void(const Foo&, int)>{};
    MEMFUNCPTR = &Foo::print1;
    MEMFUNCPTR(f, 2500);

    return 0;
}
