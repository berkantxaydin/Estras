#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(void){
    string n1;//Default initialization
    string n2 (n1);
    string n2 = n1;
    string n3 ("Value");
    string n3 = "Value";
    string n4 (5, 'c'); // 5 times 'c'
    string readMe;//Operations
    while(cin >> readMe)
        cout << readMe << endl;
    while(getline(cin,readMe))
        cout << readMe << endl;
            if (!readMe.empty())
                {cout<<"The string is:" << endl
                     << readMe << endl;
                 auto len = readMe.size();
                 cout <<"Length of this string = "<<len <<endl;
                }
            else
                cout <<"The string is empty"<<endl;
        int punct_count = 0;
        for(auto ch : readMe){
            cout << ch << endl;
            if(ispunct(ch))
            ++punct_count;
            cout << "Number of punction characters in " << readMe
                 << "= " <<punct_count;
        }
        for(auto &ch :readMe)
            ch = toupper (ch);
        for(int i = 0; i != readMe.size() && !isspace(readMe[i]); i++)
            readMe = toupper(readMe[i]);
cout << "Converted string = " <<readMe;
return 0;
}