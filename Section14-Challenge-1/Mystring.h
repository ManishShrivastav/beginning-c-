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

        Mystring operator-() const; // make lowercase
        Mystring operator+(const Mystring &rhs) const; // concatenation
        Mystring &operator+=(const Mystring &rhs); // concatenate and assign
        Mystring operator*(int n) const; // repeat string n times
        Mystring &operator*=(int n); // repeat string in place

        bool operator==(const Mystring &rhs) const; // equality
        bool operator!=(const Mystring &rhs) const; // inequality
        bool operator<(const Mystring &rhs) const; // less than
        bool operator>(const Mystring &rhs) const; // greater than

        Mystring &operator++(); // pre-increment
        Mystring operator++(int); // post-increment
        Mystring &operator--(); // pre-decrement
        Mystring operator--(int); // post-decrement

        void display() const; // Display method
        int get_length() const; // Getter method for length of string
        const char *get_str() const; // Getter method for string
};
#endif // _MYSTRING_H_