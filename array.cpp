#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>      // for more algorithms like accumulate

// Display the array -- note the size MUST be included when passing an std::array to a function
void display(const std::array<int, 5>& arr) {
    std::cout << "[ ";
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 ==============================================" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};        // double {{}} if using C++11
    std::array<int, 5> arr2;                        // uninitialized array

    display(arr1);
    display(arr2);          // uninitialized array will contain garbage values

    arr2 = {10, 20, 30, 40, 50};      // assign values to arr2

    display(arr1);
    display(arr2);

    std::cout << "Size of arr1: " << arr1.size() << std::endl;      // 5
    std::cout << "Size of arr2: " << arr2.size() << std::endl;      // 5

    arr1[0] = 1000;       // change the first element of arr1
    arr1.at(1) = 2000;     // change the second element of arr1
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;      // 10
    std::cout << "Back of arr2: " << arr2.back() << std::endl;        // 50
}

int main() {
    test1();
    return 0;
}