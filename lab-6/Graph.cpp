#include <map>
#include <list>
#include <queue>
#include <utility>
#include <iostream>
#include "Graph.h"

bool Graph::operator () (Node* nodeA, Node* nodeB) {
     char labelA = this->revNodeMap.find(nodeA)->second;
     char labelB = this->revNodeMap.find(nodeB)->second;
     if (nodeMapWt.at(labelA)<nodeMapWt.at(labelB)) {
          return true;
     } else {
          return false;
     }

}

Node::Node(char label) {
     this->label = label;
     this->distToSrc = 2147483647; // max of int
     this->adjList.clear();
     // Graph g;
     // g.nodeMap[label] = this;
}

Node::Node(char label, int distToSrc) {
     this->label = label;
     this->distToSrc = distToSrc;
     this->adjList.clear();
}

Edge::Edge(Node* nodeFrom, Node* nodeTo, int weight) {
     this->nodeFrom = nodeFrom;
     this->nodeTo = nodeTo;
     this->weight = weight;
     this->path = std::make_pair(nodeFrom,nodeTo);
}

Edge::~Edge() {
     delete this->nodeTo;
     delete this->nodeFrom;
}

Graph::Graph() {
     this->size = 0;
}

Graph::Graph(char label) {
     Node* start = this->add_node_(label);
     this->start = start;
     // this->unvisitedNodes.push(start->distToSrc);
}

Graph::~Graph() {
     this->size = 0;
     while (!this->unvisitedNodes.empty()) {
          this->unvisitedNodes.pop();
     }
     while (!this->visitedNodes.empty()) {
          this->visitedNodes.pop();
     }
     while (!this->edgesQueue.empty()) {
          this->edgesQueue.pop();
     }
     this->nodeMap.clear();
     this->revNodeMap.clear();
     this->nodeMapWt.clear();
     this->edgeMap.clear();
     delete this;
}

void Graph::remove_edge_(Edge *killEdge) {
     killEdge->path = std::make_pair(killEdge->nodeFrom, killEdge->nodeTo);
     killEdge->nodeTo->adjList.remove(killEdge->nodeFrom);
     killEdge->nodeFrom->adjList.remove(killEdge->nodeTo);
     killEdge->nodeTo = 0;
     killEdge->nodeFrom = 0;
     this->edgeMap.erase(killEdge->path);
     this->edgeMapWt.erase(killEdge->weight);
     killEdge->path = std::make_pair(killEdge->nodeFrom, killEdge->nodeTo);
     killEdge = 0;
     // delete killEdge;
}

void Graph::remove_node_(Node *killNode) {
     this->nodeMap.erase(killNode->label);
     this->revNodeMap.erase(killNode);
     this->nodeMapWt.erase(killNode->label);
     // Remove edges connected to node
     Node *currNode = killNode->adjList.back();
     Edge *killEdge;
     // Go through list of adjacent nodes, start at the top
     while (!killNode->adjList.empty()) {
          currNode = killNode->adjList.back();
          // If there's an edge from the current node in the adjacency list to the node we're removing, remove it
          if (this->edgeMap.count(std::make_pair(currNode,killNode))) {
               // this->edgeMap.erase(std::make_pair(currNode,killNode));
               killEdge = this->edgeMap.find(std::make_pair(currNode,killNode))->second;
               this->remove_edge_(killEdge);
          } else if (this->edgeMap.count(std::make_pair(killNode,currNode))) {
               killEdge = this->edgeMap.find(std::make_pair(killNode,currNode))->second;
               this->remove_edge_(killEdge);
          }
          killNode->adjList.pop_back();
     }
}

Edge* Graph::add_edge_(Node* nodeFrom, Node* nodeTo, int weight) {
     // Does this edge already exist? Check the map of the edges for anything from nodeFrom to nodeTo.
     // if (this->edgeMap.find(std::make_pair(nodeFrom,nodeTo))->first == std::make_pair(nodeFrom,nodeTo)) {
     if (this->edgeMap.count(std::make_pair(nodeFrom,nodeTo))) {
          // If there was an edge going from that nodeFrom to that nodeTo, throw an error because it already exists
          throw EdgeExists();
     } else {
          // Otherwise, create a new edge
          Edge *newEdge = new Edge(nodeFrom, nodeTo, weight);
          this->edgeMap[std::make_pair(nodeFrom, nodeTo)] = newEdge;
          this->edgeMapWt[weight] = newEdge;
          nodeFrom->adjList.push_back(nodeTo);
          nodeTo->adjList.push_back(nodeFrom);
          return newEdge;
     }
}

Node* Graph::add_node_(char label) {
     Node *newNode;
     if (this->nodeMap.count(label)) {
          throw NoDups();
     } else {
          newNode = new Node(label);
          // newNode->index = this->nodeMap.size();
          this->nodeMap[label] = newNode;
          this->revNodeMap[newNode] = label;
          this->size++;
          this->nodeMapWt[label] = 2147483647; // max weight
     }
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

void Graph::print_nodes() {
     std::cout << "Nodes: " << std::endl;
     for (std::map<char,int>::iterator it = this->nodeMapWt.begin(); it != this->nodeMapWt.end(); ++it) {
          std::cout << "Node " << it->first << " is currently weighted at " << it->second << std::endl;
     }
}

void Graph::BFT_(Node* start) {
     // First, clear the queues
     while (!unvisitedNodes.empty()) {
          unvisitedNodes.pop();
     }
     while (!visitedNodes.empty()) {
          visitedNodes.pop();
     }

     // Push starting node onto unvisited node queue
     unvisitedNodes.push(start);
     // Create Node objects to work with
     Node *node = start;
     Node *adjNode;
     while (!unvisitedNodes.empty()) {
          // Set working node to whatever is at the top of the unvisited nodes queue
          node = unvisitedNodes.top();
          //
          while (!node->adjList.empty()) {
               // Set adjacent node to the first node on the working node's adjacent nodes list
               adjNode = node->adjList.front();
               // Print out the working node and its connection to the adjacent node
               std::cout << "Node " << node->label << " is connected to node " << adjNode->label << "." << std::endl;
               unvisitedNodes.push(adjNode);
               visitedNodes.push(start);
               // adjList.pop_front();
          }
     }
}
