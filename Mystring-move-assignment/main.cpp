#include <iostream>
#include <vector>
#include "Mystring.h"


using namespace std;

int main() {
    Mystring a{"Hello"}; // Overloaded constructor
    a = Mystring{"Hola"}; // Move assignment
    a = "Bonjour"; // Move assignment

    Mystring empty; // No-args constructor
    Mystring larry("Larry"); // Overloaded constructor
    Mystring stooge{larry}; // Copy constructor
    Mystring stooges; // No-args constructor

    empty = stooge; // Copy assignment
    empty = "Funny"; // Move assignment


    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    return 0;
}