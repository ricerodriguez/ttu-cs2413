#include <map>
#include <list>
#include <queue>
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
     char label;
     int distToSrc, index;
     std::list<Node*> adjList;
     Node(char);
     Node(char,int);
};

typedef std::pair<Node*,Node*> NodePair;

class Edge {
     friend class Graph;
public:
     // void add_node_(char);
     // void remove_node_(Node*);
     int weight;
     Node *nodeTo, *nodeFrom;
     NodePair path;
     Edge(Node*,Node*,int);
     ~Edge();
};

class Graph {
     friend class Node;
     std::map <char,Node*> nodeMap;
     std::map <Node*,char> revNodeMap;
     std::map <char,int> nodeMapWt;
     std::map <NodePair,Edge*> edgeMap;
     std::map <int,Edge*> edgeMapWt;

     Edge* add_edge_(Node*,Node*,int);
     Node* add_node_(char);
     void remove_edge_(Edge*);
     void remove_node_(Node*);
     void BFT_(Node*);

public:
     bool operator () (Node*, Node*);
     Node* start;
     int size;
     void add_node(char);
     void add_edge(char,char,int);
     void remove_edge(char,char);
     void remove_node(char);
     void print_nodes();
     std::priority_queue<Node*> unvisitedNodes;
     std::priority_queue<Node*> visitedNodes;
     std::priority_queue<Edge*> edgesQueue;
     Graph();
     Graph(char);
     ~Graph();
};
