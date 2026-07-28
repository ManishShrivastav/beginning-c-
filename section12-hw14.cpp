/*
Instructions

Exercise: Find Maximum Element

Specification:

Write a C++ function find_max_element that takes an integer array and its size as input and returns the maximum element in the array using pointers.

Function Signature:

int findMaxElement(int* arr, int size);

Input:

    arr: A pointer to the first element of the integer array.

    size: The size of the array.

Output:

The function should return the maximum element in the array.

Example:

int arr[] = {12, 45, 67, 23, 9};
int size = sizeof(arr) / sizeof(arr[0]);

int maxElement = findMaxElement(arr, size);

// maxElement should be 67

Constraints:

    The array will always have at least one element.

    The elements in the array are unique.

*/

#include <iostream>

using namespace std;

int find_max_element(int *arr, int size);

int main()
{
    int array[] {12, 45, 67, 23, 9};
    int size = sizeof(array) / sizeof(array[0]);

    int maxElement = find_max_element(array, size);

    cout << "The max element in array is " << maxElement << endl;
    cout << endl;
    return 0;
}

int find_max_element(int *arr, int size)
{
    int largest = *arr;

    for (int i{}; i < size; i++) 
    {
        if (largest < *(arr + i)) 
        {
            largest = *(arr + i);
        }
    }

    return largest;
}