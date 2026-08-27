// Section 18

#include <iostream>

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the number of miles: ";
    std::cin >> miles;
    std::cout << "Enter the number of gallons: ";
    std::cin >> gallons;

    try {
        if (gallons == 0) {
            throw 0;
        }
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Miles per gallon: " << miles_per_gallon << std::endl;
    } 
    catch (int &ex) {
        std::cerr << "Sorry, can't divide by zero: " << ex << std::endl;
    }

    std::cout << "Bye!" << std::endl;

    return 0;
}