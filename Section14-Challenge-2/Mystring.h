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
        ~Mystring(); // Destructor

        Mystring &operator=(const Mystring &rhs); // Copy assignment
        Mystring &operator=(Mystring &&rhs); // Move assignment

        friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs); // Insertion operator
        friend std::istream &operator>>(std::istream &in, Mystring &rhs);       // Extraction operator

        friend Mystring operator-(const Mystring &obj); // make lowercase
        friend Mystring operator+(const Mystring &lhs, const Mystring &rhs); // concatenation
        friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs); // concatenate and assign
        friend Mystring operator*(const Mystring &lhs, int n); // repeat string n times
        friend Mystring &operator*=(Mystring &lhs, int n); // repeat string in place

        friend bool operator==(const Mystring &lhs, const Mystring &rhs); // equality
        friend bool operator!=(const Mystring &lhs, const Mystring &rhs); // inequality
        friend bool operator<(const Mystring &lhs, const Mystring &rhs); // less than
        friend bool operator>(const Mystring &lhs, const Mystring &rhs); // greater than

        friend Mystring &operator++(Mystring &obj); // pre-increment - make uppercase
        friend Mystring operator++(Mystring &obj, int); // post-increment - make uppercase
        friend Mystring &operator--(Mystring &obj); // pre-decrement - make lowercase
        friend Mystring operator--(Mystring &obj, int); // post-decrement - make lowercase

        void display() const; // Display method
        int get_length() const; // Getter method for length of string
        const char *get_str() const; // Getter method for string
};
#endif // _MYSTRING_H_