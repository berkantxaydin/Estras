#include <iostream>

typedef char *pstring;
const pstring cstr = 0;
const pstring *ps;

namespace ber = std;

using ber::cout;
using std::endl;

extern const int i = /*function();*/ 0; // accesible from other files

int main(void){
    int i = 0;
    int *const p1 = &i; //top-level const
    const int ci = 42; //top-level const
    const int *p2 =&ci; //low-level const
    const int *const p3 = p2;
    const int &r = ci; //low-level const

    i = ci; // 0 is equal to 42
    p2 = p3; // 42 is equal to p2
    p2 = &i; // p2 is eaqual to 42
    const int &r2 = i; // r2 is equal to 42
    // r2 = ci; // low-level const(const references) not changable
    constexpr int f = 30; // you can use this for verfiying that it's constant.
    void constexpr funct();
    constexpr int *q = nullptr; // pointer itself constant(top-level const)
    const int *p = NULL; // integer object is const. p is pointing to them
    auto summ = i+f;
    cout << "Sum =" << summ << endl;
    cout << typeid(summ).name() << endl;
    decltype(/*funct()*/summ) i = summ;
    const int ci = 0, &cj = ci;
    decltype (ci) x = 0; //has const int
    decltype (cj) y = x; //has const int and bound to x
    cout <<typeid(y).hash_code() <<endl;
    decltype ((i)) l = i; // it should be lvalue
    decltype (*p) e = 0;
}
