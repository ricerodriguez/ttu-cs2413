#include "doublelist.h"
#include <iostream>
Node::Node(int datum){
     this->datum = datum;
     this->next = 0;
}

List::List(){
     this->head = 0;
     this->size = 0;
}

void List::del(Node *node) {
     if(node) {
          this->del(node->next);
          delete node;
     }
}

List::~List(){
     this->del(this->head);
}

// This works
void List::ins(int index, int datum) {
     if (index > this->size || index < 0) {
          throw 420;
     }
     Node *newNode = new Node(datum);
     Node *temp = this->head;   // New temporary node, start it by pointing at the head

     // If index is 0, insert at the beginning
     if(index == 0) {
          newNode->next = this->head; // New node's pointer points to head
          this->head->prev = newNode;
          this->head = newNode;       // Head is updated to point to new node

     // If index is the size of the list, insert at the end
     } else if (index == this->size) {
          newNode->next = 0;
          if(this->head == 0) {
               this->head = newNode;    // Head points to new node now
               this->tail = newNode;    // Tail points to new node now
          } else {
               while(temp->next != 0){
                    temp = temp->next;
               }
               // Make the temp node point to the new node, new node is now being pointed to in the list
               // and pointing to the next node in the list
               temp->next = newNode;
               newNode->prev = temp;
               this->tail = newNode;
          }
     }

     // If index isn't 0 and it's not the size of the list, prepare to insert somewhere in the middle
     else {
          int i;
          while(i < index - 1 && temp->next != 0){
               temp = temp->next;
               i++;
          }
          newNode->next = temp->next;
          // Make the temp node point to the new node, new node is now being pointed to in the list
          // and pointing to the next node in the list
          temp->next = newNode;
          newNode->next->prev = newNode;
          newNode->prev = temp;
     }
     this->size++;
}
// This works
void List::insBeg(int datum) {
     Node *newNode = new Node(datum);
     newNode->next = this->head;
     this->head->prev = newNode;
     this->head = newNode;
     this->size++;
}

// This works
void List::insEnd(int datum) {
     Node *newNode = new Node(datum);
     newNode->next = 0;
     Node *temp = this->head;   // New temporary node, start it by pointing to head
     if(this->head == 0) {
          this->head = newNode;    // Head points to new node now
          this->tail = newNode;    // Tail points to new node now
     } else {
          while(temp->next != 0){
               temp = temp->next;
          }
          // Make the temp node point to the new node, new node is now being pointed to in the list
          // and pointing to the next node in the list
          temp->next = newNode;
          newNode->prev = temp;
          this->tail = newNode;
     }
     this->size++;
}
// This works
void List::delThis(int index) {
     Node *kill = this->head;
     if (index >= this->size || index < 0) {
          throw 420;
     }
     if(index == 0) {
          this->head = this->head->next;
     } else {
          for(int i = 0; kill != 0 && i < index - 1; i++) {
               kill = kill->next;
          }
          Node *next = kill->next->next;
          delete kill->next;
          kill->next = next;
     }
     this->size--;
}
// This works
void List::delBeg() {
     if(~this->head) {
          throw "List is empty, nothing to delete";
     }
     Node *kill;
     kill = this->head;
     this->head = this->head->next;
     this->size--;
     delete kill;
}

void List::delEnd() {
     if(~this->head) {
          throw "List is empty, nothing to delete";
     }
     Node *temp = this->head;
     if(size > 1) {
          for(int i = 1; i < this->size - 1; i++){
               temp = temp->next;
          }
          temp->next = 0;
          delete temp->next;
          this->tail = temp;
     } else {
          this->tail = this->head->next;
          this->head = this->head->next;
          delete temp;
     }
     this->size--;
}
// This works
void List::view() {
     Node *node = this->head;
     // Node *temp;
     int i = 0;
     while(node != 0){
          std::cout << "Node " << i << ": " << node->datum << std::endl;
          node = node->next;
          i++;
     }
     if (this->head == 0) {
          std::cout << "Linked list is currently empty." << std::endl;
     }
}
// This works
int List::getSize() {
     return this->size;
}
// This works
int List::getDat(int index) {
     Node *temp = this->head;
     for(int i = 1; i < index; i++) {
          temp = temp->next;
     }
     return temp->datum;
}
