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

template<typename T>
T&& MOVE(T& smt) {
    return (T&&)smt;
}

int main(int argc, char* argv[])
{
    auto i = 20; // integer ---> 4 bytes in my arch

    auto* int_arr = new int[10]; // allocate 10 integers ---> allocate 40bytes in my arch
    delete[] int_arr;

    auto dog = Animal("Dog", 5); // Animal ---> 8 bytes in my arch, because it has one ptr
    cout << dog.name << endl;

    // Animal dog2(dog); // old dialects
    // int k(5);
    auto dog2 = (Animal&&)dog; // copy c-tor
    // from this line onwards, you will never use dog again.

    auto dog3 = Animal();
    dog3 = dog2; // copy assignment

    auto dog4 = Animal();
    // dog4 = (Animal&&)dog3;
    dog4 = std::move(dog3);

    return 0;
}
