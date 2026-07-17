#include <iostream>

using namespace std;

void swap_pointers(int* ptr1, int* ptr2);

int main()
{
    int i {5};
    int j {10};

    cout << "Before swap:" << endl;
    cout << "\t- Value of i: " << i << endl;
    cout << "\t- Value of j: " << j << endl;

    swap_pointers(&i, &j);

    cout << "After swap:" << endl;
    cout << "\t- Value of i: " << i << endl;
    cout << "\t- Value of j: " << j << endl;

    return 0;
}

void swap_pointers(int* ptr1, int* ptr2)
{
    int temp{};

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    // *ptr1 = *ptr1 + *ptr2;
    // *ptr2 = *ptr1 - *ptr2;
    // *ptr1 = *ptr1 - *ptr2;
}