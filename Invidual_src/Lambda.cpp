#pragma argsused // not warn you when you not used your variable


#include <iostream>
#include <vector>
#include <algorithm>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[]){
  
    // [](int x){
    //     if (x%2 == 0)
    //         std::cout << x << "is even number\n";
    //     else
    //         std::cout << x << "is odd number\n";
    // }

    //[cc](p){fd}; cc = capture close

    int d=3, e=1;

    std::vector<int> v = {1, 4, 3, 2, 5};
    std::for_each(v.begin(), v.end(), [&d, e](int x){
        if (x%d == 0)
            std::cout << x << "is divisible by " <<d<<"\n";
        else
            std::cout << x << "is not divisible by " <<d<<"\n";
        d = 10;
        // e = 9; you can't change e. if you put "=" in [cc] you can't change anything, you need to do [&] for make everything changable
    });
    
    std::cout <<"d="<<d;
    std::cin.get();
    return 0;
}

    // struct 
    // {
    //     void operator() (int x) {
    //         std::cout << x << std::endl;
    //     }
    // }smt;