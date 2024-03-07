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