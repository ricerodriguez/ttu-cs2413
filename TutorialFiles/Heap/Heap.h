class Heap {
     class Node {
     public:
          Node *left, *right, *parent;
          int datum;
          Node(int);

     };
     Node *root;
     void upheap(Node*);
     void downheap(Node*);
     // Destructor helper
     void destr_helper(Node*);
public:
     Heap();
     ~Heap();
     // Heaps are used for priority queues, so we're calling the insert and remove functions push
     // and pop and they'll behave like a push/pop on a queue
     void push(int);
     int pop();
};
