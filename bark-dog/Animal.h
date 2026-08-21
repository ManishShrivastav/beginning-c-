#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

// Abstract base class animal
class Animal {
private:
    std::string name;
    int age;
public:
    Animal() = default; // Default constructor
    Animal(const std::string& name, int age) : name(name), age(age) {} // Parameterized constructor

    virtual std::string get_noise() = 0; // Pure virtual function

    virtual int get_num_legs() = 0; // Pure virtual function

    virtual std::string get_name() { return name; } // Getter for name

    virtual int get_age() { return age; } // Getter for age
};

#endif          // _ANIMAL_H_