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
     Node *kill = this->head;
     if(kill == 0) {
          throw 2;
     } else if (kill->next == 0) {
         delete this->head;
         this->head = 0;
     } else {
          for(int i = 0; kill != 0 && i < size - 1; i++) {
               kill = kill->next;
          }
          // delete kill->next;
          Node *next = kill->next->next;
          delete kill->next;
          kill->next = 0;
     }
     this->size--;
}
// This works
void List::view() {
     Node *temp;
     int i = 0;
     if(size) { // Check if there's even anything there
          for (temp = this->head; temp != 0 && (temp != 0 || i <= size); temp = temp->next)  {
               i++;
               std::cout << "Node " << i - 1 << ": " << temp->datum << std::endl;
          }
     } else {
          throw 2; // List is empty, nothing to view
     }
}
// This works
int List::getSize() {
     return this->size;
}
// This works
int List::getDat(int ind) {
     Node *temp = head;
     for(int i = 0; i < ind; i++) {
          temp = temp->next;
     }
     return temp->datum;
}
