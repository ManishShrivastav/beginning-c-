#include <cstring>
#include <iostream>
#include "Mystring.h"


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

// Insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// Extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000]; // temporary buffer
    in >> buff; // read input into buffer
    rhs = Mystring{buff}; // use move assignment to set rhs
    delete[] buff; // deallocate buffer
    return in;
}