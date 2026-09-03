#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in_file {"poem.txt"};
    std::ofstream out_file {"poem_output.txt"};

    if(!in_file) {
        std::cerr << "Problem opening input file";
        return 1;
    }

    if(!out_file) {
        std::cerr << "Problem opening output file";
        return 1;
    }

    std::string line;
    while (std::getline(in_file, line)) {  // read a line from the file
        out_file << line << std::endl;
    }
    
    std::cout << "File copied successfully." << std::endl;

    in_file.close(); // close the input file
    out_file.close(); // close the output file

    return 0;
}