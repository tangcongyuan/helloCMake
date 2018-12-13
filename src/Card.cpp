#include "Card.h"

namespace Card {

std::ostream& operator<<(std::ostream& os, const Suit& suit) {
    switch(suit) {
        case Suit::Spades:   os << "Spades";   break;
        case Suit::Hearts:   os << "Hearts";   break;
        case Suit::Clubs:    os << "Clubs";    break;
        case Suit::Diamonds: os << "Diamonds"; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Value& value) {
    switch(value) {
        case Value::Ace:   os << "Ace";   break;
        case Value::Two:   os << "Two";   break;
        case Value::Three: os << "Three"; break;
        case Value::Four:  os << "Four";  break;
        case Value::Five:  os << "Five";  break;
        case Value::Six:   os << "Six";   break;
        case Value::Seven: os << "Seven"; break;
        case Value::Eight: os << "Eight"; break;
        case Value::Nine:  os << "Nine";  break;
        case Value::Ten:   os << "Ten";   break;
        case Value::Jack:  os << "Jack";  break;
        case Value::Queen: os << "Queen"; break;
        case Value::King:  os << "King";  break;
        case Value::Small_Joker: os << "Samll Joker"; break;
        case Value::Big_Joker:   os << "Big Joker";   break;
    }
    return os;
}

// Card::Card() {}

Card::Card(Suit suit, Value value) : _suit(suit), _value(value) {
    // std::cout << "Created " << this->str() << std::endl;
}

// Card::Card(const Card& c){
//     this->_suit = c._suit;
//     this->_value = c._value;
// }

Card::Card(Card&& c){
    this->_suit = c._suit;
    this->_value = c._value;
}

// Card& Card::operator=(const Card& rhs) {
//     this->_suit = rhs._suit;
//     this->_value = rhs._value;
//     return *this;
// }

Card& Card::operator=(Card&& rhs) {
  this->_suit = rhs._suit;
  this->_value = rhs._value;
  return *this;
}

Card::~Card(){
    // std::cout << "Card deleted: " << this->str() << std::endl;
}

std::string Card::str() {
    std::ostringstream oss;
    oss << "Card: " << this->_value << " of " << this->_suit;
    return oss.str();
}

std::string Card::emoji() {
    std::string emojis[CARDS_PER_DECK]{
        "\U0001F0A1", "\U0001F0A2", "\U0001F0A3", "\U0001F0A4", "\U0001F0A5", "\U0001F0A6", "\U0001F0A7", "\U0001F0A8", "\U0001F0A9", "\U0001F0AA", "\U0001F0AB", "\U0001F0AD", "\U0001F0AE", // Spades
        "\U0001F0B1", "\U0001F0B2", "\U0001F0B3", "\U0001F0B4", "\U0001F0B5", "\U0001F0B6", "\U0001F0B7", "\U0001F0B8", "\U0001F0B9", "\U0001F0BA", "\U0001F0BB", "\U0001F0BD", "\U0001F0BE", // Hearts
        "\U0001F0D1", "\U0001F0D2", "\U0001F0D3", "\U0001F0D4", "\U0001F0D5", "\U0001F0D6", "\U0001F0D7", "\U0001F0D8", "\U0001F0D9", "\U0001F0DA", "\U0001F0DB", "\U0001F0DD", "\U0001F0DE", // Diamonds
        "\U0001F0C1", "\U0001F0C2", "\U0001F0C3", "\U0001F0C4", "\U0001F0C5", "\U0001F0C6", "\U0001F0C7", "\U0001F0C8", "\U0001F0C9", "\U0001F0CA", "\U0001F0CB", "\U0001F0CD", "\U0001F0CE", // Clubs
        "\U0001F0DF", "\U0001F0CF", // Jokers
    };
    const int CARDS_PER_SUIT = 13;
    return emojis[CARDS_PER_SUIT * (int)this->_suit + (int)this->_value];
}

Suit Card::get_suit() { return this->_suit; }
Value Card::get_value() { return this->_value; }

}
