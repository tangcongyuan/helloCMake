#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.h"
#include <vector>

namespace Player {

class Player {
public:
    Player(){}
private:
    std::vector<Card::Card> _hand;
};

}

#endif // __PLAYER_H__
