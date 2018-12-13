#include "Table.h"
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <sstream>      // std::ostringstream

Table::Table(int decks_per_table,
        int players_per_table,
        int cards_to_keep) :
        _num_decks(decks_per_table),
        _num_players(players_per_table),
        _keep(cards_to_keep) {
    // std::cout << "Create Table: " << this->str() << std::endl;
    _shuffled.reserve(_num_decks * CARDS_PER_DECK);
    for(int i = 0; i < _num_decks; i++) {
      Deck deck{CARDS_PER_DECK};
      for(int j = 0; j < CARDS_PER_DECK; j++) {
          // Both of following calls Move Constructor of Card class
          // auto& card = deck.get_card(j);
          // _shuffled.emplace_back(card.get_suit(), card.get_value());
          _shuffled.emplace_back(std::move(deck.get_card(j)));
      }
    }

    std::cout << "Table constains " << _shuffled.size() << " cards." << std::endl;
}

void Table::shuffle() {
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(_shuffled.begin(), _shuffled.end(), std::default_random_engine(seed));
    for(auto& card : _shuffled) std::cout << card.str() << std::endl;
}

std::string Table::str() {
    std::ostringstream oss;
    oss << this->_num_decks << " decks per table; " <<
        this->_num_players << " players per table; " <<
        this->_keep << " cards to keep.";
    return oss.str();
}
