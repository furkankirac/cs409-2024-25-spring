// alignment, padding

// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

// construction: initializer list
// function objects / lambdas

#include <iostream>
#include <string>

using namespace std;

// struct string {
//     string(const char* whatever) {
//          // ...
//     }
//     string(const string& other) {
//         // ...
//     }
// };

struct Animal {
    string name; // 32 bytes in my architecture
    int age = 0; // 4 bytes in my arch

    // default c-tor
    Animal() : name("Po") // const char[3] --> const char *
    { }

    // c-tor from string
    Animal(const string& name_to_be) : name(name_to_be), age(0) {
        // cout << "copy c-tor got called" << endl;
    }

    // c-tor from string (name), int (age)
    Animal(const string& name_to_be, int age) : name(name_to_be), age(age) { }

    // copy c-tor: c-tor from an available Animal instance
    Animal(const Animal& other) : Animal(other.name, other.age) { }

    // move c-tor: c-tor from an available Animal instance, we steal from "other" if possible
    Animal(Animal&& other) : name(std::move(other.name)), age(other.age) {
        // cout << "move c-tor got called" << endl;
    }

    // copy assignment:
    // write on top of (already constructed) this instance from an available "other" Animal
    Animal& operator=(const Animal& other) {
        // cout << "copy assignment got called" << endl;
        name = other.name; // call's string's copy assignment
        age = other.age; // call's int's copy assignment
        return *this;
    }

    // move assignment
    // write on top of (already constructed) this instance from an available "other" Animal
    // if possible steal from "other"
    auto& operator=(Animal&& other) {
        // cout << "move assignment got called" << endl;
        name = std::move(other.name);
        age = other.age;
        return *this;
    }

    ~Animal() {
        // cout << "Animal destructor got called" << endl;
    }

    // virtual void shout() {
    //     cout << "What?" << endl;
    // }

    // makes this class abstract until shout gets declared in one of its descendants
    virtual void shout() {
        cout << "Base shout" << endl;
    }
    void shout(int) { } // overloading shout
};

struct Dog : Animal { // inheritance
    using Animal::Animal;
    void shout() { // override
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
    // cout << dog.name << endl;
    // dog.shout();

    auto bird = Bird("Karga");
    // cout << bird.name << endl;
    // bird.shout();

    Animal(); // r-value ---> temporary value for the time being

    Animal* animals[] = { &dog, &bird };
    for(int i=0; i<2; i++) {
        cout << animals[i] << endl;
        animals[i]->shout();
    }

    // short string optimization
    cout << sizeof(string) << endl; // 32 bytes in my standard library
    cout << sizeof(Animal) << endl;

    return 0;
}

