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

// Function to insert a new node iteratively
void BST::insert(int datum) {
     // Create a new node
     Node *newNode = new Node(datum);

     // If root is null, i.e. the binary search tree is empty...
     if(!this->root) {
          // Set new node to be the root of the tree
          this->root = newNode;
     }
     // Otherwise, find where to stick the new node into
     else {
          // Start the reference node at the root
          Node *temp = this->root;
          // While temp is non-empty...
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

// Function to insert a new node recursively, uses a helper function
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

// Helper function for the recursive insert function
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

// Function to search for a node and return the node if it's found, otherwise return null
BST::Node* BST::search(int datum) {
     // Start the reference node at the root of the tree
     Node *temp = this->root;
     // While the reference node being checked is non-empty and we haven't found the node yet
     while(temp && temp->datum != datum) {
          // If the node we're looking for is less than the reference node being checked
          if(datum < temp->datum) {
               // Node must be left of reference node, check node to the left
               temp = temp->left;
          }
          else {
               // Otherwise, node must be right of reference node, check node to the right
               temp = temp->right;
          }
     }
     // Reference node has exited the loop, if the node was in the tree, temp must be the node we
     // were looking for, otherwise temp is null (exited the loop by being empty)
     return temp;
}

// Function to iteratively remove a node from the tree. Note that the only argument needed is the
// value of the node because of the design decision made to not allow duplicates. This function has
// a dependency on the search function
void BST::remove(int datum) {
     // Reference node is set to the node which will be removed, found using the search function
     Node *temp1 = this->search(datum);
     // Create boolean leftChild which is true if temp1 is a left child of its parent
     bool leftChild;
     // Create boolean isRoot which is true if temp1 is the root node
     bool isRoot;
     // If the search function returns a null (node does not exist)...
     if(!temp1) {
          // ... Throw an error, because we can't remove a node that doesn't exist
          throw "Number not in tree";
     }
     // Otherwise, since we found the node, start the process to remove it
     else {
          // First, check if the node has a parent node
          if(temp1->parent) {
               // Determine if left or right child
               if(temp1->parent->left == temp1) {
                    leftChild = true;
               } else {
                    leftChild = false;
               }
          // If the node does not have a parent node, then it must be the root node
          } else {
               // Set the boolean to true so we know the node is the root node
               isRoot = true;
          }
          // Execute the remove
          // Check for children of the node
          if(!temp1->left) {
               // If the left of temp1 is not set then all we have left is the right child (or there
               // are no children)
               if(!temp1->right) {
                    // If the right of temp1 is also not set, then there are no children and we just
                    // have to delete the node

                    // If the node is the root node, just delete the root because there aren't any
                    // parent nodes to worry about
                    if(isRoot) {
                         this->root = 0;
                    }

                    // Otherwise, check if the node is left or right of its parent
                    else if(leftChild) {
                         // Cut the connection between the parent and its left child (temp1)
                         temp1->parent->left = 0;
                    } else {
                         // Cut the connection between the parent and its right child (temp1)
                         temp1->parent->right = 0;
                    }
               // If there is a right child (but not a left child)...
               } else {
                    // First check if the node is the root
                    if(isRoot) {
                         // If it's the root, delete the root, set the child as the new root
                         this->root = temp1->right;
                    // Otherwise, if node is not the root
                    } else {
                         // If the node was the left child of its parent node...
                         if(leftChild) {
                              // Cut the connection between the node and it's parent, replace node's
                              // position in tree with the node's child
                              temp1->parent->left = temp1->right;
                         } else {
                              temp1->parent->right = temp1->right;
                         }
                    }
               }
               delete temp1;
          }
     }
}
