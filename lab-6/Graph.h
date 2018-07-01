#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <exception>

struct EdgeExists : public std::exception {
     const char * what () const throw () {
          return "The edge you're trying to add already exists! ";
     }
};

struct NoDups : public std::exception {
     const char * what () const throw () {
          return "No duplicate nodes allowed! Choose a different label and try again. ";
     }
};

struct NodeNotFound : public std::exception {
     const char * what () const throw () {
          return "The node you're looking for couldn't be found! ";
     }
};

struct EdgeNotFound : public std::exception {
     const char * what () const throw () {
          return "The edge you're looking for couldn't be found! ";
     }
};


class Node {
     friend class Edge;
     friend class Graph;
public:
     Node(char);
     Node(char,int);
     char label;
     int distToSrc, index;
     std::vector<Node*> adjVect;
};

typedef std::pair<Node*,Node*> NodePair;

class Edge {
     friend class Graph;
public:
     Edge(Node*,Node*,int);
     ~Edge();
     int weight;
     Node *nodeTo, *nodeFrom;
     NodePair path;
};

struct NodeQueueSorter {
     bool operator() (Node* a, Node *b) {
          return a->distToSrc > b->distToSrc;
     }
};

struct EdgeQueueSorter {
     bool operator() (Edge* a, Edge *b) {
          return a->weight > b->weight;
     }
};


typedef std::priority_queue<Node*, std::vector<Node*>, NodeQueueSorter> NodeQueue;


class Graph {
     friend class Node;
     std::map <char,Node*> nodeMap;
     std::map <Node*,char> revNodeMap;
     std::map <NodePair,Edge*> edgeMap;

     void BFT_(Node*);
     Node* add_node_(char);
     Edge* add_edge_(Node*,Node*,int);

public:
     int size;
     Node* start;
     void BFT(char);
     void add_node(char);
     void add_edge(char,char,int);
     Graph();
     Graph(char);
     ~Graph();
     NodeQueue unvisitedNodes;
     std::vector<Node*> visitedNodes;
};
