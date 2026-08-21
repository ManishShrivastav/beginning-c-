#include <iostream>
#include <memory>


class Base {
    public:
        void say_hello() const {
            std::cout << "Hello - I'm a Base class object!" << std::endl;
        }
};

class Derived : public Base {
    public:
        void say_hello() const {
            std::cout << "Hello - I'm a Derived class object!" << std::endl;
        }
};

void greetings(const Base& obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greetings(b);
    greetings(d);

    Base* base_ptr = new Derived();
    base_ptr->say_hello();
    greetings(*base_ptr);

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();
    greetings(*ptr1);

    delete base_ptr;


    return 0;
}