#include <queue>
#include <map>
#include <list>
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

class Graph {
     class Edge {
     public:
          class Node {
          public:
               char label;
               int distToSrc, index;
               std::list<Node*> adjList;
               Node(char);
               Node(char,int);
          };
          // void add_node_(char);
          // void remove_node_(Node*);
          int weight;
          Node *nodeTo, *nodeFrom;
          std::pair <Node*,Node*> path(nodeTo,nodeFrom);
          Edge(Node*,Node*,int);
          ~Edge();
     };
     std::map<char,Node*> nodeMap;
     std::map <std::pair<Node*,Node*>,Edge*> edgeMap;
     Edge* add_edge_(Node*,Node*,int);
     Node* add_node_(char);
     void remove_edge_(Edge*);
     void remove_node_(Node*);
     void dijkstra_(Node*);

public:
     int size;
     void add_node(char);
     void add_edge(char,char,int);
     void remove_edge(char,char);
     void remove_node(char);
     void dijkstra(char);
     std::priority_queue<int> unvisitedNodes;
     std::priority_queue<int> visitedNodes;
     std::priority_queue<int> edgesQueue;
     std::map<char,int> mapNodes;
     Graph();
     Graph(char);
     ~Graph();
}
