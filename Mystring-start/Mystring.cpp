#include "Mystring.h"
#include <cstring>
#include <iostream>

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0'; // set string to null character
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0'; // set string to null character
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s); // copy the string
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str); // copy the string
}

// Destructor
Mystring::~Mystring() {
    delete[] str; // deallocate memory
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// Getter method for length of string
int Mystring::get_length() const {
    return std::strlen(str);
}

// Getter method for string
const char *Mystring::get_str() const {
    return str;
}   