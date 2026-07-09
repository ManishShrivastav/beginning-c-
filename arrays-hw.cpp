/*
Declaring, Initializing and Accessing an Array
Instructions
Declare an array of 10  integers named arr  and initialize the array so that all 10 integers are 0 .

Then assign 100  to the first element of the array and 1000  to the last element of the array.
*/

#include <iostream>

using namespace std;

int main()
{
    int arr[10] {0}; // Declare and initialize an array of 10 integers to 0

    cout << "Initial array values: \n";
    
    cout << "First element: " << arr[0] << endl; // Output the first element
    cout << "Last element: " << arr[9] << endl;   // Output the last element

    arr[0] = 100;    // Assign 100 to the first element
    arr[9] = 1000;   // Assign 1000 to the last element

    cout << "\nUpdated array values: \n";
    cout << "First element: " << arr[0] << endl; // Output the first element
    cout << "Last element: " << arr[9] << endl;   // Output the last element
    return 0;
}