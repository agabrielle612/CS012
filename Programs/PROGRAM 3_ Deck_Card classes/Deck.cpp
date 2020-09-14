#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Deck.h"
#include "Card.h"

/* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
       For best efficiency, top of Deck should be stored at 
       back end of vector.
    */
//c = Clubs, d = Diamonds, h = Hearts, s = Spades
Deck::Deck() {
   int sz = 13;

   for (int i = sz; i > 0; i--) {
       theDeck.push_back(Card('s', i));
   }
   for (int i = sz; i > 0; i--) {
       theDeck.push_back(Card('h', i));
   }

    for (int i = sz; i > 0; i--) {
       theDeck.push_back(Card('d', i));
   }

   for (int i = sz; i > 0; i--) {
        theDeck.push_back(Card('c',i));
   }

}

/* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
       As mentioned in comments for constructor, for best efficiency,
       top card should be at back end of vector.
    */
Card Deck::dealCard() {
    Card topCard = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(topCard);
    return topCard;
}

/* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       To pass test harness, this function must go forward through dealtCards
       pushing each Card onto back end of theDeck, then clear dealtCards. Do
       not use pop_back on dealtCards.
    */
void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); i++) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
    random_shuffle( theDeck.begin(), theDeck.end());
}

/* returns the size of the Deck (how many cards have not yet been dealt).
    */
unsigned Deck::deckSize() const{
    return theDeck.size();
}
