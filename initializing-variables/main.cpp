#include <iostream>

using namespace std;

// This program will calculate the area of a room in square feet

int main() 
{
    cout << "Enter the length of the room in feet: ";
    double room_length;
    cin >> room_length;

    cout << "Enter the width of the room in feet: ";
    double room_width;
    cin >> room_width;

    double area = room_length * room_width;
    cout << "The area of the room is " << area << " square feet." << endl;
    return 0;
}