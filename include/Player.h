#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.h"
#include <vector>
#include <string>

namespace Player {

class Player {
public:
    Player(long player_id);                // Custom Constructor
    Player(const Player& player) = delete; // Copy Constructor
    Player(Player&& player);               // Move Constructor
    Player& operator=(const Player& rhs) = delete; // Copy Assign operator
    Player& operator=(Player&& rhs) = delete;      // Move Assign operator
    ~Player();                             // Default Destructor

    std::string str();
private:
    long _id;
    std::vector<Card::Card> _hand;
};

}

#endif // __PLAYER_H__
