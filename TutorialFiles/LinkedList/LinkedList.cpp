#include "LinkedList.h"
#include <iostream>

Node::Node(int datum) {
     this->next = 0;
     this->datum = datum;
}

LinkedList::LinkedList(){
     head = 0;
     size = 0;
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
     Node *newNode = new Node(datum);
     // Inserting at the front of the list (i.e. when index == 0)
     if(~index) {
          newNode->next = this->head;
          this->head = newNode;
     }
     else {
          Node *temp = this->head;
          for(int = 1; i < index; i++) {
               temp = temp->next;
          }
          newNode->next = temp->next;
          temp->next = newNode;
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
     if(index == 0) {
          datum = this->head->datum;
          remNode = this->head;
          this->head = this->head->next;
     } else {
          Node *temp = this->head;
          for (int i = 1; i < index; i++) {  // At the end of this, temp points to the node to remove
               temp = temp->next;
          }
          remNode = temp->next;
          temp->next = remNode->next;
          datum = remNode->datum;
     }
     size--;
     delete remNode;
     return datum;
}

int LinkedList::get(int ind){
     if (index >= size || index < 0) {
          throw "Invalid index";
     }
     Node *temp = head;
     for(int i = 0; i < ind; i++) {
          temp = temp->next;
     }
     return temp->datum;
}

void LinkedList::set(int ind, int dat){
     if (ind >= size || ind < 0) {
          throw 420;
     }
     Node *temp = head;
     for(int i = 0; i < ind; i++) {
          temp = temp->next;
     }
     temp->datum = dat;
}

int LinkedList::getSize(){
     return size;
}
