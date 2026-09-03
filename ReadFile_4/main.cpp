#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;

    in_file.open("poem.txt");
    if(!in_file) {
        std::cerr << "Problem opening file poem.txt";
        return 1;
    }

    char ch;
    while (in_file.get(ch)) {  // read a character from the file
        std::cout << ch;
    }
    
    in_file.close(); // close the file

    return 0;
}