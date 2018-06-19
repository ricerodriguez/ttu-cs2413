#include <exception>
class Node {
public:
     Node(int);
     int datum;
     Node *next, *prev;
};

struct InvInd : public std::exception {
     const char * what () const throw () {
          return "Invalid index! Please choose something within range. ";
     }
};

struct EmptyList : public std::exception {
     const char * what () const throw () {
          return "List is currently empty! There is nothing to delete. ";
     }
};

struct EmptyStack : public std::exception {
     const char * what () const throw () {
          return "Stack is currently empty! ";
     }
};

struct EmptyQueue : public std::exception {
     const char * what () const throw () {
          return "Queue is currently empty! ";
     }
};

struct NonEmptyList : public std::exception {
     const char * what () const throw () {
          return "List is not empty when it should be. Head is non-empty. ";
     }
};

class List {
     Node *head, *tail;
     int size;
     void del(Node *node);
public:
     List();
     ~List();
     // This function will accept a value from the user, which will be used to create a new node at
     // the beginning of the linked list
     void insBeg(int); // int datum
     // This function will accept a value from the user, which will be used to create a new node at
     // the end of the linked list
     void insEnd(int); // int datum
     // This function will delete the first node of the linked list.
     int delBeg();
     // This function will delete the last node of the linked list.
     int delEnd();
     // This function will display the linked list.
     void view();
     int getSize();
     int getDat(int);
     Node* getHead();
     Node* getTail();
     bool isEmpty();
};

class Stack {
     List *stack;
public:
     Stack();
     ~Stack();
     void push(int);     // Adds something to the top of the stack
     int pop();          // Tells you whatever is at the top of the stack and removes it
     int peek();         // Tells you whatever is at the top of the stack
     bool empty();       // Empties out the stack
     void print();       // Prints out the stack to the console
};

class Queue {
     List *queue;
public:
     Queue();
     ~Queue();
     void push(int);     // Adds something to the top of the stack
     int pop();          // Tells you whatever is at the top of the stack and removes it
     int peek();         // Tells you whatever is at the top of the stack
     bool empty();       // Empties out the queue
     void print();       // Prints out the queue to the console
};
