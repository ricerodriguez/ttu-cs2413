class Node {
public:
     int datum;
     Node *next;
     Node();
}

class ListStack {
     Node *head;
     void destr_helper(Node*);
public:
     ListStack();
     ~ListStack();
     void push(int);
     int pop();
     int peek();
     bool isEmpty();
}

class ArrStack {
     int *head, curr, size;
public:
     ArrStack();
     ~ArrStack();
     void push(int);
     int pop();
     int peek();
     bool isEmpty();
}
