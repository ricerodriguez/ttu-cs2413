// // A graph is a Standard Library vector of vertices. Each vertex has an Standard
// // Library vector of edges. The vertices and edges can have associated
// // information (cost, names, etc)
// #include <vector>
//
// class Graph {
//      class Edges {
//      public:
//           class Node {
//           public:
//                char label, *edges;
//                Node *left, *right, *parent;
//                Node(char);
//                // std::vector<char> edges;
//           };
//           int weight;
//           Node **nodes;
//           // Node *root;
//      };
//      int order;
//      bool isDirected;
//      std::vector<char> nodes;
// public:
//      add_node(char);
//      add_edge(char,char,int);
//      remove_edge(char,char);
//      remove_node(char);
//      dijkstra(char);
// }

#include <queue>
#include <map>
struct EdgeNotFound : public std::exception {
     const char * what () const throw () {
          return "The edge you're looking for couldn't be found! ";
     }
};

struct NodeNotFound : public std::exception {
     const char * what () const throw () {
          return "The node you're looking for couldn't be found! ";
     }
};

struct EdgeExists : public std::exception {
     const char * what () const throw () {
          return "The edge you're trying to add already exists! ";
     }
};

struct NodeConnected : public std::exception {
     const char * what () const throw () {
          return "Node cannot be deleted because it is connected to other nodes! Remove edges to/from this node and try again. ";
     }
};

struct NoDups : public std::exception {
     const char * what () const throw () {
          return "No duplicate nodes allowed! Choose a different label and try again. ";
     }
};


class Graph {
     class Edge {
     public:
          class Node {
          public:
               char label;
               int weight;
               // Node *left, *right, *parent;
               Node(char);
               std::map<Node*,Edge*> mapOut;
               std::map<Node*,Edge*> mapIn;
               std::priority_queue<Node*> adjEdges;
          };
          Node *nodeTo, *nodeFrom;
          std::vector<int> adjNodes; // ints so that standard library can order
          std::map<char,Node*> adjNodesMap;
          int weight;
          // void destr_helper(Node*);
          Edge(Node*,Node*,int,bool); // node to, node from, weight
          ~Edge();
     }
     Edge *nextShortestEdge;
     Node *start, *end;
     std::priority_queue<Edge*> edgesList;
     std::priority_queue<Node*> nodesList;
     void add_node(char);
     void add_edge(char,char,int);
     void remove_edge(char,char);
     void remove_node(char);
     void dijkstra(char);
     Graph();
     Graph(Node*,char);
     ~Graph();
}
