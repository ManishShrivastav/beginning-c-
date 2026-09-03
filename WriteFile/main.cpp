#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream out_file {"output.txt", std::ios::app}; // create and open a file for writing

    if(!out_file) {
        std::cerr << "Problem creating file output.txt";
        return 1;
    }
    
    std::string line;
    std::cout << "Enter lines of text (type 'exit' to quit):" << std::endl;
    while (true) {
        std::getline(std::cin, line); // read a line from standard input
        if (line == "exit") {
            break; // exit the loop if the user types 'exit'
        }
        out_file << line << std::endl; // write the line to the file
    }

    out_file.close(); // close the file

    return 0;
}