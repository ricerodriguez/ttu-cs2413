#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include "Graph.h"

Node::Node(char label) {
     this->label = label;
     this->distToSrc = 2147483647; // max of int
     this->adjVect.clear();
}

Node::Node(char label, int distToSrc) {
     this->label = label;
     this->distToSrc = distToSrc;
     this->adjVect.clear();
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
}

Graph::~Graph() {
     this->size = 0;
     while (!this->unvisitedNodes.empty()) {
          this->unvisitedNodes.pop();
     }
     while (!this->visitedNodes.empty()) {
          this->visitedNodes.pop_back();
     }

     this->nodeMap.clear();
     this->revNodeMap.clear();
     this->edgeMap.clear();
     delete this;
}

void Graph::add_node(char label) {
     this->add_node_(label);
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
     }
     return newNode;
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
          nodeFrom->adjVect.push_back(nodeTo);
          nodeTo->adjVect.push_back(nodeFrom);
          return newEdge;
     }
}

void Graph::BFT(char label) {
     if (!this->nodeMap.count(label)) {
          throw NodeNotFound();
     } else {
          Node *node = this->nodeMap.find(label)->second;
          this->BFT_(node);
     }
}

void Graph::BFT_(Node* start) {
     bool foo = false;
     // First, clear the queues
     while (!unvisitedNodes.empty()) {
          unvisitedNodes.pop();
     }
     while (!visitedNodes.empty()) {
          visitedNodes.pop_back();
     }
     // Create iterator for searching through the queue
     std::vector<Node*>::iterator i_node, i_temp;
     // std::map<Node*,char>::iterator i_map;
     // Create Node objects to work with
     Node *node = start;
     // Node *temp;
     Node *adjNode;
     // Create a copy of the adjacent list vector so we can pop things off it
     // without affecting the actual list
     std::vector<Node*> tempAdjVect(node->adjVect);
     // Push starting node onto unvisited node queue
     unvisitedNodes.push(start);
     // While we still have unvisited nodes...
     while (!unvisitedNodes.empty()) {
          // Set working node to whatever is at the top of the unvisited nodes queue
          node = unvisitedNodes.top();
          // Set the temp adjacent vector to the new node's adjacent vector
          tempAdjVect = node->adjVect;
          // Pop the unvisited nodes queue since we're working with it now
          unvisitedNodes.pop();
          // Check if node is in the visited queue
          i_node = std::find(visitedNodes.begin(), visitedNodes.end(), node);
          if (i_node == visitedNodes.end()) {
               // Node is unvisited, visit each adjacent node
               if (tempAdjVect.empty()) {
                    std::cout << "Node " << node->label << " has no connections." << std::endl;
               } else {
                    std::cout << "Node " << node->label << " is connected to node";
                    if (tempAdjVect.size() > 1) {
                         std::cout << "s ";
                    }
               }
               // While we still haven't pushed all of the working node's adjacent nodes to the unvisited nodes queue...
               while (!tempAdjVect.empty()) {
                    // Visit by printing node and its adjacent nodes
                    // std::cout << "Node " << node->label << " is connected to " << tempAdjVect.back()->label << std::endl;
                    if (tempAdjVect.size() == 2 && !foo) {
                         std::cout << tempAdjVect.front()->label << " and";
                    } else if (tempAdjVect.size() > 1) {
                         std::cout << ' ' << tempAdjVect.front()->label << ",";
                         foo = true;
                    } else if (foo) {
                         std::cout << " and " << tempAdjVect.front()->label << ".\n";
                    } else {
                         std::cout << ' ' << tempAdjVect.front()->label << ".\n";
                    }
                    // Check if this adjacent node has been visited
                    i_temp = std::find(visitedNodes.begin(), visitedNodes.end(), tempAdjVect.front());
                    if (i_temp == visitedNodes.end()) {
                         // Node has not been visited, push it to the unvisited nodes queue
                         unvisitedNodes.push(tempAdjVect.front());
                    }
                    // We've printed the adjacent node and (if it was unvisited)
                    // pushed it to the unvisited queue, so we're done with it
                    // now. Pop it out.
                    tempAdjVect.erase(tempAdjVect.begin());
               }
               // Finished going through all of working node's adjacent nodes,
               // we're done with the node now. Push it to the visited nodes vector.
               visitedNodes.push_back(node);
          }

          if (this->unvisitedNodes.empty()) {
               // If there are no more unvisited nodes, check if there are any nodes in
               // the graph that aren't in the visited nodes
               for (std::map<Node*,char>::iterator it = revNodeMap.begin(); it != revNodeMap.end(); ++it) {
                    // Find the position of the node in the map
                    i_temp = std::find(visitedNodes.begin(), visitedNodes.end(), it->first);
                    // If the node from the graph was not in the visited nodes vector
                    if (i_temp == this->visitedNodes.end()) {
                         // Push the disconnected node to the unvisited nodes queue
                         unvisitedNodes.push(it->first);
                    }
               }
          }
     }
}
