// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>

bool find_substring(const std::string &str, const std::string &substr) {
    return str.find(substr) != std::string::npos; // check if substring is found in the string
}

int main() {
    std::ifstream in_file;
    std::string word_to_find {};
    std::string word_read {};
    int word_count {0};
    int match_count {0};
    in_file.open("romeoandjuliet.txt");
    if(!in_file) {
        std::cerr << "Problem opening file romeoandjuliet.txt";
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> word_to_find;

    while (in_file >> word_read) {  // read a word from the file
        ++word_count; // increment total word count
        if (find_substring(word_read, word_to_find)) { // check if the substring is found
            ++match_count; // increment match count if substring is found
        }
    }

    std::cout << "Total words read: " << word_count << std::endl;
    std::cout << "The substring \"" << word_to_find << "\" was found " << match_count << " times." << std::endl;

    return 0;
}

