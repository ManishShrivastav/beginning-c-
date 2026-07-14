#include <iostream>
#include <cstring>          // for c-style string functions
#include <cctype>           // for character classification functions

using namespace std;

int main()
{
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50];

    // cout << first_name;     // will likely display garbage!

    // ==============================================================

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Please enter your last name: ";
    cin >> last_name;
    cout <<"----------------------------------" << endl;

    cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters" << endl;
    cout << "and your last name " << last_name << " has " << strlen(last_name) << " characters" << endl;

    cout << endl;
    
    return 0;
}