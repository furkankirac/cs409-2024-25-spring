// C++11 dialect: r-value references (int&&)
// C++11 dialect: Perfect Forwarding necessity due to r-value refs
//                Perfect forwarding lets a function forward its arguments
//                to another function while preserving their exact type
//                properties (l-value or r-value)
// C++11 dialect: parameter packs, pack expansions
// C++14 dialect: ...
// C++17 dialect: fold expressions (easier pack expansion recursion logic)

#include <iostream>
#include <vector>

using namespace std;

void foo(int&) { cout << "l-value arrived" << endl; }
void foo(int&&) { cout << "r-value arrived" << endl; }

// T-->int&  so that int& && --> collapses to int&
// T-->int   so that int &&  --> collapses to int&&
template<typename T>
void bar(T&& t) { // forwarding reference
    // foo(t);
    foo(std::forward<T>(t)); // forward<T> conditionally casts t as r-value if T is pure
}

int main(int argc, char* argv[])
{
    auto i = 5;
    // foo(i);
    // foo(5);
    bar(i); // says l-value arrived
    bar(5); // says l-value arrived again!
}
