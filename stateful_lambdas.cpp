#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};

// Capture by value
// The global variable global_x cannot be captured because it is not within 
// the reaching scope of the lambda. However, it can still be accessed from within the lambda
// using normal lookup rules.

void test1() {
    std::cout << "\n====Test 1======================================" << std::endl;

    int local_x {100};

    auto l = [local_x] () {
        std::cout << "local_x: " << local_x << std::endl;
        std::cout << "global_x: " << global_x << std::endl;
    };
    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by using the mutable keyword.
// Note that this modifiability only pertains to the captured variable within the lambda body and 
// not the actual variable in the outer scope.
void test2() {
    std::cout << "\n====Test 2======================================" << std::endl;

    int x {100};
    
    std::cout << "x before lambda call: " << x << std::endl;

    auto l = [x] () mutable {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };
    l();
    std::cout << "x after lambda call: " << x << std::endl; // x remains unchanged

    l();
    std::cout << "x after second lambda call: " << x << std::endl; // x remains unchanged
}

// Capture by reference
// Any changes made to the captured variable within the lambda will affect the original variable in the outer scope.
void test3() {
    std::cout << "\n====Test 3======================================" << std::endl;

    int x {100};
    std::cout << "x before lambda call: " << x << std::endl;

    auto l = [&x] () {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };
    l();
    std::cout << "x after lambda call: " << x << std::endl; // x is now 200
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value. 
// The variable z is not captured by the lambda because it is not used 
// within the lambda body.
void test4() {
    std::cout << "\n====Test 4======================================" << std::endl;

    int x {100};
    int y {200};
    int z {300};        // NOTE: z is not used in the lambda body, so it will not be captured. 
                        // This should produce an 'unused variable' warning when compiled with -Wall.

    std::cout << "x before lambda call: " << x << std::endl;
    std::cout << "y before lambda call: " << y << std::endl;
    std::cout << "z before lambda call: " << z << std::endl;

    auto l = [=] () mutable {
        x += 100; // x is captured by value
        y += 100; // y is captured by value
        // z is not captured because it is not used in the lambda body
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    };

    std::cout << "\n";
    l();

    std::cout << "\n";
    std::cout << "x after lambda call: " << x << std::endl; // x remains unchanged
    std::cout << "y after lambda call: " << y << std::endl; // y remains unchanged
    std::cout << "z after lambda call: " << z << std::endl; // z remains unchanged
}

// Default capture by reference
// This time because all three variables -x, y, z are used within 
// the lambda body, they will all be captured by reference.
void test5() {
    std::cout << "\n====Test 5======================================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    std::cout << "x before lambda call: " << x << std::endl;
    std::cout << "y before lambda call: " << y << std::endl;
    std::cout << "z before lambda call: " << z << std::endl;

    auto l = [&] () {
        x += 100; // x is captured by reference
        y += 100; // y is captured by reference
        z += 100; // z is captured by reference
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    std::cout << "\n";
    l();

    std::cout << "\n";
    std::cout << "x after lambda call: " << x << std::endl; // x is now 200
    std::cout << "y after lambda call: " << y << std::endl; // y is now 300
    std::cout << "z after lambda call: " << z << std::endl; // z is now 400
}

// Default capture by value, and capture y byreference
void test6() {
    std::cout << "\n====Test 6======================================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    std::cout << "x before lambda call: " << x << std::endl;
    std::cout << "y before lambda call: " << y << std::endl;
    std::cout << "z before lambda call: " << z << std::endl;

    auto l = [=, &y] () mutable {
        x += 100; // x is captured by value
        y += 100; // y is captured by reference
        z += 100; // z is captured by value
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    std::cout << "\n";
    l();

    std::cout << "\n";
    std::cout << "x after lambda call: " << x << std::endl; // x remains unchanged
    std::cout << "y after lambda call: " << y << std::endl; // y is now 300
    std::cout << "z after lambda call: " << z << std::endl; // z remains unchanged
}

// Default capture by reference, and capture x and z by value
// Equivalent to test 6.
void test7() {
    std::cout << "\n====Test 7======================================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    std::cout << "x before lambda call: " << x << std::endl;
    std::cout << "y before lambda call: " << y << std::endl;
    std::cout << "z before lambda call: " << z << std::endl;

    auto l = [&, x, z] () mutable {
        x += 100; // x is captured by value
        y += 100; // y is captured by reference
        z += 100; // z is captured by value
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    std::cout << "\n";
    l();

    std::cout << "\n";
    std::cout << "x after lambda call: " << x << std::endl; // x remains unchanged
    std::cout << "y after lambda call: " << y << std::endl; // y is now 300
    std::cout << "z after lambda call: " << z << std::endl; // z remains unchanged
}

// Used for test 8
class Person {
    private:
        std::string name;
        int age;
    public:
        Person() = default;
        Person(std::string name, int age) : name{name}, age{age} {}
        Person(const Person& p) = default;
        ~Person() = default;
        std::string get_name() const { return name; }
        void set_name(std::string name) { this->name = name; }
        int get_age() const { return age; }
        void set_age(int age) { this->age = age; }

        friend std::ostream& operator<<(std::ostream& os, const Person& p);

        auto change_person1() {return [this] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
        auto change_person2() {return [=] (std::string new_name, int new_age) mutable {name = new_name; age = new_age;};}
        auto change_person3() {return [&] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "[Person: " << p.name << ", Age: " << p.age << "]";
    return os;
}

// Default capture by reference of the current object using [this], [=], [&], and [this] 
// are equivalent when capturing an object's member variables - all are captured by reference. 
// NOTE that capturing this with [=] has been deprecated in C++20. Also, C++20 allows [*this] to capture the current object by value.
void test8() {
    std::cout << "\n====Test 8======================================" << std::endl;

    Person person("Larry", 18);

    std::cout << "person before lambda call: " << person << std::endl;

    // Default capture [this]. This is the preferred way to capture the current object in C++20 and later.
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << "person after lambda call: " << person << std::endl; // person is now Moe, 30

    // Default capture by value [=]. This is deprecated in C++20 and later.
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << "person after lambda call: " << person << std::endl; // person is Curly, 25

    // Default capture by reference [&]. This is equivalent to [this].
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << "person after lambda call: " << person << std::endl;
}

// Used for test 9
class Lambda {
    private:
        int y;
    public:
        Lambda(int y) : y{y} {};

        void operator()(int x) {
            std::cout << "x + y: " << x + y << std::endl;
        };        
};

// Lambda class equivalence example
void test9() {
    std::cout << "\n====Test 9======================================" << std::endl;

    int y {100};

    Lambda lambda1(y);
    auto lambda2 = [y] (int x) { std::cout << "x + y: " << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

// Class used for test 10
class People {
    private:
        std::vector<Person> people;
        int max_people;
    public:
        People(int max=10): max_people{max} {}
        People(const People& p) = default;
        void add(std::string name, int age) {
            people.emplace_back(name, age);
        }
        void set_max_people(int max) {
            max_people = max;
        }
        int get_max_people() const {
            return max_people;
        }

        // This method returns a vector of Person objects in people 
        // whose age > max_age AND it limits the number of persons returned 
        // to be <= the member variable max_people. NOTE that the lambda in 
        // this example captures this, by reference and by value.
        std::vector<Person> get_people(int max_age) {
            std::vector<Person> result;
            int count {0};
            std::copy_if(people.begin(), people.end(), std::back_inserter(result), 
                [this, &count, max_age] (const Person& p) { return p.get_age() > max_age && ++count <= max_people; });

            return result;
        }
};

void test10() {
    std::cout << "\n====Test 10======================================" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    
    auto result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    friends.set_max_people(3);

    result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    result = friends.get_people(50);

    std::cout << std::endl;
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }
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
    return 0;
}