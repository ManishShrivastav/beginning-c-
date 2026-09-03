#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;

    in_file.open("poem.txt");
    if(!in_file) {
        std::cerr << "Problem opening file poem.txt";
        return 1;
    }

    std::string line;
    while (std::getline(in_file, line)) {  // read a line from the file
        std::cout << line << std::endl;
    }
    
    in_file.close(); // close the file

    return 0;
}