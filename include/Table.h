#ifndef __TABLE_H__
#define __TABLE_H__

#include "Deck.h"
#include "Player.h"
#include <vector>

class Table {
public:
    Table(int decks_per_table,
        int players_per_table,
        int cards_to_keep);
    Table(const Table& table) = delete;
    Table(Table&& table) = delete;
    Table& operator=(const Table& rhs) = delete;

    std::string str();

private:
    int _num_decks;
    int _num_players;
    int _keep;
    std::vector<Card::Card> _shuffled;
    std::vector<Player::Player> _players;
};

#endif // __TABLE_H__
