#include <iostream>
#include "Dog.h"

int main() {
    std::cout << "=== Dog Object ===" << std::endl;
    Dog dog {"Spot", 5};
    std::cout << dog.get_name() << " says " << dog.get_noise() << std::endl;
    std::cout << dog.get_name() << " has " << dog.get_num_legs() << " legs." << std::endl;
    std::cout << dog.get_name() << " is " << dog.get_age() << " years old." << std::endl;

    std::cout << "\n=== Dog Pointer ===" << std::endl;
    Dog* dog_ptr = new Dog {"Spot", 5};
    std::cout << dog_ptr->get_name() << " says " << dog_ptr->get_noise() << std::endl;
    std::cout << dog_ptr->get_name() << " has " << dog_ptr->get_num_legs() << " legs." << std::endl;
    std::cout << dog_ptr->get_name() << " is " << dog_ptr->get_age() << " years old." << std::endl;

    delete dog_ptr;

    std::cout << "\n=== Animal Pointer ===" << std::endl;
    Animal* animal_ptr = new Dog {"Spot", 5};
    std::cout << animal_ptr->get_name() << " says " << animal_ptr->get_noise() << std::endl;
    std::cout << animal_ptr->get_name() << " has " << animal_ptr->get_num_legs() << " legs." << std::endl;
    std::cout << animal_ptr->get_name() << " is " << animal_ptr->get_age() << " years old." << std::endl;

    // delete animal_ptr;

    return 0;
}