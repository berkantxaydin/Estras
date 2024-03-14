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
    //params ctor
    IlluminCat(const string& name, int id){
        Name = name;
        Id = id;
    }
    //destructor
    virtual ~IlluminCat() {
        cout << Id + "destructor invoked";

    }
    // IlluminCat(){}//  empty default constructor
    // IlluminCat() {Name = "lala";}// default ctor
    //copy ctor
    IlluminCat(const IlluminCat& original) {
        Name = original.Name;
        Id = original.Id;
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
        std::cout << "circumference = " << et.circumference << std::endl;
        std::cout << "area = " << et.area << std::endl;
    }
};