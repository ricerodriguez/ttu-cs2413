class Graph {
     Vertex *vertices;
     PQueue *heap;
     int order;
     bool directed;
     bool has_vert(char);
     void destr_helper(Vertex*);
     void trace_path(Vertex*);
public:
     Graph(bool);
     ~Graph();
     void add_node(char);
     void add_edge(char,char,int);
     void remove_edge(char,char);
     void remove_node(char);
     void dijkstra(char);


     class List;
     class Vertex {
     public:
          char label;
          int distance, index;
          List *adjList;
          Vertex *next, *prev;
          Vertex(char);
          ~Vertex();
     };

     class List {
     public:
          class Node {
               Vertex *datum;
               Node *next, *prev;
               int distance;
               Node(Vertex*,int);
          };
          Node *head;
          void destr_helper(Node*);
          List();
          ~List();
          void add(Vertex*,int);
          void kill(char);
     };

     class PQueue {
          int *arr, tail, size;
          void upheap(int);
          void downheap(int);
          int parent(int);
          int right(int);
          int left(int);
          void swap(int, int);
          void clear();
     public:
          PQueue();
          ~PQueue();
          void push(int);
          int pop();
          bool isEmpty();
          void heapify(int*,int);
     };
};
