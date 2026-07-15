/*
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 


If the user enters the string, "12345", then your program should display:

 

    1                                                                                                                  
   121                                                                                                                 
  12321                                                                                                                
 1234321                                                                                                               
123454321


*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letters {};

    cout << "Enter a string of letters so I can create a Letter Pyramid form it: ";
    getline(cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    for (char c : letters)
    {
        size_t num_spaces = num_letters - position;

        while (num_spaces > 0)
        {
            cout << " ";
            --num_spaces;
        }

        for (size_t j = 0; j < position; j++)
        {
            cout << letters.at(j);
        }

        cout << c;

        for (int j = position - 1; j >= 0; --j)
        {
            auto k = static_cast<size_t>(j);
            cout << letters.at(k);
        }

        cout << endl;
        ++position;
    }

    return 0;
}