#include "Deck.h"

Deck::Deck(int num) : _num_of_cards(num) {
    this->_cards.reserve(_num_of_cards);
    for(const Card::Suit& suit : this->_suits)
        for(const Card::Value& value : this->_values)
            this->_cards.emplace_back(suit, value);
    this->_cards.emplace_back(Card::Suit::Diamonds, Card::Value::Small_Joker);
    this->_cards.emplace_back(Card::Suit::Diamonds, Card::Value::Big_Joker);
}

Deck::~Deck(){}
