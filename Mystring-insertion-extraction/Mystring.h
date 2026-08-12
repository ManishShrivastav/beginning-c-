#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iosfwd>

class Mystring {
    private:
        char *str; // pointer to a char[] that holds a C-style string

    public:
        Mystring(); // No-args constructor
        Mystring(const char *s); // Overloaded constructor
        Mystring(const Mystring &source); // Copy constructor
        Mystring(Mystring &&source); // Move constructor

        Mystring &operator=(const Mystring &rhs); // Copy assignment
        Mystring &operator=(Mystring &&rhs); // Move assignment

        ~Mystring(); // Destructor

        friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs); // Insertion operator
        friend std::istream &operator>>(std::istream &in, Mystring &rhs);       // Extraction operator

        void display() const; // Display method
        int get_length() const; // Getter method for length of string
        const char *get_str() const; // Getter method for string
};

#endif // _MYSTRING_H_