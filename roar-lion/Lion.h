#ifndef _LION_H_
#define _LION_H_
#include "Animal.h"

// Derived class Lion from Animal
class Lion : public Animal {
public:
    std::string get_noise() override;
    int get_num_legs() override;

};

#endif          // _LION_H_