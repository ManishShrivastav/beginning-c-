/*
In this exercise you will create a program that will be used to automatically print a grocery list. 
Most weeks the grocery list is the same and so you may begin by declaring the function prototype 
print_grocery_list which has the default argument values:

mangos = 13

apples = 3

oranges = 7

The function print_grocery_list has no return statement and so the return type of the function prototype should be void.
*/

#include <iostream>

using namespace std;

// Prototype
void print_grocery_list(int apples = 3, int mangoes = 13, int oranges = 7);

void modify_grocery_list ()
{
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7, 11);
}

int main ()
{
    modify_grocery_list();

    return 0;
}

void print_grocery_list(int apples, int mangoes, int oranges)
{
    cout << apples << " apples" << "\n" << mangoes << " mangoes" << "\n" << oranges << " oranges" << "\n";
}