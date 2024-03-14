#include "Labyrinth.h"
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

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

bool ascendingCompare (int a, int b) {
    return a < b;
}
bool descendingCompare (int a, int b) {
    return a > b;
}

//custom sort
void customSort(vector<int>& arr, bool (*compare)(int, int)) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (compare(arr[i], arr[j])) {
                Swap(arr[i], arr[j]);
            }
        }
    }
}
//bool (*funcPtr)(int, int) = ascendingCompare; costomSort(myArr, funcPtr);

void getMinAndMax(vector<int>& arr, int* min, int* max) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}

//some basic generics
template<typename T>
T square(T x) {
    return x * x;
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
        return operator-(a, b);
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

template <typename T>
bool equal(T a, T b){
    return (a==b);
}
//template specialization
template<>
bool equal<float>(float a, float b){
    cout << "equal<float>\n";
    return fabs(a - b) < 0.00001f;
}
template<>
bool equal<double>(double a, double b){
    cout << "equal<double>\n";
    return abs(a - b) < 0.0000001;
}