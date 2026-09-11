#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>


// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i : vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1===========================================" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};
    auto it = nums1.begin();                    // iterator to the first element 1
    std::cout << *it << std::endl;
    
    it++;                                       // point to the next element 2
    std::cout << *it << std::endl;

    it += 2;                                     // point to the next element 4
    std::cout << *it << std::endl;

    it -= 2;                                     // point to the next element 2
    std::cout << *it << std::endl;

    it = nums1.end() - 1;                       // point to the last element 5
    std::cout << *it << std::endl;
}

void test2() {
    std::cout << "\nTest2===========================================" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums1.begin();                    // iterator to the first element 1
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    // Change all vector elements to 0 using iterator
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;
        it++;   
    }
    display(nums1);
}

void test3() {
    std::cout << "\nTest3===========================================" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it1 = nums1.begin();                    // iterator to the first element 1
    // auto it1 = nums1.cbegin();

    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }
    
    // Compiler Error: assignment of read-only location ‘* it1’
    it1 = nums1.begin();
    while (it1 != nums1.end()) {
        // *it1 = 0;   // Compiler Error: assignment of read-only location ‘* it1’
        it1++;
    }
}

void test4() {
    // Using a reverse iterator
    std::cout << "\nTest4===========================================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4};

    auto it1 = vec.rbegin(); // reverse iterator to the last element 4
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // const reverse iterator over a list
    std::list<std::string> names{"Larry", "Moe", "Curly"};
    std::list<std::string>::const_reverse_iterator it2 = names.crbegin();
    std::cout << *it2 << std::endl;
    it2++;                          // point to the next element "Moe"
    std::cout << *it2 << std::endl;

    // iterator over a map of string, string pairs
    std::map<std::string, std::string> favorites{
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };

    auto it3 = favorites.begin();               // iterator over map of string, string pairs
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }

}

void test5() {
    // iterate over a subset of a container using iterators
    std::cout << "\nTest5===========================================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // iterate over a subset of the vector
    auto start = vec.begin() + 2; // point to the 3rd element
    auto end = vec.end() - 3;     // point to the 3rd last element
    while (start != end) {
        std::cout << *start << std::endl;
        start++;
    }
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}