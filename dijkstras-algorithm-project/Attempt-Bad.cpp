#include "Attempt-Bad.h"
#include <vector>
#include <map>

Graph::Edge::Node::Node(char label) {
     this->label = label;
     this->weight = 2147483647; // maximum value for int
     // this->left = 0;
     // this->right = 0;
     // this->parent = 0;
}

Graph::Edge::Edge(Node *nodeTo, Node *nodeFrom, int weight) {
     this->weight = weight;
     this->nodeTo = nodeTo;
          this->adjNodesMap[nodeTo->label] = nodeTo;
          this->adjNodes.push_back(nodeTo->weight);
     this->nodeFrom = nodeFrom;
          this->adjNodesMap[nodeFrom->label] = nodeFrom;
          this->adjNodes.push_back(nodeFrom->weight);
}


Graph::Edge::~Edge() {
     this->adjNodes.clear();
     this->adjNodesMap.clear();
}

Graph::Graph() {
     this->start = 0;
     this->end = 0;
     this->nextShortestEdge = 0;
     this->nextShortestEdgeList = 0;
}

Graph::Graph(Node* start, char label) {

}

void Graph::add_node(char label) {
     int i = 0;
     for (; i < this->nodesList.size() && this->nodesList[i]->label != label; i++);
     if (this->nodesList[i]->label == label) {
          throw NoDups();
     } else {
          Node *newNode = new Node(label);
     }
}

void Graph::add_edge(char labelFrom, char labelTo, int weight) {
     // Check if edge exists already
     int i = 0, j = 0, k = 0;
     Edge *currEdge;
     Node *currNodeTo, *currNodeFrom,
          *nodeTo, *nodeFrom;
     for (; i < this->edgesList.size() && currEdge->nodeTo->label != labelTo
          && currEdge->nodeFrom->label != labelFrom; i++) {
          currEdge = this->edgesList[i];
     }
     if (currEdge->nodeTo->label == labelTo && currEdge->nodeFrom->label == labelFrom) {
          throw EdgeExists();
     } else {
          for (; j < this->nodesList.size() && currNodeTo->label != labelTo; j++) {
               currNodeTo = this->nodesList[j];
          }
          if (currNodeTo->label != labelTo) {
               throw NodeNotFound();
          } else {
               nodeTo = currNodeTo;
          }
          for (; k < this->nodesList.size() && currNodeFrom->label != labelFrom; k++) {
               currNodeFrom = this->nodesList[k];
          }
          if (currNodeFrom->label != labelFrom) {
               throw NodeNotFound();
          } else {
               nodeFrom = currNodeFrom;
          }
     }

     Edge *newEdge = new Edge(nodeTo, nodeFrom, weight);
     this->edgesList.push_back(newEdge);
     nodeTo->mapIn[nodeFrom] = newEdge;
     nodeFrom->mapOut[nodeTo] = newEdge;
     nodeTo->adjEdges.push_back(newEdge);
     nodeFrom->adjEdges.push_back(newEdge);

}

void Graph::remove_edge(char labelFrom, char labelTo) {
     // Edge *edgeKill = this->edgesList.front();
     Edge *currEdge;
     Node *currNodeTo, *currNodeFrom;
     int index = 0;
     for (; index < this->edgesList.size()
          && currNodeTo->label != labelTo
          && currNodeFrom->label != labelFrom; index++) {
               currEdge = this->edgesList[index];
               currNodeTo = currEdge->nodeTo;
               currNodeFrom = currEdge->nodeFrom;
          }
     if (currNodeTo->label != labelTo || currNodeFrom->label != labelFrom) {
          throw EdgeNotFound();
     } else {
          currEdge->nodeTo = 0;
          currEdge->nodeFrom = 0;
          currEdge->adjNodes.clear();
          currEdge->adjNodesMap.clear();
          this->edgesList.erase(index);
          int imapIn, imapOut, ilistTo, ilistFrom;
          imapIn = currNodeTo->mapIn.find(currNodeFrom);
          imapOut = currNodeFrom->mapOut.find(currNodeTo);
          currNodeTo->mapIn.erase(imapIn);
          currNodeFrom->mapOut.erase(imapOut);
          for (ilistTo = 0; ilistTo < currNodeTo->adjList.size()
               && currNodeTo->adjList[ilistTo]->nodeFrom != currNodeFrom; ilistTo++);
          for (ilistFrom = 0; ilistFrom < currNodeFrom->adjList.size()
               && currNodeFrom->adjList[ilistFrom]->nodeTo != currNodeTo; ilistFrom++);

          currNodeTo->adjList.erase(ilistTo);
          currNodeFrom->adjList.erase(ilistFrom);
          // currNodeTo->adjEdges.erase()
     }
}

void Graph::remove_node(char label) {
     int i = 0, j = 0;
     for (; i < this->nodesList.size() && this->nodesList[i]->label != label; i++);
     if (this->nodesList[i]->label != label) {
          throw NodeNotFound();
     } else {
          Node* kill = this->nodesList[i];
          for (; j < kill->mapIn.size(); j++) {
               // each node in the map gets the edge connecting it to the node to be removed deleted
               kill->mapIn
          }
          kill->mapIn.clear();
          kill->mapOut.clear();
          kill->adjEdges.clear();
          this->nodesList.erase(i);
     }
}
