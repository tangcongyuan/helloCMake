#include "Deck.h"

Deck::Deck(int num) : _num_of_cards(num) {
    this->_cards.reserve(_num_of_cards);
    // for(int i = 0; i < num; i++) this->_cards.push_back(Card::Card{ Card::Suit::Spades, Card::Value::Ace });
    for(const Card::Suit& suit : this->_suits)
        for(const Card::Value& value : this->_values)
            this->_cards.emplace_back(suit, value);
}
