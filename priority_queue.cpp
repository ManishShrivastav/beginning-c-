#include <iostream>
#include <queue>

class Person {
    private:
        std::string name;
        int age;
    public:
        Person(): name{"Unknown"}, age{0} {}
        Person(std::string name, int age): name{name}, age{age} {}
        bool operator<(const Person& other) const {
            return this->age < other.age; // Compare based on age
        }
        bool operator==(const Person& other) const {
            return (this->name == other.name) && (this->age == other.age); // Compare based on name and age
        }

        friend std::ostream& operator<<(std::ostream& os, const Person& person) {
            os << person.name << ": " << person.age;
            return os;
        }
};

// This displays the priority queue by repeatedly topping 
// and popping the priority queue. It is being passed by
// value so that the original priority queue is not modified.

template <typename T>
void display(std::priority_queue<T> pq) {
    std::cout << "[ ";
    while (!pq.empty()) {
        T element = pq.top();
        pq.pop();
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest 1 ====================================" << std::endl;
    std::priority_queue<int> pq;

    for (int i: {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7}) {
        pq.push(i);
    }

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;
    display(pq);

    pq.pop();
    display(pq);
}

void test2() {
    std::cout << "\nTest 2 ====================================" << std::endl;
    std::priority_queue<Person> pq;

    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});

    display(pq);
}

int main() {
    test1();
    test2();
    return 0;
}