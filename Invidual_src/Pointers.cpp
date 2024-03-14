#include <iostream>
#include <memory>

using namespace std;

void printNumber(int* numberPtr) {
    cout << *numberPtr << endl;
}
void printLetter(char* charPtr) {
    cout << *charPtr << endl;
}
void print(void* ptr, char type) {
    switch ((type))
    {
    case 'i':
        cout << *((int*)ptr)<< endl;break;
    case 'c':
        cout << *((char*)ptr)<< endl;break; 
    default:
        break;
    }
}

//dynamic two-dimensional array
int** create2DArray(int rows, int cols) {
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}

//delete dynamic two-dimensional array
void delete2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = NULL;
}

class MyClass {
    MyClass() {
        cout << "Ctor invoked" << endl;
    }
    ~MyClass() {
        cout << "Ctor invoked" << endl;
    }
};


int add(int a, int b) {
    return a+b;
}


int main()
{
    int number = 5;
    print(&number, 'i');

    char letter = 'A';
    print(&letter, 'c');

    int** array = create2DArray(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = i * 4 + j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
    delete2DArray(array, 3);

    //smart pointers
    unique_ptr<int> unPtr1 = make_unique<int>(5);
    unique_ptr<int> unPtr2 = move(unPtr1); // unPtr1 is NULL now!

    // memory deallocation for smart ptr
    {
        unique_ptr<MyClass>unPtr1 = make_unique<MyClass>();
    }
    
    {
    shared_ptr<MyClass>shPtr1 = make_shared<MyClass>();
    cout<< "Shared count: " <<shPtr1.use_count() << endl;
    {
    shared_ptr<MyClass>shPtr2 = shPtr1;
    cout<< "Shared count: " <<shPtr1.use_count() << endl;
    }
    cout << "Shared cout: " <<shPtr1.use_count() << endl;
    }

    //weak pointers
    weak_ptr<MyClass>wkPtr1;
    {
        shared_ptr<MyClass>shPtr1 = make_shared<MyClass>();
        wkPtr1 = shPtr1;
        if (wkPtr1.expired()) {
            cout << "The object has been deleted." << endl;
        }
        else {
            cout << "The object is still alive." << endl;
        }
    }

    //function pointer
    int(*funcPtr)(int, int) = add;
    cout << add(3, 2) << endl;
    cout << funcPtr(3,2) << endl;


   
    

    cin.get();
}
