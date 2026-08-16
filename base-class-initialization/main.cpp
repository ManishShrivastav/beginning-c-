#include <iostream>

using namespace std;

class Base {
    private:
        int value;
    public:
        Base() : value{0} {
            cout << "Base no-args constructor" << endl;
        }
        Base(int x) : value{x} {
            cout << "Base (int) overloaded constructor" << endl;
        }
        ~Base() {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base {
    private:
        int doubled_value;
    public:
        Derived() 
        : Base{}, doubled_value{0} {
            cout << "Derived no-args constructor" << endl;
        }
        Derived(int x) 
            : Base{x}, doubled_value{x * 2} {
                cout << "Derived (int) overloaded constructor" << endl;
        }
        ~Derived() {
            cout << "Derived destructor" << endl;
        }
};

int main() {
    // cout << "=== Base class ==========================" << endl;
    // Base b;
    // cout << endl;
    // Base b {100};

    // Base *p_b {nullptr};
    // p_b = new Base();
    // delete p_b;

    cout << "\n=== Derived class =======================" << endl;
    // Derived d;
    // cout << endl;
    Derived d {1000};

    // Derived *p_d {nullptr};
    // p_d = new Derived();
    // delete p_d;

    cout << "==============================================" << endl;

    return 0;
}