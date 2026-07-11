#include <iostream>

using namespace std;

int main()
{
    char selection {};

    do
    {
        cout << "\n-------------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;

        (selection == '1') ? cout << "You chose 1 - Do this\n": 
        (selection == '2') ? cout << "You chose 2 - Do that\n":
        (selection == '3') ? cout << "You chose 3 - Do something else\n":
        (selection == 'Q' || selection == 'q') ? cout << "Goodbye...\n": cout << "Invalid selection -- try again" << endl;
        
        
    } while (selection != 'Q' && selection != 'q');
    
}