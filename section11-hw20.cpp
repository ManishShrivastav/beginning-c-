/*
Problem Title: Sum of Digits using Recursion

Problem Description:

Write a C++ program to find the sum of digits of a number using recursion.

You need to implement the function int sum_of_digits(int n) that takes an integer n as an argument and returns the sum of its digits.

Function Signature:

int sum_of_digits(int n)

Input:

    An integer

Output:

    Return the sum of the digits of n.

Example:

Input:

n = 1234

Output:

10

Explanation:

The sum of digits of 1234 is 1 + 2 + 3 + 4 = 10.
*/

#include <iostream>

using namespace std;

int sum_of_digits(int n);

int main()
{
    int n {1234};
    cout << "The sum of digits " << n << " is " << sum_of_digits(n) << endl;

    return 0;
}

int sum_of_digits(int n)
{
    if (n == 0)
    {
        return 0;;
    }
    return (n % 10 + sum_of_digits(n / 10));
}