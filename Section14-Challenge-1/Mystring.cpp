#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    std::cout << "No-args constructor called" << std::endl;
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr} {
    std::cout << "Overloaded constructor called" << std::endl;
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    std::cout << "Copy constructor used" << std::endl;
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str) {
    std::cout << "Move constructor used" << std::endl;
    source.str = nullptr;
}

// Destructor
Mystring::~Mystring() {
    if (str == nullptr) {
        std::cout << "Calling destructor for Mystring: nullptr" << std::endl;
    } else {
        std::cout << "Calling destructor for Mystring: " << str << std::endl;
    }
    delete[] str;
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
    str = rhs.str; // transfer ownership of the resource
    rhs.str = nullptr; // set the moved-from object to a valid state
    return *this; // return the current object
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

// Additional operators for challenge - member function style
// Make lowercase
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenate and assign
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// Repeat string n times
Mystring Mystring::operator*(int n) const {
    // if (n <= 0 || str == nullptr) {
    //     return Mystring{};
    // }

    // size_t len = std::strlen(str);
    // char *buff = new char[(len * static_cast<size_t>(n)) + 1];
    // buff[0] = '\0';

    // for (int i = 0; i < n; ++i) {
    //     std::strcat(buff, str);
    // }

    // Mystring temp{buff};
    // delete[] buff;
    // return temp;

    Mystring temp;
    for (int i = 0; i < n; ++i) {
        temp += *this;
    }
    return temp;
}

// Repeat string in place
Mystring &Mystring::operator*=(int n) {
    Mystring temp = *this * n;
    *this = temp;
    return *this;
}

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Inequality
bool Mystring::operator!=(const Mystring &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

// Less than
bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

// Greater than
bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

// Pre-increment - uppercase letters
Mystring &Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(str); ++i) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// Post-increment - makes the string uppercase but returns the original value
Mystring Mystring::operator++(int) {
    Mystring temp(*this);
    operator++(); // call pre-increment to make the string uppercase
    return temp;
}

// Pre-decrement - lowercase letters
Mystring &Mystring::operator--() {
    for (size_t i = 0; i < std::strlen(str); ++i) {
        str[i] = std::tolower(str[i]);
    }
    return *this;
}

// Post-decrement - makes the string lowercase but returns the original value
Mystring Mystring::operator--(int) {
    Mystring temp(*this);
    operator--(); // call pre-decrement to make the string lowercase
    return temp;
}
