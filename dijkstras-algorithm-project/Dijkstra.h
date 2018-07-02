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

struct EdgesThere : public std::exception {
     const char * what () const throw () {
          return "There are edges connected to this node. Delete those edges first! ";
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

struct InvStart : public std::exception {
     const char * what () const throw () {
          return "You can't use this node as a starting position because there are no outgoing edges connected to it! ";
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
     // NodePair path;
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
typedef std::priority_queue<Edge*, std::vector<Edge*>, EdgeQueueSorter> EdgeQueue;

class Graph {
     friend class Node;
     std::map <char,Node*> nodeMap;
     std::map <Node*,char> revNodeMap;
     std::map <char,int> nodeMapWt;
     std::map <NodePair,Edge*> edgeMap;
     std::map <Edge*,int> edgeMapWt;

     void BFT_(Node*);
     void dijkstra_(Node*,Node*);
     Node* add_node_(char);
     void remove_edge_(Edge*);
     void remove_node_(Node*);
     int distToNode_(Node*,Node*);
     Edge* add_edge_(Node*,Node*,int);
     bool hasOutgoingEdges_(Node*);
     void updateDist_(Node*);

public:
     int size;
     Node* start;
     void BFT(char);
     void print_nodes();
     void dijkstra(char,char);
     void add_node(char);
     void remove_node(char);
     void remove_edge(char,char);
     void add_edge(char,char,int);
     NodeQueue unvisitedNodes;
     EdgeQueue edgesQueue;
     NodeQueue finalQueue;
     std::vector<Node*> visitedNodes;
     Graph();
     Graph(char);
     ~Graph();
};
