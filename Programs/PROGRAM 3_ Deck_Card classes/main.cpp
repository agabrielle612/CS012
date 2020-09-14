#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &, const vector<Card> &);

bool operator==(const Card&, const Card&);

int main() {
	srand(2222);

	string ans, outputFile;
	unsigned numOfCards, numOfDeals;
	double percentage = 0;
	ofstream outFile;

	cout << "Do you want to output all hands to a file? (Yes/No) ";
	cin >> ans;
	cout << endl;

	if (ans == "Yes") {
		cout << "Enter name of output file: ";
		cin >> outputFile;
		cout << endl;

		outFile.open(outputFile);

		if (!outFile.is_open()) {
			cout << "Could not open " << outputFile << "." << endl;
			exit(0);
		}
	}

	cout << "Enter number of cards per hand: ";
	cin >> numOfCards;
	cout << endl;

	cout << "Enter number of deals (simulations): ";
	cin >> numOfDeals;
	cout << endl;

	vector<Card> _dealtCards;
	Deck _card;

	//cout << "TEST1" << endl;
	for (unsigned i = 0; i < numOfDeals; i++) {
		_card.shuffleDeck();
		
        //cout << "TEST2" << endl;
        for (unsigned j = 0; j < numOfCards; j++) {
            _dealtCards.push_back(_card.dealCard());
        }
        
        //cout << "TEST3" << endl;
        if (hasPair(_dealtCards)) {
			outFile << "Found Pair!!! ";
            percentage++;
        }
        else {
            outFile << "              ";
        }
        outFile << _dealtCards << endl;

		_dealtCards.clear(); //clears the dealtCards so that when reshuffled, it'll be a clean vector
	}

	outFile.close();
	
	percentage = 100 * ( percentage / static_cast<double>(numOfDeals));

	cout << "Chances of receiving a pair in a hand of " << numOfCards << " cards is: " << percentage << " %" << endl;
	return 0;
}

bool hasPair(const vector<Card> &hand) {
	int pair;

	for (unsigned i = 0; i < hand.size(); i++) {
		pair = hand.at(i).getRank();
		for (unsigned j = i + 1; j < hand.size(); j++) {
			if (pair == hand.at(j).getRank()) {
				return true;
			}
		}
	}
	return false;
}

ostream & operator<<(ostream & out, const vector<Card> &cardVal) {
	
    for (unsigned i = 0; i < cardVal.size(); i++) {
		out << cardVal.at(i) << ", ";
	}
	return out;
}

