// C++ reference vs pointers
// l-value binding, r-value binding
// new, new[], delete, delete[]

// copy c-tor, copy assignment
// move ctor, move assignment

// Generics / Templates:
// function, class, variable, type templates

// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

#include <cstring>
#include <iostream>
// #include <stdio.h> // C standard library i/o functionality
// #include <string>

using namespace std;

struct Animal
{
    // char name[10]; // what's the type of name --> char[10];
    char* name;

    Animal() {
        name = new char[3];
        name[0] = 'P';
        name[1] = 'o';
        // ...
        name[2] = 0; //'\0';
    }

    Animal(const char* name_to_be) {
        auto length = strlen(name_to_be);
        name = new char[length + 1];
        strcpy(name, name_to_be);

        // cout << strlen(name_to_be) << endl;
        // strcpy(name, name_to_be);
        // cout << (long int*)name_to_be << endl;
        // cout << name_to_be[0] << endl;
    }

    ~Animal() {
        delete[] name;
        cout << "Animal destructor got called" << endl;
    }
};


int main(int argc, char* argv[])
{
    // string s("Hi there");
    // auto s = string("Hi there");

    {
        auto animal = Animal();
        cout << animal.name << endl;
    }

    auto animal2 = Animal("Dog"); // const char[4]
    cout << animal2.name << endl;


    // cout << (int)'0' << endl; // 48

    return 0;
}
