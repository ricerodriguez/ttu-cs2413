#include "Attempt.h"

Graph::Graph(bool directed) {
     this->order = 0;
     this->directed = directed;
     this->vertices = 0;
     this->heap = 0;
}

void Graph::destr_helper(Vertex* vert) {
     if(vert) {
          this->destr_helper(vert->next);
          delete node;
     }
}

Graph::~Graph() {
     this->destr_helper(this->vertices);
}

Graph::Vertex::Vertex(char label) {
     this->label = label;
     this->distance = 0;
     this->index = 0;

}
