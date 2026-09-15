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

void test2() {
    std::cout << "\nTest2 ==============================================" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0);       // fill arr1 with 0s
    display(arr1);
    display(arr2);

    arr1.swap(arr2);     // swap the contents of arr1 and arr2
    display(arr1);
    display(arr2);
}

void test3() {
    std::cout << "\nTest3 ==============================================" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};
    
    int *ptr = arr1.data();      // get pointer to the underlying array
    std::cout << "Pointer: " << ptr << std::endl;
    *ptr = 10000;      // change the first element of arr1 using the pointer
    display(arr1);
}

void test4() {
    std::cout << "\nTest4 ==============================================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 4, 5, 3};

    // Use std::sort to sort the array in descending order
    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5() {
    std::cout << "\nTest5 ==============================================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 4, 5, 3};
    
    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());

    std::cout << "Minimum element: " << *min_num << std::endl;
    std::cout << "Maximum element: " << *max_num << std::endl;
}

void test6() {
    std::cout << "\nTest6 ==============================================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 3, 3, 5};
    
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) {
        std::cout << "Adjacent elements found with value: " << *adjacent << std::endl;
    } else {
        std::cout << "No adjacent elements found." << std::endl;
    }
}

void test7() {
    std::cout << "\nTest7 ==============================================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 4, 5, 3};

    // Use std::accumulate to sum the elements of the array
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of elements in arr1 is: " << sum << std::endl;
}

void test8() {
    std::cout << "\nTest8 ==============================================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 1, 2, 3, 3, 3, 3, 3};
    
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Number of occurrences of 3 in arr1 is: " << count << std::endl;
}

void test9() {
    std::cout << "\nTest9 ==============================================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
    
    // find how many numbers are between 10 and 200
    int count = std::count_if(arr1.begin(), arr1.end(), [](int x) { return x > 10 && x < 200; });
    std::cout << "Number of elements between 10 and 200 in arr1 is: " << count << std::endl;
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
    return 0;
}