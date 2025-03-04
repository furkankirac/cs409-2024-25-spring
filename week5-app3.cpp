// OOP:
// construction in general
// move ctor, move assignment
// console struct and instance example
// function objects / lambdas

// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct Animal {
    string name;
    int age = 0; // 4 bytes in my arch

    Animal() : name("Po")  { }

    Animal(const string& name_to_be) : name(name_to_be), age(0) {
        cout << "copy c-tor got called" << endl;
    }

    Animal(const string& name_to_be, int age) : Animal(name_to_be) { // c-tor delegation
        this->age = age;
    }

    Animal(const Animal& other) : Animal(other.name, other.age) { }

    Animal(Animal&& other) : name(std::move(other.name)), age(other.age) {
        cout << "move c-tor got called" << endl;
    }

    Animal& operator=(const Animal& other) {
        cout << "copy assignment got called" << endl;
        name = other.name; // call's string's copy assignment
        age = other.age; // call's int's copy assignment
        return *this;
    }

    auto operator=(Animal&& other) {
        cout << "move assignment got called" << endl;
        name = std::move(other.name);
        age = other.age;
    }

    ~Animal() {
        cout << "Animal destructor got called" << endl;
    }
};

struct Console {
};

Console COUT;
Console COUT2;

template<typename T>
auto& operator<<(Console& c, T value) {
    std::cout << value << endl << endl;
    return c;
}


int main(int argc, char* argv[])
{
    // cout << 4 << endl;
    COUT << 4;
    COUT2 << 4.4 << 5;

    return 0;
}
