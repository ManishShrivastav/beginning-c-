#include <iostream>
#include <fstream>

// File copy using get and put

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

    char ch;
    while (in_file.get(ch)) {  // read a character from the input file
        out_file.put(ch); // write the character to the output file
    }
    
    std::cout << "File copied successfully." << std::endl;

    in_file.close(); // close the input file
    out_file.close(); // close the output file

    return 0;
}