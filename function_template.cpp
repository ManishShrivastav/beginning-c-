#include <iostream>
#include <ostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person& other) const {
        return this->age < other.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name;
    return os;
}

template <typename T>
void my_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x {100};
    int y {200};
    
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    my_swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    Person p1{"Curly", 15};
    Person p2{"Moe", 30};

    Person p3 = min(p1, p2); 
    std::cout << "Younger person: " << p3.name << ", Age: " << p3.age << std::endl;

    func(p1, p2);

    std::cout << "Minimum of 3 and 5: " << min<int>(3, 5) << std::endl;
    std::cout << "Minimum of 3 and 5: " << min(3, 5) << std::endl; // Type deduction
    std::cout << "Minimum of A and B: " << min('A', 'B') << std::endl;
    std::cout << "Minimum of 3.5 and 2.1: " << min(3.5, 2.1) << std::endl;
    std::cout << "Minimum of 5 + 2 * 2 and 7 + 40: " << min(5 + 2 *2, 7 + 40) << std::endl;

    func(10, 20.5);
    func (10, 20);
    func<char, std::string>('A', "Hello");
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string("Frank"));

    return 0;
}