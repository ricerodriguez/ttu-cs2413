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
     Heap(int*,int);
     ~Heap();
     // Heaps are used for priority queues, so we're calling the insert and remove functions push
     // and pop and they'll behave like a push/pop on a queue
     void push(int);
     int pop();
     void heapify(int*, int);
};

class ArrHeap {
     int *arr, tail, size;
     void upheap(int);
     void downheap(int);
     int parent(int);
     int right(int);
     int left(int);
     void swap(int, int);
public:
     ArrHeap();
     ~ArrHeap();
     void push(int);
     int pop();
     void heapify(int*,int);

}
