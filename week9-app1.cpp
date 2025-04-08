// previous lecture:
// ..., std::map (uses std::pair as its items for representing KEY, VALUE
// std::pair, std::tuple
// C unions --> std::variant + std::get

// This lecture
// generic dependent types:
// i.e. type alias in "typename std::remove_reference<T>::type"
// is dependent type on template's T parameter
// C++11 dialect: r-value references (int&&)
// C++11 dialect: Perfect Forwarding necessity due to r-value refs
//                Perfect forwarding lets a function forward its arguments
//                to another function while preserving their exact type
//                properties (l-value or r-value)
// C++11 dialect: parameter packs, pack expansions
// C++14 dialect: ...
// C++17 dialect: fold expressions (easier pack expansion recursion logic)
// C++20 dialect: concepts, requires clause + requires expression

// ----------------------------------------------------------------------------
// requires clause: (requires std::integral<T>)
// It is used to specify constraints on template parameters
// in a template declaration. It defines the conditions that a type (or types)
// must satisfy to be valid for instantiation of the template.

// ----------------------------------------------------------------------------
// requires expression: (requires(T a) { a + a; })
// It is a compile-time construct used to test whether a set of expressions
// or requirements is valid for a given type or types. It’s a way to define
// or check constraints explicitly.

// ----------------------------------------------------------------------------
// concepts are names/aliases assigned for requires expressions

#include <iostream>
#include <vector>

using namespace std;

// template<typename T> struct isIntegral { static constexpr bool value = false; };
// template<> struct isIntegral<int> { static constexpr bool value = true; };
// template<> struct isIntegral<char> { static constexpr bool value = true; };

template<typename T>
concept Addable = requires (T a) {
    a + a;
};


template<typename T>
concept IsStdContainer = requires (T hopefully_container) {
    hopefully_container.begin();
    hopefully_container.end();
    hopefully_container.size();
    // hopefully_container.push_back( decltype(*hopefully_container.begin()){} );
    // hopefully_container.push_back( {} );
    // hopefully_container.push_back( typename T::value_type{} );
};

template<typename T>
// requires clause
// requires std::is_integral<T>::value
// requires Addable<T>
// requires requires (T a) { a + a; }
void foo()
{
    // if constexpr (requires(T a) { a + a; }) {
    if constexpr (Addable<T>) {
        cout << "This is addable" << endl;
    }

    cout << "Hello" << endl;
}

// 1st notation
// template<typename T>
// requires IsStdContainer<T>
// void bar(const T& container) {
//     cout << "size of the container is " << container.size() << endl;
// }

// 2nd notation
// template<typename T>
// void bar(const T& container)
//     requires IsStdContainer<T> // container run-time paramater is also at our hands to use if required
// {
//     cout << "size of the container is " << container.size() << endl;
// }

// 3rd notation
// template<IsStdContainer T> // only works with single parametered concepts
// void bar(const T& container) {
//     cout << "size of the container is " << container.size() << endl;
// }

// 4th notation
// only works with single parametered concepts
// generic terse syntax
void bar(const IsStdContainer auto& container) {
    cout << "size of the container is " << container.size() << endl;
}

void print_vector(const vector<int>& v) {
}

int main(int argc, char* argv[])
{
    auto v = vector<int>{1, 2};
    // v + v;
    // foo<vector<int>>();
    // foo<int>();

    // bar(5);
    bar(v);

    print_vector({1, 2});
}
