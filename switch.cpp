/*
As the user what grade they expect on an exam and tell them what they need to score to get it.
*/

#include <iostream>

using namespace std;

int main()
{
    char letter_grade {};

    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch (letter_grade)
    {
    case 'A': case 'a': cout << "You need 90 or higher, study hard!"; break;
    case 'B': case 'b': cout << "You need 80 - 89, go study!"; break;
    case 'C': case 'c': cout << "You need 70 - 79 for an average grade"; break;
    case 'D': case 'd': cout << "Hmm, you should strive for a better grade. All you need is 60 - 69"; break;
    case 'F': case 'f': 
    {
        char confirm {};
        cout << "Are you sure (Y/N)? ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y')
        {
            cout << "OK, I guess you didn't study..." << endl;
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            cout << "Good - go study!" << endl;
        }
        else
        {
            cout << "Illegal choice" << endl;
        }       
        
        break;
    }

    default: cout <<" Sorry, not a valid grade"; break;
    
    }

    cout << endl;

    return 0;
}