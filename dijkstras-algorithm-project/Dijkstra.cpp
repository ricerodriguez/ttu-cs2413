#include <map>
#include <queue>
#include <list>
#include <utility>
#include "Dijkstra.h"


Graph::Edge::Node::Node(char label) {
     this->label = label;
     this->distToSrc = 2147483647; // max of int
     this->adjList = 0;
}

Graph::Edge::Node::Node(char label, int distToSrc) {
     this->label = label;
     this->distToSrc = distToSrc;
     this->adjList = 0;
}

Graph::Edge::Edge(Node* nodeFrom, Node* nodeTo, int weight) {
     this->nodeFrom = nodeFrom;
     this->nodeTo = nodeTo;
     this->weight = weight;
     this->path = std::make_pair(nodeFrom,nodeTo);
}

Graph::Edge::~Edge() {

}

Graph::Graph(char label) {
     Node* start = this->add_node_(label);
     this->unvisitedNodes.push(start->distToSrc);
}

Graph::~Graph() {

}

void Graph::remove_edge_(Edge *killEdge) {
     killEdge->path = std::make_pair(killEdge->nodeFrom, killEdge->nodeTo);
     killEdge->nodeTo->adjList.remove(killEdge->nodeFrom);
     killEdge->nodeFrom->adjList.remove(killEdge->nodeTo);
     killEdge->nodeTo = 0;
     killEdge->nodeFrom = 0;
     this->edgeMap.erase(killEdge->path);
     killEdge->path = 0;
     killEdge = 0;
     // delete killEdge;
}

void Graph::remove_node_(Node *killNode) {
     this->nodeMap.erase(killNode->label);
     // Remove edges connected to node
     Node *currNode = killNode->adjList.front();
     Edge *killEdge;
     // Go through list of adjacent nodes, start at the top
     while (!killNode->adjList.empty()) {
          currNode = killNode->adjList.front();
          // If there's an edge from the current node in the adjacency list to the node we're removing, remove it
          if (this->edgeMap.count(std::make_pair(currNode,killNode))) {
               // this->edgeMap.erase(std::make_pair(currNode,killNode));
               killEdge = this->edgeMap.find(std::make_pair(currNode,killNode))->second;
               this->remove_edge_(killEdge);
          } else if (this->edgeMap.count(std::make_pair(killNode,currNode))) {
               killEdge = this->edgeMap.find(std::make_pair(killNode,currNode))->second;
               this->remove_edge_(killEdge);
          }
          killNode->adjList.pop_front();
     }
}

Graph::Edge* Graph::add_edge_(Node* nodeFrom, Node* nodeTo, int weight) {
     // Does this edge already exist? Check the map of the edges for anything from nodeFrom to nodeTo.
     // if (this->edgeMap.find(std::make_pair(nodeFrom,nodeTo))->first == std::make_pair(nodeFrom,nodeTo)) {
     if (this->edgeMap.count(std::make_pair(nodeFrom,nodeTo))) {
          // If there was an edge going from that nodeFrom to that nodeTo, throw an error because it already exists
          throw EdgeExists();
     } else {
          // Otherwise, create a new edge
          Edge *newEdge = new Edge(nodeFrom, nodeTo, weight);
     }
     return newEdge;
}

Graph::Edge::Node* Graph::add_node_(char label) {
     if (this->nodeMap.count(label)) {
          throw NoDups();
     } else {
          Node *newNode = new Node(label);
          // newNode->index = this->nodeMap.size();
     }
     this->size++;
     return newNode;
}

void Graph::add_node(char label) {
     this->add_node_(label);
}

void Graph::add_edge(char labelFrom, char labelTo, int weight) {
     if (!this->nodeMap.count(labelFrom) || !this->nodeMap.count(labelTo)) {
          throw NodeNotFound();
     } else {
          Node *nodeFrom = this->nodeMap.find(labelFrom)->second;
          Node *nodeTo = this->nodeMap.find(labelTo)->second;
          this->add_edge_(nodeFrom, nodeTo, weight);
     }
}

void Graph::remove_edge(char labelFrom, char labelTo) {
     if (!this->nodeMap.count(labelFrom) || !this->nodeMap.count(labelTo)) {
          throw NodeNotFound();
     } else {
          Node *nodeFrom = this->nodeMap.find(labelFrom)->second;
          Node *nodeTo = this->nodeMap.find(labelTo)->second;
          if (!this->edgeMap.count(std::make_pair(nodeFrom,nodeTo))) {
               throw EdgeNotFound();
          } else {
               Edge *killEdge = this->edgeMap.find(std::make_pair(nodeFrom,nodeTo))->second;
               this->remove_edge_(killEdge);
          }
     }
}

void Graph::remove_node(char label) {
     if (!this->nodeMap.count(label)) {
          throw NodeNotFound();
     } else {
          Node *killNode = this->nodeMap.find(label)->second;
          this->remove_node_(killNode);
     }
}
