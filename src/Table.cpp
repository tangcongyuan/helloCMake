#include "Table.h"
#include <sstream>

Table::Table(int decks_per_table,
        int players_per_table,
        int cards_to_keep) :
        _decks(decks_per_table),
        _players(players_per_table),
        _keep(cards_to_keep) {
    // std::cout << "Create Table: " << this->str() << std::endl;
    shuffled.reserve(_decks * CARDS_PER_DECK);
    for(int i = 0; i < _decks; i++) {
      Deck deck{CARDS_PER_DECK};
      for(int j = 0; j < CARDS_PER_DECK; j++) {
          auto& card = deck.get_card(j);
          shuffled.emplace_back(card.get_suit(), card.get_value());
      }
    }
}

std::string Table:: str() {
    std::ostringstream oss;
    oss << this->_decks << " decks per table; " <<
        this->_players << " players per table; " <<
        this->_keep << " cards to keep.";
    return oss.str();
}
