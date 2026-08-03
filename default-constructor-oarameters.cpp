// Section 13
// Default Constructor Parameters
// Demonstrates how default parameters can be used in constructors to reduce the number of overloaded constructors.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name {"XXXXXXX"};
   int health;
   int xp;
public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
};

// Player::Player() 
//     : Player{"None", 0, 0} {
//         cout << "No-args constructor called" << endl;
// }

// Player::Player(std::string name_val) 
//    : Player{name_val, 0, 0} {
//         cout << "Single-arg constructor called" << endl;
// }
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        cout << "Three-args constructor called" << endl; 
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
    
    return 0;
}