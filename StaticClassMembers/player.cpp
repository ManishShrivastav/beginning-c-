#include "player.h"

int Player::num_players {0};        // Static member initialization

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;
}

// Copy constructor (this is needed because we have a static member variable)
Player::Player(const Player &source)
    : Player{source.name, source.health, source.xp} {
}

Player::~Player() {
    // Destructor
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}