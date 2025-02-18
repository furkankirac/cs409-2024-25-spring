// core language definitions:
// - l-value / r-value
// - chain assignment
// - constness: east/west const, pointers and const
// - C++ reference vs pointers

// OOP:
// assignment
// copy c-tor, copy assignment
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// move-ctor, move-assignment

// functional programming:
// - overloading
//   (all the operators are implemented as functions and they also can ve overloaded)

// Generics / Templates:
// function, class, variable, type templates

#include <iostream>
// #define AAA Vector2d

using namespace std;

template<typename T>
struct Vector2d {
    static inline int numVector2d = 0;

    T x = 0;
    T y = 0;

    Vector2d(/* Vector2d* v, */T x, T y) {
        numVector2d++;
        this->x = x;
        this->y = y;
    }

    // copy constructor
    Vector2d(const Vector2d& other) {
        cout << "copy c-tor got called" << endl;
        numVector2d++;
        this->x = other.x;
        this->y = other.y;
    }

    // copy assignment
    Vector2d& operator=(const Vector2d& right) {
        this->x = right.x;
        this->y = right.y;
        return *this;
    }

    ~Vector2d() {
        numVector2d--;
    }

    template<typename K>
    auto operator+(/*Vector2d left, */const Vector2d<K>& right) {
        auto& self = *this;
        Vector2d c(0, 0);
        c.x = self.x + right.x;
        c.y = self.y + right.y;
        return c;
    }


    T& get_x() {
        return x;
    }

    static int inform() {
        cout << "active vector2ds: " << Vector2d<T>::numVector2d << endl;
        return 5;
    }

};

int main(int argc, char* argv[])
{
    auto a = Vector2d<int>(1, 10);
    auto& ax = a.get_x();
    cout << ax << endl;

    // cout << a.get_x() << endl;

    // Vector2d(1, 10);
    // 5;
    Vector2d<int>::inform();

    auto b = Vector2d<float>(-5.2f, -2.2f);
    Vector2d<float>::inform();

    auto c = a + b;
    // auto c = a.operator+(b);
    Vector2d<int>::inform();

    // solve the error that occurs in the compilation of below line
    // as a homework
    // Vector2d d = c = b = a;

    // auto ptr = &b;

    cout << "cx = " << c.x << endl;
    cout << "cy = " << c.y << endl;

    return 0;
}
