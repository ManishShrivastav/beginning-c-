/*
Declare a vector of integers named vec  and initialize the vector to 10,20,30,40, and 50 

Modify the first element of the vector to be 100  and modify the last element of the vector to be 1000 .

The final vector should then be 100, 20, 30, 40, and 1000.
*/


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declare and initialize the vector
    vector<int> vec {10, 20, 30, 40, 50};

    // Modify the first element to be 100
    vec[0] = 100;

    // Modify the last element to be 1000
    vec[vec.size() - 1] = 1000;

    // Output the final vector
    cout << "The final vector is: " << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << ", and " << vec[4];
    cout << endl;

    return 0;
}