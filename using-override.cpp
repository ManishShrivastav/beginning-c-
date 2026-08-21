#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }

    virtual ~Base() = default; // Virtual destructor
};

class Derived : public Base {
public:
    virtual void say_hello() const override {          // Using 'override' for clarity
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }

    virtual ~Derived() = default; // Virtual destructor
};

int main() {
    Base *p1 = new Base();
    p1->say_hello(); // Calls Base::say_hello

    Derived *p2 = new Derived();
    p2->say_hello();  // Calls Derived::say_hello due to virtual function mechanism

    Base *p3 = new Derived();
    p3->say_hello();  // Calls Derived::say_hello due to virtual function mechanism

    delete p1; // Properly calls Base destructor
    delete p2; // Properly calls Derived destructor followed by Base destructor
    delete p3; // Properly calls Derived destructor followed by Base destructor

    return 0;
}