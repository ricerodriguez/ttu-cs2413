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

int List::delBeg() {
     int datum = this->head->datum;
     Node *kill = this->head;
     if(!this->head) {
          throw EmptyList();
     }
     else if(kill == this->tail) {
          delete kill;
          this->head = 0;
          this->tail = 0;
     } else {
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
     if(temp){
          return temp->datum;
     } else {
          throw InvInd();
     }
}

Node* List::getHead() {
     return this->head;
}

Node* List::getTail() {
     return this->tail;
}

bool List::isEmpty() {
     return !this->head;
}

Stack::Stack() {
     this->stack = new List;
}

Stack::~Stack(){
     // stack->del(stack->getHead());
     delete this->stack;
}

void Stack::push(int datum) {
     stack->insBeg(datum);
}

int Stack::pop() {
     if(stack->getHead() == 0) {
          throw EmptyList();
     }
     return stack->delBeg();
}

int Stack::peek() {
     if(stack->getHead() == 0) {
          throw EmptyStack();
     }
     return stack->getDat(0);
}

void Stack::print() {
     Node* node = stack->getHead();
     Node *head = stack->getHead();
     Node *tail = stack->getTail();
     int i = 0;
     // If there's nothing in the head (list is empty)
     if (head == 0) {
          std::cout << "Stack is currently empty." << std::endl;
     } else {
     std::cout << "This stack has " << stack->getSize() << " nodes." << std::endl;
     while(node != 0){
          if(node == head) {
               if(node == tail) {
                    std::cout << "Node " << i << ": " << stack->getDat(0) << " (Top/Bottom)" << std::endl;
                    break;
               }
               // std::cout << "Node " << i << " (Head): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << head->datum << " (Top of Stack)" << std::endl;
          } else if(node->next == 0) {
               // std::cout << "Node " << i << " (Tail): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << tail->datum << " (Bottom of Stack)" << std::endl;
          } else {
               std::cout << "Node " << i << ": " << node->datum << std::endl;
          }
          node = node->next;
          i++;
     }
     }


}

bool Stack::empty() {
     return stack->isEmpty();
}

Queue::Queue() {
     this->queue = new List;
}

Queue::~Queue() {
     delete this->queue;
}

void Queue::push(int datum) {
     queue->insEnd(datum);
}

int Queue::pop() {
     return queue->delEnd();
}

int Queue::peek() {
     if(queue->getHead() == 0) {
          throw EmptyQueue();
     }
     return queue->getDat(queue->getSize());
}

bool Queue::empty() {
     return queue->isEmpty();
}

void Queue::print() {
     // queue->view();
     Node* node = queue->getHead();
     Node *head = queue->getHead();
     Node *tail = queue->getTail();
     int i = 0;
     // If there's nothing in the head (list is empty)
     if (head == 0) {
          std::cout << "Queue is currently empty." << std::endl;
     } else {
     std::cout << "This queue has " << queue->getSize() << " nodes." << std::endl;
     while(node != 0){
          if(node == head) {
               if(node == tail) {
                    std::cout << "Node " << i << ": " << queue->getDat(0) << " (Top/Bottom)" << std::endl;
                    break;
               }
               // std::cout << "Node " << i << " (Head): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << head->datum << " (Top of Queue)" << std::endl;
          } else if(node->next == 0) {
               // std::cout << "Node " << i << " (Tail): " << node->datum << std::endl;
               std::cout << "Node " << i << ": " << tail->datum << " (Bottom of Queue)" << std::endl;
          } else {
               std::cout << "Node " << i << ": " << node->datum << std::endl;
          }
          node = node->next;
          i++;
     }
     }

}
