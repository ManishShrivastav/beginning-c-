#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string text_to_day);
    bool is_dead();
};

class Account
{
    public:
    // attributes
    string name;
    double balance;

    // methods
    bool deposit (double bal);
    bool withdrawl (double bal);
};


int main()
{
    
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    
    return 0;
}