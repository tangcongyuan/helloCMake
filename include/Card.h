#ifndef __CARD_H__
#define __CARD_H__

#include "Config.h"
#include <iostream>
#include <sstream>
#include <string>

namespace Card {

// When adding more suits, make sure to add them in 'operator<<' as well.
enum class Suit {
    Spades,
    Hearts,
    Clubs,
    Diamonds,
};

std::ostream& operator<<(std::ostream& os, const Suit& suit);

// When adding more values, make sure to add them in 'operator<<' as well.
enum class Value {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Small_Joker,
    Big_Joker,
};

std::ostream& operator<<(std::ostream& os, const Value& value);

class Card {
public:
    // Card();                      // Default Constructor
    Card(Suit suit, Value value);   // Custom Constructor
    Card(const Card& c) = delete;   // Custome Copy Constructor
    Card(Card&& c);                 // Custom Move Constructor
    Card& operator=(const Card& c) = delete; // Custom Copy Assign operator
    Card& operator=(Card&& c);      // Custom Move Assign operator, for std::shuffle/swap algorithm
    ~Card();                        // Custom Destructor

    std::string str();
    std::string emoji();

    Suit get_suit();
    Value get_value();

private:
    Suit _suit;
    Value _value;
};

// Overload operator via non-member function
std::ostream& operator<<(std::ostream& os, Card& card);

}

#endif // __CARD_H__
