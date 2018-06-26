#include "bst.h"
#include <iostream>

BST::Node::Node(int datum) {
     this->left = 0;
     this->right = 0;
     this->parent = 0;
     this->datum = datum;
}

BST::BST() {
     this->root = 0;
}

void BST::destr_helper(Node* node) {
     if(node) {
          this->destr_helper(node->left);
          this->destr_helper(node->right);
          delete node;
     }
}

BST::~BST() {
     this->destr_helper(this->root);
}

void BST::ins(int datum) {
     Node* newNode = new Node(datum);
     if(this->root == 0) {
          this->root = newNode;
     } else {
          this->ins_helper(this->root, newNode);
     }
}

void BST::ins_helper(Node* node, Node* newNode) {
     if(node->datum == newNode->datum) {
          throw NoDups();
     } else if (newNode->datum < node->datum) {
          if(node->left) {
               this->ins_helper(node->left, newNode);
          } else {
               node->left = newNode;
          }
     } else {
          if(node->right) {
               this->ins_helper(node->right, newNode);
          } else {
               node->right = newNode;
          }
     }
}


BST::Node* BST::find(int datum) {
     Node* temp = this->root;
     while(temp && temp->datum != datum) {
          if(datum < temp->datum) {
               temp = temp->left;
          } else {
               temp = temp->right;
          }
     }
     return temp;
}

BST::Node* BST::find_main(int datum) {
     Node* temp = this->root;
     while(temp && temp->datum != datum) {
          if(datum < temp->datum) {
               temp = temp->left;
          } else {
               temp = temp->right;
          }
     }
     if(temp == 0) {
          throw NotFound();
     }
     return temp;
}

void BST::del(int datum) {
     bool isLeftChild = false;
     bool isRoot = false;
     Node* temp1 = this->find(datum);
     if(!temp1) {
          throw NotFound();
     } else {
          if(temp1->parent) {
               isRoot = false;
               if(temp1->parent->left == temp1) {
                    isLeftChild = true;
               } else {
                    isLeftChild = false;
               }
          } else {
               isRoot = true;
          }

          if(!temp1->left) {
               if(!temp1->right) {
                    if(isRoot) {
                         this->root = 0;
                    } else if(isLeftChild) {
                         temp1->parent->left = 0;
                    } else {
                         temp1->parent->right = 0;
                    }
               } else {
                    if(isRoot) {
                         this->root = temp1->right;
                    } else {
                         if(isLeftChild) {
                              temp1->parent->left = temp1->right;
                         } else {
                              temp1->parent->right = temp1->right;
                         }
                    }
               }
               delete temp1;
          } if(!temp1->right) {
               if(!temp1->left) {
                    if(isRoot) {
                         this->root = 0;
                    } else if(isLeftChild) {
                         temp1->parent->left = 0;
                    } else {
                         temp1->parent->right = 0;
                    }
               } else {
                    if(isRoot) {
                         this->root = temp1->left;
                    } else {
                         if(isLeftChild) {
                              temp1->parent->left = temp1->left;
                         } else {
                              temp1->parent->right = temp1->left;
                         }
                    }
               }
               delete temp1;
          } else {
               Node* temp2 = temp1->left;
               if(temp2->right == 0) {
                    // Moves the left datum into the parent spot
                    temp1->datum = temp2->datum;
                    // Moves the node of that node to the parent spot
                    temp1->left = temp2->left;
               } else {
                    // While we can keep going...
                    while(temp2->right != 0) {
                         // Keep going right
                         temp2 = temp2->right;
                    }
                    temp1->datum = temp2->datum;
                    temp2->parent->right = temp2->left;
               }
               delete temp2;
          }
     }
}

void BST::traverse(int choice) {
     if(choice == 1) {
          this->pre_order(this->root);
     } else if (choice == 2) {
          this->in_order(this->root);
     } else if (choice == 3) {
          this->post_order(this->root);
     }
}

void BST::pre_order(Node* node) {
     if(!node) {
          return;
     } else {
          std::cout << node->datum << std::endl;
          this->pre_order(node->left);
          this->pre_order(node->right);
     }
}

void BST::in_order(Node* node) {
     if(!node) {
          return;
     } else {
          this->in_order(node->left);
          std::cout << node->datum << std::endl;
          this->in_order(node->right);
     }
}

void BST::post_order(Node* node) {
     if(!node) {
          return;
     } else {
          this->post_order(node->left);
          this->post_order(node->right);
          std::cout << node->datum << std::endl;
     }
}
