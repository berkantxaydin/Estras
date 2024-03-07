#include "Labyrinth.h"

using std::cout;

bool isPrimeNumber(int num){
    if(num <= 1)
        return false;
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int recursive_sum(int m, int n) {
    if (m == n)
        return m;
    return m + recursive_sum(m+1, n);
}

template<typename V>
void Swap(V& a, V& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

template <class T>
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