#ifndef __DECK_H__
#define __DECK_H__

#include "Card.h"
#include <vector>

class Deck {
public:
    Deck(int num);
    Deck(const Deck& deck) = delete;
    Deck(Deck&& deck) = delete;
    Deck& operator=(const Deck& deck) = delete;
    ~Deck();

    Card::Card& get_card(int i);
private:
    int _num_of_cards;
    std::vector<Card::Card> _cards;
    Card::Suit _suits[4]{
        Card::Suit::Spades,
        Card::Suit::Hearts,
        Card::Suit::Clubs,
        Card::Suit::Diamonds,
    };
    Card::Value _values[13]{
        Card::Value::Ace,
        Card::Value::Two,
        Card::Value::Three,
        Card::Value::Four,
        Card::Value::Five,
        Card::Value::Six,
        Card::Value::Seven,
        Card::Value::Eight,
        Card::Value::Nine,
        Card::Value::Ten,
        Card::Value::Jack,
        Card::Value::Queen,
        Card::Value::King,
    };
};

#endif // __DECK_H__
