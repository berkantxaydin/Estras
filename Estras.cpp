#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <list>

namespace ber = std;

using ber::cin;
using ber::cout;

template <typename T>
class Calculator{
public:
    T add(T a, T b){
        return a + b;
    }
    T subtract(T a, T b){
        return a - b;
    }
    T multiply(T a, T b){
        return a * b;
    }
    T divide(T a, T b){
        if(b == 0){
            cout << "Error: Division by zero!";
            return 0;
        }
        return a / b;
    }
};

int main(void){
    IlluminCat* s1 = new Cats("Berk", 1, 1);
    IlluminCat* s2 = new Persons("Berk", 1, 1);

    s1->smt();
    s2->smt();

    Calculator<int> intCalculator;
    cout << intCalculator.add(12,32);
    
    std::cin.get();
    return 0;
}
