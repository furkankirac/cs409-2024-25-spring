// CORE:
// const T& -> l-value and r-value binding behavior at the same time

// GENERICS:
// Compile time type debugging: TypeDisplay<T>
// reference collapsing
// T&&, auto&& keywords and their unexpected behavior

// GENERICS + FUNCTIONAL
// metaprogramming:
//  value trait: is_lvalue_ref<T>, true_value, false_value, integral_value<T>, remove_ref<T>

// std::pair, std::tuple, std::variant
// parameter packs, fold expressions
// concepts

// GENERICS
// perfect forwarding

#include <iostream>
#include <string>

using namespace std;

template<auto t> struct IntegralValue { static constexpr decltype(t) value = t; };
struct False_Value : IntegralValue<false> { };
struct True_Value : IntegralValue<true> { };

// template<typename T, T t> struct IntegralValue { static constexpr T value = t; };
// struct False_Value : IntegralValue<bool, false> { };
// struct True_Value : IntegralValue<bool, true> { };

// std equivalent is std::false_value
// struct False_Value { static constexpr bool value = false; };

// std equivalent is std::true_value
// struct True_Value { static constexpr bool value = true; };

template<typename T> struct is_lvalue_ref : False_Value { };
template<typename T> struct is_lvalue_ref<T&> : True_Value { };

template<typename T> struct is_rvalue_ref : False_Value { };
template<typename T> struct is_rvalue_ref<T&&> : True_Value { };


template<typename T> struct remove_ref      { using type = T; };
template<typename U> struct remove_ref<U&>  { using type = U; };
template<typename U> struct remove_ref<U&&> { using type = U; };



template<typename T>
struct TypeDisplay; // forward declaration


auto foo(const string& s) { // this const& thing binds to both l-value and r-value ref
    // auto t = TypeDisplay<string>{};
}

template<typename T>
auto bar(T&& t) { // forwarding ref
    // binds to both l-value and r-value variable
    // T's internal refness is chosen by compiler so that binding is successful
    // auto t = TypeDisplay<T>{};

    // if call-site t is an l-value
    // compiler chooses T as i.e. int& (with a single ref) so that it callapses to &

    // if call-site t is an r-value
    // compiler chooses T as i.e. int (with no refness) so that it callapses to &&

    // cout << is_lvalue_ref<T>::value << endl;

    if constexpr(is_lvalue_ref<T>::value) { // check if call-site value is an l-value
        cout << "I am sent an l-value (can only bind with &)" << endl;

    } else { // must be an r-value then
        cout << "I am sent an r-value (can only bind with &&)" << endl;
    }
}

template<typename T>
auto dummy(T&&) {
    using T_pure = remove_ref<T>::type;
    if constexpr(is_same<T_pure, int>::value) {

    }
}


int main(int argc, char* argv[])
{
    using int_ref = int&;
    using int_refref = int&&;

    // REFERENCE COLLAPSING RULE introduced aith dialect 2011 (C++11)
    // TypeDisplay<int_ref>{};          // int&         ---> int&
    // TypeDisplay<int_ref&>{};         // int&     &   ---> int&
    // TypeDisplay<int_ref&&>{};        // int&     &&  ---> int&
    // TypeDisplay<int_refref>{};       // int&&        ---> int&&
    // TypeDisplay<int_refref&>{};      // int&&    &   ---> int&
    // TypeDisplay<int_refref&&>{};     // int&&    &&  ---> int&&
    // reference collapse can generate && only when
    //  type's refness and its modifier are both &&
    // or
    //  type is pure (contains no refness) and modifier is &&

    // bar(5);
    int k = 5;
    bar(k);

    // auto s = string("whatever");
    // // foo(s);
    // foo(string("whatever"));
    // bar(5);
}
