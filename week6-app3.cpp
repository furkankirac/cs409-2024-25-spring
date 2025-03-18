// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

// alignment, padding

// construction: initializer list
// casting operator

// function objects / lambdas

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Vector {
    T* data;
    int size;

    Vector(int size) : data(new T[size]), size(size) { }

    Vector(std::initializer_list<int> il) : data(new T[il.size()]), size(il.size()) {
        for(int i=0; i<il.size(); i++)
            data[i] = il.begin()[i];
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[] (int index) const {
        // size++;
        return data[index];
    }

    auto operator() () const {
        for(int i=0; i<size; i++)
            cout << (*this)[i] << " ";
        cout << endl;
    }

    operator int(/* Vector<T> const * this_*/) const {
        // size++;
        return size;
    }

    operator string() const {
        auto s = string("");
        for(int i=0; i<size; i++) {
            s += (*this)[i];
            s += " ";
        }
        return s;
    }

    template<typename K>
    auto convert_to() const {
        auto temp = Vector<K>(size);
        for(int i=0; i<size; i++)
            temp[i] = (*this)[i]; //    data[i];
        return temp;
    }

    auto multiply_by(const double coef) const {
        for(int i=0; i<size; i++)
            (*this)[i] *= coef;
    }

    auto operator*=(double coef) const {
        for(int i=0; i<size; i++)
            (*this)[i] *= coef;
    }

};

int main(int argc, char* argv[])
{
    // auto* p = new int[3];
    // p[0] = 1;
    // p[1] = 5;
    // p[2] = 10;
    // delete[] p;

    auto vi = Vector<int>{3, 5, 7, 9};
    cout << (int)vi << endl;
    auto vf = vi.convert_to<float>();

    vf();
    vf.multiply_by(1.1);
    vf *= 1.1;
    // vf.operator*=(1.1);
    vf();

    auto s = (string)vf;
    cout << s << endl;

    // auto vi = Vector<int>({1, 5, 10});
    // vi[0] = 1;
    // auto k = vi[0];


    // auto v1 = std::vector<int>(3);
    // auto v2 = std::vector<int>{1, 5, 10};
    // cout << v2[0] << endl;
    // cout << v2[2] << endl;

    return 0;
}
