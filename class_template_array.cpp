#include <iostream>
#include <string>

template <typename T, int N>
class Array {
    int size {N};           // how do we know what N is?  It is not defined anywhere in this code snippet.
    T values[N];          // the N needs to be known at compile time, but it is not defined in this snippet.

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &array) {
        os << "[ ";
        for (const auto &value: array.values) {
            os << value << " ";
        }
        os << "]";
        return os;
    }

    public:
        Array() = default;
        Array(T init_val) {
            for (auto &item: values) {
                item = init_val;
            }
        }

        void fill(T val) {
            for (auto &item: values) {
                item = val;
            }
        }

        int get_size() const { return size; }

        // overload the subscript operator for easy use
        T &operator[](int index) {
            return values[index];
        }
};

int main () {
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << "The contents of nums is: " << nums << std::endl;

    nums.fill(0);
    std::cout << "\nThe size of nums is: " << nums.get_size() << std::endl;
    std::cout << "The contents of nums is: " << nums << std::endl;

    nums.fill(10);
    std::cout << "\nThe size of nums is: " << nums.get_size() << std::endl;
    std::cout << "The contents of nums is: " << nums << std::endl;

    nums[0] = 1000;
    nums[1] = 2000;
    std::cout << "\nThe contents of nums is: " << nums << std::endl;

    Array<int, 100> nums2 {1};
    std::cout << "\nThe size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << "The contents of nums2 is: " << nums2 << std::endl;

    Array<std::string, 10> strings {std::string{"Frank"}};
    std::cout << "\nThe size of strings is: " << strings.get_size() << std::endl;
    std::cout << "The contents of strings is: " << strings << std::endl;

    strings[0] = std::string{"Larry"};
    std::cout << "The contents of strings is: " << strings << std::endl;

    strings.fill(std::string{"X"});
    std::cout << "The contents of strings is: " << strings << std::endl;

    return 0;
}