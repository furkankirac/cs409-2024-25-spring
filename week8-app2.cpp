// std::pair, std::tuple, std::variant

// parameter packs, fold expressions
// concepts

// GENERICS
// perfect forwarding

#include <iostream>
#include <vector>
#include <map>
#include <variant>

using namespace std;

template<typename Key, typename Value>
struct Pair {
    Key first;
    Value second;

    // IntStringPair() { }
    // IntStringPair(int i, string s) : first(i), second(s) { }
};


struct Whatever {
    int i;
    float f;
    string s;
};

union UNION {
    int i;      // 4 bytes for my arch
    double f;   // 8 bytes for my arch
    const char* p;
};

enum UNION_TYPE {
    INT = 0,
    DOUBLE = 1,
    CONSTCHARPTR = 2,
};

struct Variant {
    UNION_TYPE union_type;
    UNION u;
    // ...
};


int main(int argc, char* argv[])
{
    UNION IF;
    IF.i = 4;
    IF.f = 3.14f;

    cout << IF.i << endl;

    using MYVARIANT = std::variant<int, double, const char *>;
    // std::any;

    auto mv0 = MYVARIANT{3.14};
    auto mv1 = MYVARIANT{"hi"};
    mv1 = 3.14f;


    auto p = Pair(10, "ten"s); // custum literals

    auto t = std::tuple<int, float, string>{1, 3.14f, "hi there"};
    auto t2 = Whatever{1, 3.14f, "hi there"};

    cout << std::get<float>(t) << endl;;
    cout << std::get<2>(t) << endl;;

    auto v = vector<std::pair<string, int>>{
        {"one", 1},
        {"five", 5},
    };

    auto m = map<string, int>{
        {"one", 1},
        {"five", 5},
    };

    cout << v[0].second << endl;
    cout << m["five"] << endl;
}
