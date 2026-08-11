#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
    private:
        char *str; // pointer to a char[] that holds a C-style string

    public:
        Mystring(); // No-args constructor
        Mystring(const char *s); // Overloaded constructor
        Mystring(const Mystring &source); // Copy constructor
        ~Mystring(); // Destructor

        Mystring &operator=(const Mystring &rhs); // Copy assignment operator

        void display() const; // Display method
        int get_length() const; // Getter method for length of string
        const char *get_str() const; // Getter method for string (We return a pointer to the string, 
                                                                    // so we can use it in other functions)
};

#endif // _MYSTRING_H_