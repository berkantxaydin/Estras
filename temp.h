#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class InterestCalculator{
public:
    InterestCalculator(string name, double principalAmount, double annualInterestRate) {
        Name = name;
        principal = principalAmount;
        rate = annualInterestRate;
    }
    void display(){
        for (int year = 0; year < 10; year++) {
        amount = principal * pow(1 + rate, year);
        cout << setw(5) << year << setw(21) << fixed << setprecision(2) << amount << endl;
        cout << "The amount of money in the account after 10 years is: " << amount << endl;
        }
    }
    float interestRate(){
        return rate;
    }
 
private:
    string Name;
    double amount;
    double principal = 1000.0;
    double rate = .05;
};
