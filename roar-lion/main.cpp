#include <iostream>
#include <string>
#include "Lion.h"

int main() {
    std::cout << "========= Objects =========" << std::endl;
    Lion lion;
    std::string roar = lion.get_noise();
    int num_legs = lion.get_num_legs();
    std::cout << "Lion noise: " << roar << std::endl;
    std::cout << "Lion number of legs: " << num_legs << std::endl;

    std::cout << "\n========= Pointers =========" << std::endl;
    Lion* lion_ptr = new Lion();
    std::string roar_ptr = lion_ptr->get_noise();
    int num_legs_ptr = lion_ptr->get_num_legs();
    std::cout << "Lion noise (pointer): " << roar_ptr << std::endl;
    std::cout << "Lion number of legs (pointer): " << num_legs_ptr << std::endl;
    delete lion_ptr;

    std::cout << "\n========= Animal Pointers =========" << std::endl;
    Animal* animal_ptr = new Lion();
    std::string roar_animal_ptr = animal_ptr->get_noise();
    int num_legs_animal_ptr = animal_ptr->get_num_legs();
    std::cout << "Lion noise (Animal pointer): " << roar_animal_ptr << std::endl;
    std::cout << "Lion number of legs (Animal pointer): " << num_legs_animal_ptr << std::endl;
    // delete animal_ptr;       // Gives a warning because Animal is an abstract class and cannot be instantiated directly. 
                                // However, we can still delete the pointer to the derived class object (Lion) through the 
                                // base class pointer (Animal). This is safe because Lion has a virtual destructor 
                                // (inherited from Animal), ensuring proper cleanup of resources.

    return 0;
}
