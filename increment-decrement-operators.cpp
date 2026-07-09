/*
Increment Operator      ++
Decrement Operator      --

Increments or decrements its operand by 1
Can be used with integers, floating point types and pointers

prefix      ++num
Postfix     num++

Don't overuse this Operator!
ALERT!!! Never use it twice for the same variables in the same statement!!
*/

#include <iostream>

using namespace std;

int main()
{
    int counter {10};
    int result {0};


    // Example 1 - simple increment
    cout << "Example 1" << endl;
    cout <<"Counter: " << counter << endl;

    counter = counter + 1;
    cout <<"Counter: " << counter << endl;

    counter++;
    cout <<"Counter: " << counter << endl;

    ++counter;
    cout <<"Counter: " << counter << endl;

    // Example 2 - Pre-increment
    cout << "\nExample 2" << endl;
    counter = 10;
    result = 0;
    cout <<"Counter: " << counter << endl;

    result = ++counter;     // Note the pre-increment
    cout <<"Counter: " << counter << endl;
    cout <<"Result: " << result << endl;

    // Example 3 - Post-increment
    cout << "\nExample 3" << endl;
    counter = 10;
    result = 0;
    cout <<"Counter: " << counter << endl;

    result = counter++;     // Note the pre-increment
    cout <<"Counter: " << counter << endl;
    cout <<"Result: " << result << endl;

    // Example 4 
    cout << "\nExample 4" << endl;
    counter = 10;
    result = 0;
    cout <<"Counter: " << counter << endl;

    result = ++counter + 10;     // Note the pre-increment
    cout <<"Counter: " << counter << endl;
    cout <<"Result: " << result << endl;

    // Example 5
    cout << "\nExample 5" << endl;
    counter = 10;
    result = 0;
    cout <<"Counter: " << counter << endl;

    result = counter++ + 10;     // Note the pre-increment
    cout <<"Counter: " << counter << endl;
    cout <<"Result: " << result << endl;

    return 0;
}