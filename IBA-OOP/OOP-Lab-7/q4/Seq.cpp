// Implementation of the simple Sequence class

#include "Seq.h"

using namespace std; // for cout, cin 

// Default constructor
template <typename T>
Seq<T>::Seq(){
   first = nullptr;
   size = 0;
}

// Copy Constructor
template <typename T>
Seq<T>::Seq(const Seq& original ){
   if (original.first == nullptr){
      first = nullptr;
      size = 0;
   }else{
      first = new Node;
      first->data = original.first->data;
      Node *pNewNode = first ;
      Node *pOldNode = original.first->next;
      // Repeat until the entire list is copied
      while (pOldNode != nullptr){
         pNewNode->next = new Node;
         pNewNode = pNewNode->next;
         pNewNode->data = pOldNode->data;;
         pOldNode = pOldNode->next;
      }
      pNewNode->next = nullptr;
      size = original.size;
   }
}

template <typename T>
Seq<T>::~Seq(){
   Node *p = first;
   // Traverse the list deleting nodes
   while (p!= nullptr){
      first = first->next; // hang on to the rest of the list
      delete p; // De-allocate memory
      p = first; // Go to next node
   }
   first = nullptr;
   size = 0;
}

// Adds a node to the start of the sequence, making it the (new) first element
template <typename T>
void Seq<T>::add(T x){
    Node *p = new Node; //temporary node
    // Assign appropriate values to the new node
    p -> data = x;
    p -> next = first;
    // Make first point to the new node
    first = p;	
    size++;
}

// Inserts element x at the given position (or index) in the sequence
template <typename T>
void Seq<T>::insertAt(T x, int pos){
   Node *p;
   Node *newNode;
   // If pos is not a valid index, do nothing.
   if (pos > size){ 
      return ;
   }
   newNode = new Node; //new node
   newNode->data = x;

   // Deal with case when item is to be inserted at the front
   if (pos == 0){
      newNode->next = first;
      first = newNode;
   }else{ // pos > 0
      p = first;
      // Move to position BEFORE insertion point
      for(int i = 0; i < pos-1; i++){
         p = p->next;
      }
      // Insert node
      newNode->next = p->next;
      p->next = newNode;
   }
   size++;
}

// If data occurs in the sequence, removes the first occurrence and returns 
// true, otherwise returns false.
template <typename T>
bool Seq<T>::remove(T x){
   Node *p = first;
   Node *temp;
   // If sequence is empty, just return false.
   if (first == nullptr){
      return false;
   }
   // Handle case where target is first
   else if (first->data == x){
      first = first ->next;
      delete p; //currently assigned head
      size--;
      return true;
   }
   // Otherwise traverse the list, looking for data
   else{
      while(p->next != nullptr){
         // Check next node for target
         if(p->next->data == x){
            temp = p->next;
            p->next = p->next->next;
            delete temp;
            return true;
         }
         p = p->next;
      }
   }
   return false;
}

// Prints the entire sequence to the screen.
// Most classes should not do their own I/O like this, because this 
// prevents a programmer using the class from controlling the I/O.
// But, it can be convenient for debugging.
template <typename T>
void Seq<T>::display(){
   Node *p = first;
   cout << "["; //Nice format!
   // Traverse the list
   while (p != nullptr){
      cout << p -> data; // Print data
      p = p -> next; // Go to next node
      if (p != nullptr){
         cout << ","; // Print a comma unless at the end of the list
      }
   }
   cout << "]"; // Don't print a newline - it might not be wanted
}
