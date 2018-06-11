#include "Stack.h"

Node::Node(int datum) {
     this->next = 0;
     this->datum = datum;
}

Stack::Stack(){
     this->head = 0;
}

void Stack::destr_helper(Node *node) {
     if(node) {
          this->destr_helper(node->next);
          delete node;
     }
}

Stack::~Stack() {
     this->destr_helper(this->head);
}
