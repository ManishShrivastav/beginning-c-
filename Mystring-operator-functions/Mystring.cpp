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
    std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str) { // steal the pointer
    source.str = nullptr; // null out the source pointer
    std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    if (str == nullptr) {
        std::cout << "Calling destructor for Mystring: nullptr" << std::endl;
    } else {
        std::cout << "Calling destructor for Mystring: " << str << std::endl;
    }
    delete[] str; // deallocate memory
}


// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;
    if (this == &rhs) // check for self-assignment
        return *this;
    delete[] str; // deallocate current memory
    str = new char[std::strlen(rhs.str) + 1]; // allocate new memory
    std::strcpy(str, rhs.str); // copy the string
    return *this; // return the current object
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) // check for self-assignment
        return *this;
    delete[] str; // deallocate current memory
    str = rhs.str; // steal the pointer
    rhs.str = nullptr; // null out the source pointer
    return *this; // return the current object
}

// Equality operator
// Compare two Mystring objects for equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0); // compare the strings
}

// Make lowercase operator
Mystring operator-(const Mystring &obj) {
    // Create a new Mystring object with the lowercase version of the current string
    char *buff = new char[std::strlen(obj.str) + 1];        // allocate new memory for the lowercase string
    std::strcpy(buff, obj.str);                     // copy the string
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);                // convert each character to lowercase
    }
    Mystring temp{buff};                                // create a new Mystring object with the lowercase string
    delete[] buff;                                         // deallocate the temporary buffer
    return temp;                                           // return the new Mystring object
}

// Concatenate operator
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    // Create a new Mystring object with the concatenated version of the current string and the right-hand side string
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1]; // allocate new memory for the concatenated string
    std::strcpy(buff, lhs.str);                     // copy the current string
    std::strcat(buff, rhs.str);                 // concatenate the right-hand side string
    Mystring temp{buff};                                // create a new Mystring object with the concatenated string
    delete[] buff;                                         // deallocate the temporary buffer
    return temp;                                           // return the new Mystring object
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