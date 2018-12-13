#ifndef __TABLE_H__
#define __TABLE_H__

#include "Hand.h"

Class Table {
public:
    Table(int num_of_players) : _players(num_of_players) {}
    initialize() {

    }
private:
    int _players;
    vector<Hand> hands;
};

#endif // __TABLE_H__
