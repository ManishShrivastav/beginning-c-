#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct Square_Functor {
    void operator()(const int& value) {
        std::cout << value * value << " ";
    }
};

template <typename T>
struct Displayer {
    void operator()(const T& value) {
        std::cout << value << " ";
    }
};

class Multiplier {
    int num;
public:
    Multiplier(int n) : num{n} {}
    int operator()(int value) {
        return value * num;
    }
};


int main() {
    std::cout << "\nTest1 ====================================" << std::endl;
    Square_Functor square;
    square(5);              // square.operator()(5) displays 25

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);                // d1.operator()(100) displays 100
    d2("Frank");             // d2.operator()("Frank") displays Frank

    std::cout << "\n\nTest2 ====================================" << std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(), vec1.end(), square); // displays 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>()); // displays 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1); // displays 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>()); // displays Larry Moe Curly

    std::for_each(vec2.begin(), vec2.end(), d2); // displays Larry Moe Curly
    std::cout << std::endl;

    std::cout << "\nTest3 ====================================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x << " ";}); // displays 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10 << " ";}); // displays 10 20 30 40 50
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";}); // displays 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), [](const std::string& s) {std::cout << s << " ";}); // displays Larry Moe Curly
    std::cout << std::endl;

    std::cout << "\nTest4 ====================================" << std::endl;
    Multiplier mult{100};
    vec1 = {1, 2, 3, 4};

    // transform changes the vector!
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult); // multiplies each element by 100
    std::for_each(vec1.begin(), vec1.end(), d1);        // displays 100 200 300 400
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {return x * 100;}); // multiplies each element by 100
    std::for_each(vec1.begin(), vec1.end(), d1);        // displays 100 200 300 400
    std::cout << std::endl;

    return 0;
}