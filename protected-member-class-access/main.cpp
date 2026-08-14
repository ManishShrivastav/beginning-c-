#include <iostream>

using namespace std;

class Base {
    // Note friends of base have access to (all) public, protected or private members of base
    public:
        int a {0};
        void display() {
            cout << a << ", " << b << ", " << c << endl;
        }
    protected:
        int b {0};
    private:
        int c {0};
};

class Derived : public Base {
    // Note friends of derived have access to only public and protected members of base (not private members of base)

    // a will be public in derived, 
    // b will be protected in derived, 
    // c will not be accessible in derived

    public:
        void access_base_members() {
            a = 100; // OK: a is public in base
            b = 200; // OK: b is protected in base
            // c = 300; // Compiler Error: c is private in base
            cout << a << ", " << b << endl;
            // cout << c << endl; // Compiler Error: 'c' is private in 'Base'
        }
};

int main() {
    cout << "=== Base member access from base objects ====================" << endl;
    Base base;
    base.a = 100; // OK: a is public
    // base.b = 200; // Compiler Error: b is protected
    // base.c = 300; // Compiler Error: c is private

    cout << "=== Base member access from derived objects ====================" << endl;
    Derived derived;
    derived.a = 100; // OK: a is public in derived
    // derived.b = 200; // Compiler Error: b is protected in derived
    // derived.c = 300; // Compiler Error: c is private in base
    
    return 0;
}