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
// #include <string>

using namespace std;

struct Animal {
    // char name[10]; // what's the type of name --> char[10];
    char* name = nullptr; // 8 bytes in my arch
    int age = 0; // 4 bytes in my arch

    Animal() : name(new char[3])  {
        // name = new char[3]; // new[] operator
        name[0] = 'P';
        name[1] = 'o';
        name[2] = 0; //'\0';
        // age = 0;
    }

    Animal(const char* name_to_be) : name(nullptr), age(0) {
        cout << "copy c-tor got called" << endl;
        auto length = strlen(name_to_be);
        name = new char[length + 1];
        strcpy(name, name_to_be);
    }

    Animal(const char* name_to_be, int age) : Animal(name_to_be) { // c-tor delegation
        this->age = age;
    }

    Animal(const Animal& other) : Animal(other.name, other.age) { }

    Animal(Animal&& other) : name(other.name), age(other.age) {
        cout << "move c-tor got called" << endl;
        other.name = nullptr;
    }

    Animal& operator=(const Animal& other) {
        cout << "copy assignment got called" << endl;
        delete[] name;
        auto length = strlen(other.name);
        name = new char[length + 1];
        strcpy(name, other.name);
        age = other.age;
        return *this;
    }

    auto operator=(Animal&& other) {
        cout << "move assignment got called" << endl;
        delete[] name;
        name = other.name;
        other.name = nullptr;
        age = other.age;
    }

    ~Animal() {
        delete[] name;
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
