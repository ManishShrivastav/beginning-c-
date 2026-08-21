#ifndef _DOG_H_
#define _DOG_H_
#include "Animal.h"

class Dog : public Animal {
public:
    Dog() = default; // Default constructor
    Dog(const std::string& name, int age) : Animal(name, age) {}
    std::string get_noise() override;
    int get_num_legs() override;
};

#endif          // _DOG_H_