#include "BST.h."

// Constructor for the Node encapsulated by the BST class
BST::Node::Node(int datum) {
     // Initialize all variables to null.
     this->parent = 0;
     this->left = 0;
     this->right = 0;
     // Initialize the datum variable to the value given through its declaration
     this->datum = datum;
}

// Constructor for the BST class
BST::BST(){
     // Initialize only variable to null
     this->root = 0;
}

// Destructor helper for the BST class
void BST::destr_helper(Node *node) {
     // If the node is non-empty...
     if(node) {
          // Recursively call this function on the node to the left of the node provided. This will
          // loop recursively until it has reached the bottom of the tree (left of node is null) at
          // which point it will have finished executing and proceed to the line following it.
          this->destr_helper(node->left);
          // Recursively call this function on the node to the right of the node provided
          this->destr_helper(node->right);
          // After the function has finished on both sides, delete the node
          delete node;
     }
}

// Destructor for the BST class
BST::~BST() {
     this->destr_helper(this->root);
}

void BST::insert(int datum) {
     // Create a new node
     Node *newNode = new Node(datum);

     // If root is null, i.e. the binary search tree is empty...
     if(!this->root) {
          // Set new node to be the root of the tree
          this->root = newNode;
     }
     // Otherwise, start from the root
     else {
          Node *temp = this->root;
          while(temp) {
               // Note: This is a design decision to not allow duplicates in the tree, this is not
               // strictly necessary for a binary search tree and designs incorporating duplicates
               // are still valid, but would be incorporated differently. If duplicates were
               // allowed, a greater/less than or equal sign (>= or <=) would be used instead of
               // greater/less than on one of the sides. So, for example, the left condition (line
               // 61) would be datum <= temp->datum instead of datum < temp->datum
               if(datum == temp->datum) {
                    throw "No duplicates allowed";
               }
               // If the new node is less than the root node (should be inserted to left of root)
               else if(datum < temp->datum) {
                    // If there's something left of temp...
                    if(temp->left) {
                         // Keep going left
                         temp = temp->left;
                    }
                    // Otherwise, if there's nothing else to the left of the temp node...
                    else {
                         // Put the new node in the spot to the left since we know the spot is empty
                         temp->left = newNode;
                         // Insert completed, break out of loop
                         break;
                    }
               }
               // If the new node is greater than the root node (should be inserted to right of root)
               else {
                    // If there's something to the right of temp...
                    if(temp->right) {
                         // Keep moving right
                         temp = temp->right;
                    }
                    // If there's nothing right of temp
                    else {
                         // Put new node in the spot to the right
                         temp->right = newNode;
                         // Insert completed, break out of loop
                         break;
                    }
               }
          }
     }
}

// Recursive insert
void BST::recur_insert(int datum) {
     // Create new node
     Node *newNode = new Node(datum);

     // If binary search tree is empty...
     if(!this->root) {
          // Root of tree is new node
          this->root = newNode;
     }
     else {
          // Calling recursive helper function on the root and passing the new node that is going to
          // be inserted
          this->rec_inst_helper(this->root, newNode);
     }

}

// Recursive insert helper function
// Note that other designs are possible that do not incorporate a helper function
void BST::rec_inst_helper(Node *node, Node *newNode) {
     // Note: Design decision was made to not consider or allow duplicates in the tree, this was
     // already mentioned and explained earlier
     if(Node->datum == newNode->datum) {
          throw "No duplicates allowed";
     }
     // If the new node is less than the given node (should go to the left of given node)...
     else if(newNode->datum < node->datum) {
          if(node->left) {
               // If there is something to the left of the given node, use the node to the left of
               // the current node as the next node to compare the new node (the one being inserted)
               this->rec_inst_helper(node->left, newNode);
          }
          // Otherwise, if there's nothing else to the left of the given node...
          else {
               // Put the new node in the spot to the left since we know the spot is empty
               node->left = newNode;
          }

     }
     // If the new node is greater than the given node (should go to the right of given node)...
     else {
          if(node->right) {
               // If there is something to the right of the given node, use the node to the right of
               // the current node as the next node to compare the new node (the one being inserted)
               this->rec_inst_helper(node->right, newNode);
          }
          // Otherwise, if there's nothing else to the right of the given node...
          else {
               // Put the new node in the spot to the right since we know the spot is empty
               node->right = newNode;
          }
     }
}
