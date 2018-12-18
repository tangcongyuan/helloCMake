#include "Deck.h"

Deck::Deck(int num) : _num_of_cards(num) {
    _cards.reserve(_num_of_cards);
    for(const Card::Suit& suit : _suits)
        for(const Card::Value& value : _values)
            _cards.emplace_back(suit, value);
    _cards.emplace_back(Card::Suit::Diamonds, Card::Value::Small_Joker);
    _cards.emplace_back(Card::Suit::Diamonds, Card::Value::Big_Joker);
}

Deck::~Deck(){}

Card::Card& Deck::get_card(int i) {
    return (_cards).at(i);
}
