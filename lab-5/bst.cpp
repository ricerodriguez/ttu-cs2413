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
               newNode->parent = node;
          }
     } else {
          if(node->right) {
               this->ins_helper(node->right, newNode);
          } else {
               node->right = newNode;
               newNode->parent = node;
          }
     }
}


BST::Node* BST::find_addr(int datum) {
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

void BST::find(int datum) {
     bool lastDirLeft = false;
     int count_left = 0;
     int count_right = 0;
     Node* temp = this->root;
     while(temp && temp->datum != datum) {
          if(datum < temp->datum) {
               if(temp == this->root) {
                    std::cout << "Starting the search at the left of the root..." << std::endl;
               } else if(!lastDirLeft) {
                    std::cout << "Went right for " << count_right << " nodes, now going left..." << std::endl;
                    count_right = 0;
               }
               temp = temp->left;
               lastDirLeft = true;
               count_left++;
          } else {
               if(temp == this->root) {
                    std::cout << "Starting the search at the right of the root..." << std::endl;
               } else if(lastDirLeft) {
                    std::cout << "Went left for " << count_left << " nodes, now going right..." << std::endl;
                    count_left = 0;
               }
               temp = temp->right;
               lastDirLeft = false;
               count_right++;
          }
     }
     if(!temp) {
          throw NotFound();
     } else if (temp == this->root) {
          std::cout << "Node was found at the root of the tree." << std::endl;
     } else if(lastDirLeft) {
          std::cout << "Went left for " << count_left << " nodes, where node with datum " << datum << " was found." << std::endl;
     } else {
          std::cout << "Went right for " << count_right << " nodes, where node with datum " << datum << " was found." << std::endl;
     }
}

// Descriptions of possibilities taken from GeeksForGeeks.org
void BST::del(int datum) {
     Node *kill = this->find_addr(datum);
     bool hasNoChildren = (!kill->left && !kill->right)?true:false;
     bool hasOneChild = ((!kill->left && kill->right) || (!kill->right && kill->left))?true:false;
     bool hasTwoChildren = (kill->left && kill->right)?true:false;
     if (hasNoChildren) {
          // There's no children, just delete and exit.
          if (kill == this->root) {
               // We're in the root, no need to change parents because there are none
               delete kill;
               return;
          } else if (kill->parent->left == kill) {
               kill->parent->left = 0;
          } else if (kill->parent->right == kill) {
               kill->parent->right = 0;
          }
          delete kill;
          return;
     } else if (hasOneChild) {
          // There's only one child. Copy the child to the node and delete the child.
          // First, determine which side child is on.
          if (!kill->left && kill->right) {
               // Nothing in left child, child must be on right.
               kill->datum = kill->right->datum;
               kill->right = 0;
               delete kill->right;
               return;
          } else if (!kill->right && kill->left) {
               // Nothing in right child, child must be on left.
               kill->datum = kill->left->datum;
               kill->left = 0;
               delete kill->left;
               return;
          } else {
               // Booleans on lines 114-116 are broken
               throw BrokBools();
          }
     } else if (hasTwoChildren) {
          // There's two children. Find in-order successor of the node. Copy
          // contents of the in-order successor to the node and delete the
          // in-order successor. Note that inorder predecessor can also be used.
          Node* temp = kill->right;
          while (temp->left) {
               temp = temp->left;
          }
          kill->datum = temp->datum;
          if (temp->parent->left == temp) {
               temp->parent->left = 0;
               return;
          } else if (temp->parent->right == temp) {
               temp->parent->right = 0;
               return;
          } else {
               throw MystErr();
          }
     } else {
          // At least one of the booleans should have been true, if we're here
          // something is wrong
          throw BrokBools();
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
          std::cout << node->datum << " ";
          this->pre_order(node->left);
          this->pre_order(node->right);
     }
}

void BST::in_order(Node* node) {
     if(!node) {
          return;
     } else {
          this->in_order(node->left);
          std::cout << node->datum << " ";
          this->in_order(node->right);
     }
}

void BST::post_order(Node* node) {
     if(!node) {
          return;
     } else {
          this->post_order(node->left);
          this->post_order(node->right);
          std::cout << node->datum << " ";
     }
}
