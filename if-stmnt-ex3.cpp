#include <iostream>
using namespace std;

void can_you_drive(int age) 
{
    
    const int driving_age{16};
    
    if (age >= driving_age)
    {
        cout << "Yes - you can drive!";
    }
        
}

int main()
{
    can_you_drive(18);
    return 0;
}