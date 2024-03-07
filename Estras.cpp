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
    IlluminCat* s1 = new Cats("Berk", 1, 1);
    IlluminCat* s2 = new Persons("Berk", 1, 1);

    s1->smt();
    s2->smt();
    
    //Generic Class
    Calculator<int> intCalculator;
    cout << intCalculator.add(12,32);
    
    //Friend Functions
    EquilateralTriangle et;
    et.setA(4);
    FriendClass h;

    h.PrintResults(et);

    std::cin.get();
    return 0;
}
