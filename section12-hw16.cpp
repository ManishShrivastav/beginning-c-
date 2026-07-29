/*
Specification:

Write a C++ function reverse_string that takes a std::string as input and returns a new std::string with the characters in reverse order. The function should use pointers to perform the reversal.

Function Signature:

std::string reverse_string(const std::string& str);

Input:

    str: The input string.

Output:

The function should return a new string with the characters of str reversed.

Example:

std::string input = "Hello, World!";
std::string reversed = reverse_string(input);

// reversed should be "!dlroW ,olleH"

*/

#include <iostream>

using namespace std;

string reverse_string(const string &str);

int main()
{
    string str {"Hello World!"};

    reverse_string(str);

    cout << "The reverse of " << str << " is " << reverse_string(str) << endl;

    cout << endl;

    return 0;
}

string reverse_string(const string &str)
{
    string reversed;
    
    const char *start = str.c_str();
    const char *end = str.c_str() + str.size() - 1;

    while (end >= start) {
        reversed.push_back(*end);
        end--;
    }

    return reversed;
}