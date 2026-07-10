/*
In this exercise you will create a program that determines the eligibility of an individual applying for a job as a delivery driver. 

In order for the individual to be eligible, they must be 18  years of age or older, or be above the age of  15  and have their parents 
consent to work. Additionally they must possess a valid social security number and have no driving accidents.

Let the variable age  represent the individual's age, and the boolean variables parental_consent  represent parental consent, ssn  
represent a valid social security number, and accidents   represent whether they have had any car accidents.
*/

#include <iostream>
using namespace std;

void logical_operators(int age, bool parental_consent, bool ssn, bool accidents) 
{
    
    if ((age >= 18 || (age >= 16 && parental_consent)) && ssn && !accidents)
    {
        cout << "Yes, you can work.";
    }
}

int main()
{
    cout << "Enter your age: ";
    int age {};
    cin >> age;

    cin >> boolalpha;
    bool parental_consent {false};
    bool ssn {false};
    bool accidents {false};

    cout << "Do you have parental consent (true/false)? ";
    cin >> parental_consent;
    
    cout << "Do you have valid ssn (true/false)? ";
    cin >> ssn;
    
    cout << "Do you have accident history (true/false)? ";
    cin >> accidents;
    
    cout << endl;

    logical_operators(age, parental_consent, ssn, accidents);

    return 0;
}