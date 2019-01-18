#include "Table.h"
#include "Player.h"
#include "ConcurrentCounter.h"
#include "Instruction.h"
#include "util.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>

int main(int argc, char** argv) {
    using namespace std;

    Instruction *instr = new Instruction("instruction1");
    cout << "Hello from Eric!" << endl;
    cout << "instr = " << instr << endl;
    delete instr;

    list<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(3);
    util::print(v, "list");

    // ConcurrentCounter cc;
    // cc(); // default NUM_OF_THREADS = 10

    Table table{DECKS_PER_TABLE, PLAYERS_PER_TABLE, CARDS_TO_KEEP};
    table.shuffle();

    vector<Player::Player> players;
    for(int i = 0; i < PLAYERS_PER_TABLE; i++) players.emplace_back(i);

    list<int> l1{1, 3, 5, 7, 9};
    list<int> l2{2, 4, 6, 8, 0};
    list<int>::iterator it = l1.begin();
    ++it;
    l1.splice(it, l2, l2.begin()); // , l2.end());
    std::cout << "*it = " << *it << std::endl;
    util::print(l1, "l1");
    util::print(l2, "l2");

    return 0;
}
