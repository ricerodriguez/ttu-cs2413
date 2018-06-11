class Node {
public:
     int datum;
     Node *next;
     Node();
}

class Stack {
     Node *head;
     void destr_helper(Node*);
public:
     Stack();
     ~Stack();
     void push(int);
     int pop();
     int peek();
     int empty();
}
