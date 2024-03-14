#include <iostream>
#include "temp.h"


using namespace std;

int main(void){
    InterestCalculator calc("Berkant", 1000.0, .05);
    calc.display();
    cout << "The interest rate is: " << calc.interestRate() << endl;

    cin.get();
    return 0;
}
