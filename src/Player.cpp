#include "Config.h"
#include "Player.h"
#include <sstream> // std::ostringstream
#include <iostream>// std::cout, std::endl

namespace Player {
// Custom Constructor
Player::Player(long player_id) : _id(player_id) {
    assert((DECKS_PER_TABLE * CARDS_PER_DECK - CARDS_TO_KEEP) % PLAYERS_PER_TABLE == 0);
    _hand.reserve((DECKS_PER_TABLE * CARDS_PER_DECK - CARDS_TO_KEEP) / PLAYERS_PER_TABLE);
    std::cout << str() << " will have " <<
        ((DECKS_PER_TABLE * CARDS_PER_DECK - CARDS_TO_KEEP) / PLAYERS_PER_TABLE) <<
        " cards on hand." << std::endl;
}

Player::Player(Player&& player) {
    _id = player._id;
}

// Default Destructor
Player::~Player(){}

std::string Player::str() {
    std::ostringstream oss;
    oss << "Player" << _id;
    return oss.str();
}

}
