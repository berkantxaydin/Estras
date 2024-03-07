#pragma once
#include "SubClasses.h"

using std::string;

class IlluminCat {
private:
    string Name;
    int Id;
protected:
public:
    virtual void smt() = 0; //pure virtual function
    IlluminCat(const string& name, int id){
        Name = name;
        Id = id;
    }
};

class EquilateralTriangle {
private:
    float a;
    float circumference;
    float area;
public:
    void setA(float length){
        a = length;
        circumference = a*3;
        area = (1.73 * a * a) / 4;
    }

    // friend void PrintResults(EquilateralTriangle et);
    friend class FriendClass;
};

class FriendClass {
public:
    void PrintResults(EquilateralTriangle et){
        cout << "circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};

//Functions.cpp
bool isPrimeNumber(int num);

int recursive_sum(int m, int n);

template<typename V>
void Swap(V& a, V& b);

template <class T>
class Calculator{
public:
    T add(T a, T b);
    T subtract(T a, T b);
    T multiply(T a, T b);
    T divide(T a, T b);
};