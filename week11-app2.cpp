// Function objects, operator() overloads and multiple inheritance
// lambda equivalents and the "struct overloaded { ... }" trick
// std::variant
#include <iostream>
#include <variant>

using namespace std;

struct FuncObjInt { auto operator() (int a) const { cout << "this is an integer " << a << endl; } };
struct FuncObjFloat { auto operator() (float a) const { cout << "this is a float " << a << endl; } };
struct FuncObjDouble { auto operator() (double a) const { cout << "this is a double " << a << endl; } };

struct FuncObjIntFloatDouble {
    auto operator() (int a) const { cout << "this is an integer " << a << endl; }
    auto operator() (float a) const { cout << "this is a float " << a << endl; }
    auto operator() (double a) const { cout << "this is a double " << a << endl; }
};

// this is essentially the same structure with FuncObjIntFloat
struct FuncObjIntFloat2 : FuncObjInt, FuncObjFloat, FuncObjDouble {
    using FuncObjInt::operator(), FuncObjFloat::operator(), FuncObjDouble::operator();
};

template<typename ... Ts>
struct Overloaded : Ts... {
    using Ts::operator()...;
};

auto fo_int_lambda = [](int a) { cout << "this is an integer " << a << endl; };
auto fo_float_lambda = [](float a) { cout << "this is a float " << a << endl; };
auto fo_double_lambda = [](double a) { cout << "this is a double " << a << endl; };

auto Z = Overloaded{fo_int_lambda, fo_float_lambda, fo_double_lambda};
auto G = Overloaded<FuncObjInt, FuncObjFloat, FuncObjDouble>{};

int main()
{
    // auto fo_int = FuncObjInt{};
    // fo_int(10);

    // auto fo_float = FuncObjFloat{};
    // fo_float(3.14f);

    // auto fo_intfloat = FuncObjIntFloat2{};
    // fo_intfloat(10);
    // fo_intfloat(3.14f);

    // struct FuncObjInt {
    //     auto operator() (int a) const {
    //         cout << "this is an integer " << a << endl;
    //     }
    // };

    auto fo_int_lambda = [](int a) { cout << "this is an integer " << a << endl; };
    // fo_int_lambda(10);

    auto fo_float_lambda = [](float a) { cout << "this is a float " << a << endl; };
    // fo_float_lambda(3.14f);

    auto fo_double_lambda = [](double a) { cout << "this is a double " << a << endl; };
    // fo_double_lambda(1.111);

    // G(10);
    // G(3.14f);
    // G(1.111);

    int a = 7;
    switch(a) {
    case 1: break;
    case 3: break;
    default: break;
    }

    auto K = Overloaded{
        [](int a) { cout << "this is an integer " << a << endl; },
        [](float a) { cout << "this is a float " << a << endl; },
        [](double a) { cout << "this is a double " << a << endl; },
        };

    K(10);
    K(3.14f);
    K(1.111);

    using IntFloatDouble = std::variant<int, float, double>;
    auto ifd = IntFloatDouble{99.9};
    std::visit(K, ifd);

    // if(std::holds_alternative<int>(ifd))
    //     K(std::get<int>(ifd));
    // else if(std::holds_alternative<float>(ifd))
    //     K(std::get<float>(ifd));
    // else if(std::holds_alternative<double>(ifd))
    //     K(std::get<double>(ifd));
    // cout << std::holds_alternative<int>(ifd) << endl;


    return 0;
}
