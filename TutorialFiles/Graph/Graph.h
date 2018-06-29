#include <iostream>
#define UNDIRECTED false
#define DIRECTED true
using namespace std;

class Graph {
     class List;
     class Vertex {
     public:
          char label;
          int dist, // distance from source node to that node..?
              index;
          List *adjList; // datum of each node is a vertex
          Vertex *next, *prev, *prior;
          Vertex(char);
          ~Vertex();
     };

     class List {
     public:
          class Node {
               Vertex *datum;
               Node *next, *prev;
               int dist; // length of the edge
               Node(Vertex*,int);
          };
          Node *head;
          void destr_helper(Node*);
          List();
          ~List();
          void add(Vertex*,int);
          void rem(char);
          bool contains(char);
     };

     class PQueue {
          Vertex **heap; // pointer to a pointer, pointer to array of pointers, elements of array are pointer to a vertex
          int tail;
          int parent(int);
          int left(int);
          int right(int);
          void swap(int,int);
     public:
          PQueue();
          ~PQueue();
          void upheap(int);
          void downheap(int);
          void heapify(Vertex*,int);
          Vertex *pop;
          bool isEmpty();
     };

     Vertex *vertices;
     PQueue *dijQueue;
     int order;
     bool directed;
     bool has_vert(char);
     void destr_helper(Vertex*);
     void trace_path(Vertex*);
public:
     Graph(bool);
     ~Graph();
     friend ostream& operator<<(ostream&, Graph&);
     void add_vert(char);
     void add_edge(char,char,char);
     void rem_vert(char);
     void rem_edge(char,char);
     void dijkstra(char);
};
