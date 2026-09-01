#include <ios>
#include <iostream>
#include <iomanip>

int main() {
    int num {255};

    // Displaying the integer in decimal, hexadecimal, and octal formats
    std::cout << "=======================================" << std::endl;
    std::cout << "Decimal: " << std::dec << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    // Displaying showing the base prefixes for hexadecimal and octal
    std::cout << "\n=======================================" << std::endl;
    std::cout << std::showbase; // Show base prefixes
    std::cout << "Decimal: " << std::dec << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    // Displaying the hex value in uppercase
    std::cout << "\n=======================================" << std::endl;
    std::cout << std::showbase << std::uppercase; // Show uppercase letters only works for hexadecimal
    std::cout << "Decimal: " << std::dec << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    // Displaying the + sign for positive numbers
    std::cout << "\n=======================================" << std::endl;
    std::cout << std::showpos; // Show + sign for positive numbers only works for decimal numbers
    std::cout << "Decimal: " << std::dec << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    // Setting using the set method to display the integer in decimal, hexadecimal, and octal formats
    std::cout.setf(std::ios::showbase | std::ios::uppercase | std::ios::showpos); 

    /*
    NOTE: 
        The | is the bitwise OR operator, and here it's being used to combine multiple std::ios format flags into one value.
    */

    // Setting to defaults
    std::cout << std::resetiosflags(std::ios::basefield | std::ios::showbase | std::ios::showpos | std::ios::uppercase); // Resetting the format flags to their default state

    std::cout << "\n=======================================" << std::endl;
    std::cout << "Enter an integer: " << std::endl;
    std::cin >> num;

    std::cout << "Decimal: " << std::dec << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "Octal: " << std::oct << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    std::cout << std:: endl << std::endl;
    return 0;
}