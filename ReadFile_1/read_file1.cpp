#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");
    if(!in_file) {
        std::cerr << "Problem opening file test.txt";
        return 1;
    }

    in_file >> line >> num >> total;            // read a line from the file

    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;

    in_file.close(); // close the file

    return 0;
}