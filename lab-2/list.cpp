#include "list.h"
#include <iostream>
Node::Node(int dat){
     datum = dat;
     next = 0;
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
void List::ins(int ind, int dat) {
     if (ind > this->size || ind < 0) {
          throw 420;
     }
     Node *node_0 = new Node(dat);
     Node *temp = this->head;   // New temporary node, start it by pointing at the head
     // If index is 0, insert at the beginning
     if(ind == 0) {
          node_0->next = this->head; // New node's pointer points to head
          this->head = node_0;       // Head is updated to point to new node
     } else {
          int i;
          while(i < ind - 1 && temp->next != 0){
               temp = temp->next;
               i++;
          }
          node_0->next = temp->next;
          // Make the temp node point to the new node, new node is now being pointed to in the list
          // and pointing to the next node in the list
          temp->next = node_0;
     }
     this->size++;
}
// This works
void List::insBeg(int dat) {
     Node *node_0 = new Node(dat);
     node_0->next = this->head;
     this->head = node_0;
     this->size++;
}

// This works
void List::insEnd(int dat) {
     Node *node_0 = new Node(dat);
     node_0->next = 0;
     Node *temp = this->head;   // New temporary node, start it by pointing to head
     if(this->head == 0) {
          this->head = node_0;    // Head points to new node now
     } else {
          while(temp->next != 0){
               temp = temp->next;
          }
          // Make the temp node point to the new node, new node is now being pointed to in the list
          // and pointing to the next node in the list
          temp->next = node_0;
     }
     this->size++;
}
// This works
void List::delThis(int ind) {
     Node *kill = this->head;
     if (ind >= this->size || ind < 0) {
          throw 420;
     }
     if(ind == 0) {
          this->head = this->head->next;
     } else {
          for(int i = 0; kill != 0 && i < ind - 1; i++) {
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
     Node *kill;
     kill = this->head;
     this->head = this->head->next;
     this->size--;
     delete kill;
}
// This works, sort of. For some reason doesn't work first time it's used, works every time afterwards...?????
void List::delEnd() {
     Node *temp = this->head;
     if(size > 1) {
          for(int i = 1; i < this->size - 1; i++){
               temp = temp->next;
          }
          temp->next = 0;
          delete temp->next;
     } else {
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
int List::getDat(int ind) {
     Node *temp = this->head;
     for(int i = 1; i < ind; i++) {
          temp = temp->next;
     }
     return temp->datum;
}
