#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

// Abstract base class Animal
class Animal {
public:
    virtual std::string get_noise() = 0; // Pure virtual function
    virtual int get_num_legs() = 0; // Pure virtual function
};

#endif          // _ANIMAL_H_