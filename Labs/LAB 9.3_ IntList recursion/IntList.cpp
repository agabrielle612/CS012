#include "IntList.h"

#include <ostream>
#include <iostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
ostream & operator<<(ostream &out, const IntList &_data) {
   
   operator<<(out, _data.head); 

   return out;
}

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
bool IntList::exists(int num) const {
   return exists(this-> head, num);
}

   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */
bool IntList::exists(IntNode *_data, int num) const {
   
   if (_data == nullptr) {
      return false;
   }
   else if (_data -> data == num) {
      return true;
   }

   return exists(_data -> next, num);
   
}


/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *_data) {
   
   if ( _data == nullptr) {
      return out;
   }
   else {
      out << _data -> data;
      if ( _data -> next != nullptr) {
         out << " ";
      }
      operator<<(out, _data -> next);
   }

   return out;
}