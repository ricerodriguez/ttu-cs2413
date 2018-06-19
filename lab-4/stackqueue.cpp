#include "stackqueue.h"
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

void List::ins(int index, int datum) {
     if (index > this->size || index < 0) {
          throw InvInd();
     }
     Node *newNode = new Node(datum);
     Node *temp = this->head;   // New temporary node, start it by pointing at the head

     // If index is 0, insert at the beginning
     if(index == 0) {
          // If there's nothing in the list...
          if(!this->head) {
               this->head = newNode;
               this->tail = newNode;
          }
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
          int i = 0;
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

void List::insBeg(int datum) {
     Node *newNode = new Node(datum);
     // If the list is empty...
     if(!this->head) {
          this->head = newNode;
          this->tail = newNode;
     }
     else {
          newNode->next = this->head;
          this->head->prev = newNode;
          this->head = newNode;
     }
     this->size++;
}

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

void List::delThis(int index) {
     Node *kill = this->head;
     Node *temp = this->head;
     Node *nextNode = this->head;
     if (index > this->size || index < 0) {
          throw InvInd();
     }
     // If index is 0, we're deleting from the beginning of the list
     if(index == 0) {
          this->delBeg();
     // If index is the same as size, we're deleting from the end of the list
     } else if(index == this->size) {
          this->delEnd();
     // Otherwise, we're deleting from somewhere between the head and the tail
     } else {
          int i = 0;
          while(i < index - 1 && temp->next != 0){
               temp = temp->next;
               i++;
          }
          kill = temp->next;
          nextNode = kill->next;
          temp->next = nextNode;
          nextNode->prev = temp;
          delete kill;
          this->size--;
     }
}

int List::delBeg() {
     Node *kill = this->head;
     int datum;
     if(!this->head) {
          throw EmptyList();
     }
     else if(kill == this->tail) {
          datum = this->head->datum;
          delete kill;
          this->head = 0;
          this->tail = 0;
     } else {
          datum = this->head->datum;
          this->head = this->head->next;
          delete kill;
     }
     this->size--;
     return datum;
}

int List::delEnd() {
     if(!this->head) {
          throw EmptyList();
     }
     int datum = this->tail->datum;
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
     return datum;
}

void List::view() {
     Node *node = this->head;
     int i = 0;
     // If there's nothing in the head (list is empty)
     if (this->head == 0) {
          std::cout << "Linked list is currently empty." << std::endl;
     } else {
     std::cout << "This linked list has " << this->size << " nodes." << std::endl;
     while(node != 0){
          if(node == this->head) {
               if(node == this->tail) {
                    std::cout << "Node " << i << ": " << this->head->datum << " (Both the head and tail)" << std::endl;
                    break;
               }
               // std::cout << "Node " << i << " (Head): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << this->head->datum << " (Head)" << std::endl;
          } else if(node->next == 0) {
               // std::cout << "Node " << i << " (Tail): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << this->tail->datum << " (Tail)" << std::endl;
          } else {
               std::cout << "Node " << i << ": " << node->datum << std::endl;
          }
          node = node->next;
          i++;
     }
     }
}

int List::getSize() {
     return this->size;
}

int List::getDat(int index) {
     Node *temp = this->head;
     for(int i = 1; i < index; i++) {
          temp = temp->next;
     }
     return temp->datum;
}

Stack::Stack() {
     this->stack = new List;
}

Stack::~Stack(){
     delete this->stack;
}

void Stack::push(int datum) {
     stack->ins(0, datum);
}

int Stack::pop() {
     return stack->delBeg();
}

int Stack::peek() {
     return stack->getDat(0);
}

void Stack::print() {
     stack->view();
}

void Stack::empty() {
     this->~Stack();
}

Queue::Queue() {
     this->queue = new List;
}

Queue::~Queue() {
     delete this->queue;
}

void Queue::push(int datum) {
     queue->ins(queue->getSize(), datum);
}

int Queue::pop() {
     return queue->delBeg();
}

int Queue::peek() {
     return queue->getDat(queue->getSize());
}

void Queue::empty() {
     this->~Queue();
}

void Queue::print() {
     queue->view();
}
