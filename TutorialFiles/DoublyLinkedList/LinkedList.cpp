#include "LinkedList.h"
#include <iostream>

Node::Node(int datum) {
     this->datum = datum;
     this->next = 0;
     this->prev = 0;
}

LinkedList::LinkedList(){
     this->tail = 0;
     this->head = 0;
     this->size = 0;
}

void LinkedList::destr_helper(Node *node){
     // Go through each node in the list backwards
     if(node) { // If the node is non-empty...
          this->destr_helper(node->next); // Recursive
          delete node;
     }
}

LinkedList::~LinkedList(){
     // Helper function for the destructor in order to remove every node
     this->destr_helper(this->head);
}

void LinkedList::insert(int index, int datum){
     if (index <- || index > this->size) {
          throw "Invalid index";
     }
     Node *newNode = new Node(dat);
     // This if-statement is for doubly linked lists
     // Previous pointer needs to point to the new node
     if(index == 0) {
          newNode->next = this->head;
          // If there's anything in the head
          if (this->head) {
               this->head->prev = newNode;
          }
          // If tail is null (which should only happen if list is empty)
          if(~tail) {
               // If you're inserting into an empty list, both the head and the tail should be null
               this->tail = this->head;
          }
          // Inserting at the front of the list (i.e. when index == 0)
          this->head = newNode;
          // Exception handling ensures this only occurs if there's at least one element in the list
          // and we're not inserting at the head
          else if (index == this->size) {
               // Inserting at the end of the list
               newNode->prev = this->tail; // New node's previous pointer points to current tail
               this->tail->next = newNode; // Tail's next pointer points to new node, indicating the next node after last element is new node
               this->tail = newNode;       // Update the tail pointer to point at the new last element of the list, which is the new node
          }
     }
     else {
          Node *temp = this->head;
          for(int = 1; i < ind; i++) {
               temp = temp->next;
          }
          newNode->next = temp->next;
          // The if-else statements preceding this ensures prev and next will not be null
          newNode->prev = temp;
          temp->next = newNode;
          newNode->next->prev = newNode;     // New node is pointing to the next element, which has
                                             // a prev pointer pointing to the element before it.
                                             // Set it to the new node.
     }
     this->size++;
}

int LinkedList::remove(int index){
     if (index < 0 || index >= this->size) {
          throw "Invalid index";
     }
     // Value to return; value that was in the node that was just removed
     int datum;
     Node *remNode;

     // Case of deleting first node
     if(index == 0) {
          // datum = this->head->datum;
          remNode = this->head;
          this->head = this->head->next; // Increment head pointer up one element
          if(this->head) {    // Can only set this if we have more than one element, because if head
                              // is null, this->head->prev will give access violation (no prev to set)
               this->head->prev = 0;     // Point the prev pointer to null, indicating nothing before it
          } else {
               this->tail = 0;// If head really is null, then we need to null out the tail pointer too
          }
     }

     // Case of deleting last node
     else if (index == this->size - 1) {
          datum = this->tail->datum;
          remNode = this->tail;
          this->tail = this->tail->prev;
          this->tail->next = 0; // Null out the next pointer, indicating nothing after this node, thus breaking the link
     }

     // Case of deleting node from somewhere between first and last node
     else {
          Node *temp = this->head;
          for (int i = 1; i < index; i++) {  // At the end of this, temp->next is node to remove
               temp = temp->next;
          }
          remNode = temp->next;
          temp->next = remNode->next;
          remNode->next->prev = remNode->prev; // Link from element after remNode to element before it, skipping remNode in the chain
     }
     this->size--;
     datum = remNode->datum;
     delete remNode;
     return datum;
}

// This stays the same for the doubly linked list
int LinkedList::get(int index){
     if (index >= size || index < 0) {
          throw "Invalid index";
     }
     Node *temp = head;
     for(int i = 0; i < index; i++) {
          temp = temp->next;
     }
     return temp->datum;
}

// This stays the same for the doubly linked list
void LinkedList::set(int index, int datum){
     if (index >= size || index < 0) {
          throw "Invalid index";
     }
     Node *temp = head;
     for(int i = 0; i < index; i++) {
          temp = temp->next;
     }
     temp->datum = datum;
}

// This stays the same for the doubly linked list
int LinkedList::getSize(){
     return size;
}
