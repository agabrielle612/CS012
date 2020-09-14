#include <iostream>
using namespace std;

#include "Card.h"

/* Assigns a default value of 2 of Clubs
    */
Card::Card() : suit('c'), rank(2) {
}	
	
	/* Assigns the Card the suit and rank provided.
	   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
	   If an invalid suit is provided, sets the suit to Clubs
	   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
	   If an invalid rank is provided, sets the rank to 2
	   Accepts lower or upper case characters for suit
	*/	
Card::Card(char s, int r) {
    s = tolower(s);
    
    if (s == 'c') {
        suit = 'c';
    }
    else if (s == 'd') {
        suit = 'd';
    }
    else if (s == 'h') {
        suit = 'h';
    }
    else if (s == 's') {
        suit = 's';
    }
    else {
        suit = 'c';
    }

    if (r < 1 || r > 13) {
        rank = 2;
        suit = 'c';
    }
    else {
        rank = r;
    }
}
	
	/* Returns the Card's suit
	*/
char Card::getSuit() const {
    return suit;
}
	
	/* Returns the Card's rank as an integer
	*/
int Card::getRank() const {
    return rank;
}
	/* Outputs a Card in the following format: Rank of Suit
	   For example, if the rank is 3 and the suit is h: 3 of Hearts
	   Or, if the rank is 1 and the suit is d: Ace of Diamonds
	   Or, if the rank is 12 and the suit is c: Queen of Clubs
	   etc.
	*/	
//1 = Ace, 11 = Jack, 12 = Queen, 13 = King
ostream & operator<<(ostream &out, const Card &usrcard) { //friend, can access private members
    if (usrcard.rank == 1) {
        out << "Ace of ";
    }
    else if (usrcard.rank == 11) {
        out << "Jack of ";
    }
    else if (usrcard.rank == 12) {
        out << "Queen of ";
    }
    else if (usrcard.rank == 13) {
        out << "King of ";
    }
    else {
        out << usrcard.rank << " of ";
    }

    if (usrcard.suit == 'c') {
        out << "Clubs";
    }
    else if (usrcard.suit == 'd') {
        out << "Diamonds";
    }
    else if (usrcard.suit == 'h') {
        out << "Hearts";
    }
    else if (usrcard.suit == 's') {
        out << "Spades";
    }

    return out;
}