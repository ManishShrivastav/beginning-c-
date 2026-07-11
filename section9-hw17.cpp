/*
Given a vector of integers, determine how many integers are present before you see the value -99 . 
Note, it's possible -99  is not in the vector! If -99  is not in the vector then the result will 
be equal to the number of elements in the vector.

The final result should be stored in an integer variable named count .

Note that you the different vectors will be tested against your code. You do not need to 
declare the vector of integers. vec  is the name of the vector you should use.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count {};

    vector <int> vec{1 , 5 , 6, -9, 10, -12, 85};

    int i {};
    while (i < vec.size() && vec.at(i) != -99)
    {
        count++;
        i++;
    }

    cout << count << endl;
    
    return 0;
}