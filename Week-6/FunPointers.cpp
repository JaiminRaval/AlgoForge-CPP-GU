#include <iostream>
using namespace std;

int main()
{
    // declare variables
    int varOne = 7;
    int varTwo = 15;
    int varThree = 27;

    // pointer
    int* varOnePtr;
    // assign value
    varOnePtr = &varOne;


    // Prints address of var1
    cout << "Address of var1: "<< &varOne << endl;
    cout << "Address stored in ptrvar1: "<< varOnePtr << endl;

    // Prints address of var2
    cout << "Address of var2: " << &varTwo << endl;

    // Prints address of var3
    cout << "Address of var3: " << &varThree << endl;


//  65, 58


}
