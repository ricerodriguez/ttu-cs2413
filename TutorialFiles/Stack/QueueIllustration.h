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

class Queue {
     LinkedList *queue;
public:
     Queue();
     ~Queue();
     void push(int);     // Adds something to the bottom of the queue
     int pop();          // Tells you whatever is at the top of the queue and removes it
     int peek();         // Tells you whatever is at the top of the queue
}
