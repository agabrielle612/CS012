#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);


void menu( vector<int> , vector<int> );

int main() {

   const int NUM_VALS = 5;
   vector<int> jerseyNum(NUM_VALS);
   vector<int> rating(NUM_VALS);

   for (int i = 0; i < NUM_VALS; ++i) {
      cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
      cin >> jerseyNum.at(i);
      cout << "Enter player " << i + 1 << "'s rating:" << endl;
      cin >> rating.at(i);
      cout << endl;
   }

   outputRoster(jerseyNum, rating);

   cout << endl;

   menu(jerseyNum, rating);

   return 0;
}

void outputRoster(const vector<int> & jerseyNum, const vector<int> &rating) {
  cout << "ROSTER" << endl;

  for (unsigned i = 0; i < jerseyNum.size(); ++i) {
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i);
      cout << ", Rating: " << rating.at(i) << endl;
   }
   cout << endl;
   menu(jerseyNum, rating);
}

void menu(vector<int> jerseyNum, vector<int> rating){

   char usrChoice;
   cout << "MENU" << endl;
   cout << "a - Add player" << endl;
   cout << "d - Remove player" << endl;
   cout << "u - Update player rating" << endl;
   cout << "r - Output players above a rating" << endl;
   cout << "o - Output roster" << endl;
   cout << "q - Quit" << endl;

   cout << endl << "Choose an option:";
   cin >> usrChoice;
   cout << endl;

   if ('a' == usrChoice) {
      addPlayer(jerseyNum, rating);
      }

   if ('d' == usrChoice) {
      removePlayer(jerseyNum, rating);
   }

   if ('u' == usrChoice) {
      updatePlayerRating(jerseyNum, rating);
   }

   if ('r' == usrChoice) {
      outputPlayersAboveRating(jerseyNum, rating);
   }

   if ('o' == usrChoice) {
      outputRoster(jerseyNum, rating);
      }

   if ('q' == usrChoice) {
      exit(0);
   }
}

void addPlayer(vector<int> &jerseyNum, vector<int> &rating) {

   int plusMember;

   cout << "Enter another player's jersey number:" << endl;
   cin >> plusMember;
   jerseyNum.push_back(plusMember);

   cout << "Enter another player's rating:" << endl;
   cin >> plusMember;
   rating.push_back(plusMember);

   cout << endl;

   menu(jerseyNum, rating);
}

void removePlayer(vector<int> &jerseyNum, vector<int> &rating) {

   int delMember;
   unsigned indexDel = 0;
   vector<int> tempJerseyNum;
   vector<int> tempRating;

   cout << "Enter a jersey number:" << endl;
   cin >> delMember;

   //first find the specified jerseyNum to delete player
   for (unsigned i = 0; i < jerseyNum.size(); ++i) {
      if (jerseyNum.at(i) == delMember) {
         indexDel = i;
      }
   }

   //store temp vector update vals
   for (unsigned i = indexDel + 1; i < jerseyNum.size(); ++i) {
      tempJerseyNum.push_back(jerseyNum.at(i));
      tempRating.push_back(rating.at(i));
   }

   //delete rosters members
   unsigned j = 0;
   for (unsigned i = indexDel; i < jerseyNum.size() - 1; ++i) {
      jerseyNum.at(i) = tempJerseyNum.at(j);
      rating.at(i) = tempRating.at(j);
      j++;
   }

   //delete last element because of update roster
   jerseyNum.pop_back();
   rating.pop_back();

   menu(jerseyNum, rating);

}

void updatePlayerRating(const vector<int> &jerseyNum, vector<int> &rating){

   int usrJersey;
   int newRating;

   cout << "Enter a jersey number:" << endl;
   cin >> usrJersey;

   cout << "Enter a new rating for a player:" << endl;
   cin >> newRating;

   for (unsigned i = 0; i < jerseyNum.size(); i++)  {
      if (jerseyNum.at(i) == usrJersey) {
         rating.at(i) = newRating;
      }
   }

   menu(jerseyNum, rating);

}
void outputPlayersAboveRating(const vector<int> &jerseyNum, const vector<int> &rating) {
   int usrRating;

   cout << "Enter a rating:" << endl;
   cin >> usrRating;

   cout << "ABOVE " << usrRating << endl;

   for (unsigned i = 0; i < rating.size(); i++) {
      if (rating.at(i) > usrRating) {
         cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i);
         cout << ", Rating: " << rating.at(i) << endl;
      }
   }
}
