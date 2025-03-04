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

    // virtual void shout() {
    //     cout << "What?" << endl;
    // }

    // makes this class abstract until shout gets declared in one of its descendants
    virtual void shout() = 0;
};

struct Dog : Animal { // inheritance
    void shout() {
        cout << "Bark" << endl;
    }
};

struct Bird : Animal { // inheritance
    using Animal::Animal;
    void shout() {
        cout << "Gak" << endl;
    }
};


int main(int argc, char* argv[])
{
    // auto animal = Animal(); // cannot be done since Animal is abstract now

    auto dog = Dog();
    cout << dog.name << endl;
    dog.shout();

    auto bird = Bird("Karga");
    cout << bird.name << endl;
    bird.shout();

    Animal* animals[] = { &dog, &bird };
    for(int i=0; i<2; i++) {
        animals[i]->shout();
    }

    return 0;
}
