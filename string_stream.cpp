#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>


int main() {
    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info}; // create an input string stream from the info

    iss >> name >> num >> total; // extract data from the string stream
    std::cout << std::setw(10) << std::left << name
              << std::setw(5) << num
              << std::setw(10) << total
              << std::endl;

    std::cout << "\n===============================" << std::endl;
    std::ostringstream oss {}; // create an output string stream
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << std::endl;

    std::cout << oss.str() << std::endl; // output the contents of the output string stream

    std::cout << "\n==== Data validation ===========================" << std::endl;
    int value {};
    std::string entry {};
    bool done {false};

    do {
        std::cout << "Enter an integer value: ";
        std::cin >> entry;
        std::istringstream validator {entry}; // create an input string stream from the entry
        if (validator >> value) { // try to extract an integer from the string stream
            done = true; // if successful, set done to true
        } else {
            std::cerr << "Sorry, that's not a valid integer." << std::endl;
        }

        // Discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
    }while (!done); // repeat until a valid integer is entered

    std::cout << "You entered the integer: " << value << std::endl;

    std::cout << std::endl;
    
    return 0;
}