/*
In this exercise you will create a program that calculates the total_amount of money that will be accumulated 
if you start with a penny and double it everyday for n number of days. 

For this program, assume that all money will be represented as a double value and so a penny will be represented as 0.01.

Begin by completing the function prototype a_penny_doubled_everyday which is passed an int and a double.

Now that the function prototype is declared, at the bottom of the file define the function.

The function should return the total_amount accumulated after n number of days. For example, if n = 18, the 
function should return 1310.72. The function should be able to calculate the total_amount for any number of 
days starting with any amount however the default amount should be a penny.

Now, from the function body of amount_accumulated, declare and initialize the variable total_amount by calling 
the a_penny_doubled_everyday function for n = 25 days.

*/

#include <iostream>
#include <iomanip>

using namespace std;

double a_penny_doubled_everyday(int, double amount = 0.01);


void amount_accumulated() 
{
    double total_amount = a_penny_doubled_everyday(18);
    cout <<  "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10) << total_amount << endl;;
}

double a_penny_doubled_everyday(int n, double amount) 
{
    
    if (n <= 1)
        return amount;
    return a_penny_doubled_everyday(--n, amount*2);
}


int main()
{
    amount_accumulated();
    return 0;
}
