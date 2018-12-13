#include "Deck.h"
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

    Deck deck{CARDS_PER_DECK};

    cout << string("\U0001F0A1") << endl; // Spades
    cout << string("\U0001F0B1") << endl; // Hearts
    cout << string("\U0001F0C1") << endl; // Diamonds
    cout << string("\U0001F0D1") << endl; // Clubs

    return 0;
}
