#include <iostream>
#include <iomanip>

void ruler() {
    std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}

int main() {
    int num1 {1234};
    double num2 {1234.5678};
    std::string hello {"Hello"};

    // Default output
    std::cout << "=============== Default output ===============" << std::endl;
    ruler();
    std::cout << num1 
              << num2 
              << hello 
              << std::endl;

    // Defaults - one per line
    std::cout << "\n=============== Defaults - one per line ===============" << std::endl;
    ruler();
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;

    // Set field width to 10
    std::cout << "\n=============== Set field width to 10 for num1 ===============" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1 
                            << num2 
                            << hello 
                            << std::endl;

    // Set field width to 10 for the first two outputs
    std::cout << "\n=============== Set field width to 10 for num1 and num2 ===============" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << hello
              << std::endl;
              
    // Set field width to 10 for all outputs
    std::cout << "\n=============== Set field width to 10 for all outputs ===============" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << std::setw(10) << hello
              << std::endl;
              
    // Set field width to 10 for all outputs and justify left
    std::cout << "\n=============== Set field width to 10 for all outputs and justify left ===============" << std::endl;
    ruler();
    std::cout << std::left;
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;

    // setfill to a dash (this is persistent until changed) then repeat the previous example
    std::cout << "\n=============== Set field width to 10 for all outputs and justify left and setfill to a dash ===============" << std::endl;
    ruler();
    std::cout << std::setfill('-');
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;

    // set width to 10 for all outputs, left justify all and carry the setfill characters
    std::cout << "\n=============== Set field width to 10 for all outputs and justify left and setfill varies ===============" << std::endl;
    ruler();
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1
              << std::setw(10) << std::left << std::setfill('#') << num2
              << std::setw(10) << std::left << std::setfill('-') << hello
              << std::endl;
    
    return 0;
}