#include <iostream>

using namespace std;

int main()
{
    int num1 {10};      // This is not assignment, it's initialization. Initialization 
                        // happens when a variable is declared and it gets the value for very first time.
                        // Assignmen is when you change that value in the variable
    int num2 {20};

    num1 = 100;        // Assign 100 to num1 variable.

    cout << "num1 is: " <<num1 << endl;
    cout << "num2 is: " <<num2 << endl;

    cout << endl;

    return 0;
}