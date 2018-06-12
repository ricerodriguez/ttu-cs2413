#include "Stack.h"

Node::Node(int datum) {
     this->next = 0;
     this->datum = datum;
}

ListStack::ListStack(){
     this->head = 0;
}

void ListStack::destr_helper(Node *node) {
     if(node) {
          this->destr_helper(node->next);
          delete node;
     }
}

ListStack::~ListStack() {
     this->destr_helper(this->head);
}

void ListStack::push(int datum) {
     Node *newNode = new Node(datum);
     // Put new node at the top of the stack. New node's next pointer points to the old head. Update
     // the head to point at the new node.
     newNode->next = this->head;
     this->head = newNode;
}

int ListStack::pop() {
     if(this->isEmpty()) {
          throw "Stack is empty";
     }
     // Get the datum from the top of the stack (head)
     int datum = this->head->datum;
     // Node to remove is the current head
     Node *remNode = this->head;
     // Update the head pointer to point to the next item in the stack, skipping over the node to
     // remove, so that once the top of the stack has been removed, the head pointer is already
     // updated to point at the new top of the stack
     this->head = remNode->next;
     // Delete the item at the top of the stack
     delete remNode;
     return datum;
}

int ListStack::peek() {
     if(this->isEmpty()) {
          throw "Stack is empty";
     }
     return this->head->datum;
}

bool ListStack::isEmpty() {
     // If head is null, the stack is empty. Thus, the boolean will be true if empty, false if not
     return !this->head;
}

ArrStack::ArrStack() {
     // Arbitrary number to start the size at
     this->size = 10;
     this->head = new int[this->size];
     this->curr = 0;
}

ArrStack::~ArrStack() {
     delete this->head;
}

void ArrStack::push(int datum) {
     // If the array is full...
     if(this->curr == this->size) {
          // Double the size of the array after the current has reached the capacity
          this->size *= 2;
          // Create a new array that's twice as big as the old one
          int *newArr = new int[this->size];
          // Copy elements from old array into new array
          for(int i = 0; i < this->size/2; i++) {
               newArr[i] = this->head[i];
          }
          // Deallocate the old array
          delete this->head;
          // Set the head pointer to the new array
          this->head = newArr;
     }
     // If the array isn't full yet, just stick the datum into the array at the current position
     this->head[this->curr] = datum;
     // Increment the current position, once it reaches capacity (the size of the array) it will hit
     // the if-statement
     this->curr++;
}

int ArrStack::pop() {
     if(this->isEmpty()) {
          throw "Stack is empty";
     }
     // Pointer curr points at the next available empty position in the array. Decrement the curr
     // pointer so that it points at the last item that was put on the stack.
     this->curr--;
     // Now return the datum stored at this position (top of the stack)
     return this->head[this->curr];
     // Note that the datum wasn't removed, but the current position was decremented so the next
     // thing to be put on the top of the stack will overwrite it
}

int ArrStack::peek() {
     if(this->isEmpty()){
          throw "Stack is empty";
     }
     return this->head[this->curr-1];
}

bool ArrStack::isEmpty() {
     return !this->curr;
}

Queue::Queue() {
     this->head = 0;
     this->tail = 0;
}

Queue::~Queue() {
     this->destr_helper(this->head);
}

void Queue::destr_helper(Node *node) {
     if(node) {
          this->destr_helper(node->next);
          delete node;
     }
}

void Queue::push(int datum) {
     Node *newNode = new Node(datum);
     newNode->next = this->head;
     if(this->head){
          this->head->prev = newNode;
     }
     this->head = newNode;
     if(!this->tail) {
          this->tail = newNode;
     }
}

int Queue::pop() {
     if(this->isEmpty()) {
          throw "Stack is empty"
     }
     int datum = this->tail->datum;
     Node *remNode = this->tail;
     this->tail = remNode->prev;
     if(this->tail) {
          this->tail->next = 0;
     } else {
          this->head = 0;
     }
     delete remNode;
     return datum;
}

int Queue::peek() {
     if(this->isEmpty()) {
          throw "Stack is empty";
     }
     return this->tail->datum;
}

bool Queue::isEmpty() {
     return !this->tail;
}
