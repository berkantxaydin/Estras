#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <list>

namespace ber = std;

using ber::cin;
using ber::cout;
using std::endl;

int main(void){
    //SubClasses
    IlluminCat* s1 = new Cats("Berkant", 01, 0);
    IlluminCat* s2 = new Persons("Miss", 02, 1);

    s1->smt();
    s2->smt();
    
    //Friend Functions
    EquilateralTriangle et;
    et.setA(4);
    FriendClass h;

    h.PrintResults(et);

    std::cin.get();
    return 0;
}
