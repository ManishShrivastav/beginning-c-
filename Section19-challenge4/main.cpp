// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

bool find_substring(const std::string &str, const std::string &substr) {
    return str.find(substr) != std::string::npos; // check if substring is found in the string
}

int main() {
    std::ifstream in_file {"romeoandjuliet.txt"};
    std::ofstream out_file {"romeoandjuliet_output.txt"};
    
    if(!in_file.is_open()) {
        std::cerr << "Problem opening file romeoandjuliet.txt";
        return 1;
    }

    if(!out_file.is_open()) {
        std::cerr << "Problem opening file romeoandjuliet_output.txt";
        return 1;
    }
    
    std::string line{};
    int line_number{0};
    

    // // This writes each line from the input file to the output file with a line number prefix (even if line is empty)
    // while (std::getline(in_file, line)) {  // read a line from the file
    //     ++line_number; // increment line number
    //     out_file << std::setw(7) << std::left << line_number << line << std::endl; // write line number and line to output file
    // }

    // This writes each line from the input file to the output file with a line number prefix (skipping empty lines)
    while (std::getline(in_file, line)) {  // read a line from the file
        if (line == "") { // check if the line is not empty
            out_file << std::endl; // write an empty line to the output file
        } else {
            ++line_number; // increment line number
            out_file << std::setw(7) << std::left << line_number << line << std::endl; // write line number and line to output file
        }
    }

    std::cout << "Lines have been written to romeoandjuliet_output.txt" << std::endl;

    in_file.close(); // close the input file
    out_file.close(); // close the output file

    return 0;
}

