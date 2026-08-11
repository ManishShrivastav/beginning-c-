#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a{"Hello"}; // Overloaded constructor
    Mystring b; // No-args constructor
    b = a; // Copy assignment operator

    b = "This is a test"; // Copy assignment operator (b.operator= is called with a const char* argument, 
                                                        // which is implicitly converted to a Mystring object)

    // Mystring empty; // No-args constructor
    // Mystring larry("Larry"); // Overloaded constructor
    // Mystring stooge{larry}; // Copy constructor

    // empty.display();
    // larry.display();
    // stooge.display();

    return 0;
}