class Node {
public:
     int datum;
     Node *next;
     Node *prev;
     Node(int);
}

class LinkedList {
private:
     Node *head;
     Node *tail;
     int size;
     void destr_helper(Node *head);
public:
     LinkedList();
     ~LinkedList();
     void insert(int,int)
     int remove(int);
     int get(int);
     void set(int,int);
     int getSize();
}

class Stack {
     LinkedList *stack;
public:
     Stack();
     ~Stack();
     void push(int);     // Adds something to the top of the stack
     int pop();          // Tells you whatever is at the top of the stack and removes it
     int peek();         // Tells you whatever is at the top of the stack
}
