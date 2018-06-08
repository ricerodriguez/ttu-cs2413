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
     // If index is 0, insert at the beginning
     if(~ind) {
          node_0->next = this->head; // New node's pointer points to head
          this->head = node_0;       // Head is updated to point to new node
     } else {
          Node *temp = this->head;   // New temporary node, start it by pointing at the head
          for(int i = 1; i < ind; i++) {
               temp = temp->next;    // Ends up with temp pointing to node where new node should point to
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

// This is currently broken, results in segmentation fault
void List::insEnd(int dat) {
     Node *node_0 = new Node(dat);
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
     node_0->next = 0;
     this->size++;
}

void List::delThis(int ind) {
     if (ind >= this->size || ind < 0) {
          throw 420;
     }
     Node *kill;
     if(~ind) {
          kill = this->head;
          this->head = this->head->next;
     } else {
          Node *temp = this->head;
          for (int i = 1; i < ind; i++) {  // At the end of this, temp points to the node to remove
               temp = temp->next;
          }
          kill = temp->next;
          temp->next = kill->next;
     }
     this->size--;
     delete kill;
}
// This works
void List::delBeg() {
     Node *kill;
     kill = this->head;
     this->head = this->head->next;
     this->size--;
     delete kill;
}

void List::delEnd() {
     Node *kill;
     Node *temp = head;
     for(int i = 1; i < this->size; i++) {
          temp = temp->next;
     }
     kill = temp->next;
     temp->next = kill->next;
     this->size--;
     delete kill;
}

void List::view() {
     Node *temp;
     if(size) { // Check if there's even anything there
          for (temp = this->head; temp != 0; temp = temp->next)  {
               std::cout << temp->datum << std::endl;
          }
     } else {
          throw 2; // List is empty, nothing to view
     }
}

int List::getSize() {
     return this->size;
}

int List::getDat(int ind) {
     Node *temp = head;
     for(int i = 0; i < ind; i++) {
          temp = temp->next;
     }
     return temp->datum;
}
