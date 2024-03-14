#include <iostream>
#include "Labyrinth.h"

using std::string;

class Cats:public IlluminCat{
private:
    int Gender;
protected:
public:
    void smt(){
        std::cout<<"Cat";
    }
    Cats(const string& name, int id, int gender) : IlluminCat(name, id), Gender(gender){}
    int getGender(){
        return Gender;
    }
    void setGender(int gender){
        Gender = gender;
    }
};
class Persons:public IlluminCat{
private:
    int Age;
protected:
public:
    void smt(){
        std::cout<<"Human";
    }
    Persons(const string& name, int id, int age) : IlluminCat(name, id), Age(age){};
    int getAge(){
        return Age;
    }
    void setAge(int age){
        Age = age;
    }
};