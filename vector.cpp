#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>


class Person {
    private:
        friend std::ostream& operator<<(std::ostream& os, const Person& person);
        std::string name;
        int age;

    public:
        Person() = default;
        Person(std::string name, int age) : name{name}, age{age} {}
        bool operator<(const Person& rhs) const {
            return this->age < rhs.age;
        }
        bool operator==(const Person& rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << ": " << person.age;
    return os;
}

// use for_each and a lambda expression to display vector elements
void display2(const std::vector<int>& vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
    std::cout << "]" << std::endl;
}

// template function to display vector elements
template <typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 =================================================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    
    vec = {2, 4, 5, 6};
    display2(vec);

    std::vector<int> vec1(10, 100);         // 10 elements with value 100
    display(vec1);
    display2(vec1);
}

void test2() {
    std::cout << "\nTest2 =================================================" << std::endl;
    
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    std::cout << "\nVector Size: " << vec.size() << std::endl;
    std::cout <<"Vector max_size: " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity: " << vec.capacity() << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "\nVector Size: " << vec.size() << std::endl;
    std::cout <<"Vector max_size: " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit();        // reduce capacity to size
    display(vec);
    std::cout << "\nVector Size: " << vec.size() << std::endl;
    std::cout <<"Vector max_size: " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity: " << vec.capacity() << std::endl;

    vec.reserve(100);          // increase capacity to 100
    display(vec);
    std::cout << "\nVector Size: " << vec.size() << std::endl;
    std::cout <<"Vector max_size: " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity: " << vec.capacity() << std::endl;
}

void test3() {
    std::cout << "\nTest3 =================================================" << std::endl;
    
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;
    display(vec);
}

void test4() {
    std::cout << "\nTest4 =================================================" << std::endl;
    
    std::vector<Person> stooges;

    Person p1{"Larry", 18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Moe", 25});
    display(stooges);

    stooges.emplace_back("Curly", 30);      // creates the object in place
    display(stooges);
}

void test5() {
    std::cout << "\nTest5 =================================================" << std::endl;
    
    std::vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;

    stooges.pop_back();                 // remove Curly from the back
    display(stooges);
}

void test6() {
    std::cout << "\nTest6 =================================================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear();                       // remove all elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2);      // remove first 2 elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // remove all even numbers
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }
    display(vec);
}

void test7() {
    std::cout << "\nTest7 =================================================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8() {
    std::cout << "\nTest8 =================================================" << std::endl;
    std::vector<int> vec1{1, 21, 3, 40, 12};
    display(vec1);

    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

void test9() {
    /*
    std::back_inserter() constructs a back-insert iterator that inserts new elements at the end of 
    the container it is applied to. It is used in conjunction with algorithms that generate output, 
    allowing you to append elements to a container without explicitly managing the insertion process.

    There is also a std::front_inserter() that can be used with deques and lists
    Copy one lis to another using an iterator and back_inserter() to insert the elements at the 
    end of the destination container.
    */
    std::cout << "\nTest9 =================================================" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // Copy_if the element is even
    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) { return x % 2 == 0; });
    display(vec1);
    display(vec2);
}

void test10() {
    std::cout << "\nTest10 =================================================" << std::endl;

    // transform over 2 ranges
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};
    std::vector<int> vec3;

    // 1 * 10, 2 * 20, 3 * 30, 4 * 40, 5 * 50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), 
                    std::back_inserter(vec3),
                    [](int x, int y) { return x * y; });
    display(vec1);
    display(vec2);
    display(vec3);
}

// insert vec2 to vec1 before the 5
void test11() {
    std::cout << "\nTest11 =================================================" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2{100, 200, 300, 400};

    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout << "Inserting vec2 before the element: " << *it << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Sorry, 5 not found in vec1." << std::endl;
    }
    display(vec1);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    return 0;
}