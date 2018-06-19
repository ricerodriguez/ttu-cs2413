#include "Heap.h"

// Class definition for the constructor of the Node class
Heap::Node::Node(int datum) {
     this->datum = datum;
     this->left = 0;
     this->right = 0;
     this->parent = 0;
}

// Class definition for the constructor of the Heap class
Heap::Heap() {
     this->root = 0;
     this->tail = 0;
}

Heap::Heap(int* arr, int size) {
     this->root = 0;
     this->tail = 0;
     this->heapify(arr, size);
}

// Helper function for the destructor of the Heap class
void Heap::destr_helper(Node* node) {
     if(node) {
          this->destr_helper(node->left);
          this->destr_helper(node->right);
          delete node;
     }
}

// Class definition for the destructor of the Heap class
Heap::~Heap() {
     this->destr_helper(this->root);
}

// Function for the up-heap. Uses recursion. This is a min-heap.
void Heap::upheap(Node* node) {
     // Min heap, so check if the node violates the min heap property. If it does, swap the two
     // nodes. Also check if there's even a parent so that it will stop calling the function at the
     // root (worst case scenario)
     if(node->parent && node->datum < node->parent->datum) {
          // Store the datum of the node into a temporary variable
          int temp = node->datum;
          // Now set the datum of the node to the parent's datum
          node->datum = node->parent->datum;
          // Now set the parent's datum as the old datum from the first node
          node->parent->datum = temp;
          // Call the function again to keep going up
          this->upheap(node->parent);
     }
}

// Function for the down-heap.
void Heap::downheap(Node* node) {
     // Check if there's even a left and right node
     if(node->left && node->right) {
          // If the left node is less than or equal to the right node, move the left one up
          if(node->left->datum <= node->right->datum) {
               // First check if the left node is also less than or equal to the current node, if
               // so, do the same as the up-heap
               if(node->left->datum <= node->datum) {
                    // Store the datum of the node into a temporary variable
                    int temp = node->datum;
                    // Now set the datum of the node to the left node's datum
                    node->datum = node->left->datum;
                    // Now set the left node's datum as the old datum from the first node
                    node->left->datum = temp;
                    // Call the function again to keep going left
                    this->downheap(node->left);
               } else {
                    // Store the datum of the node into a temporary variable
                    int temp = node->datum;
                    // Now set the datum of the node to the right node's datum
                    node->datum = node->right->datum;
                    // Now set the right node's datum as the old datum from the first node
                    node->right->datum = temp;
                    // Call the function again to keep going right
                    this->downheap(node->right);
               }
          }
     // Only have to check if there's a left child node because it is not possible for the node to
     // have a right child and not a left child in this data structure.
     } else if (node->left) {
          // Store the datum of the node into a temporary variable
          int temp = node->datum;
          // Now set the datum of the node to the left node's datum
          node->datum = node->left->datum;
          // Now set the left node's datum as the old datum from the first node
          node->left->datum = temp;
          // Call the function again to keep going left
          this->downheap(node->left);
     }
}

// Function to push a new node onto the heap
void Heap::push(int datum) {
     // Create the new node
     Node *newNode = new Node(datum);

     if(this->root == 0) {
          this->root = newNode;
          this->tail = newNode;
     } else {
          // Use the tail as the reference node
          Node *temp = this->tail;
          // While the current node is not the root and is not a left node of its parent...
          while(temp->parent && temp->parent->left != temp) {
               // Keep going up
               temp = temp->parent;
          }
          // If it's not the root, go up one, right one, and THEN go all the way down to the left
          if(temp != this->root) {
               // If the parent has a right child, set the pointer to that.
               if(temp->parent->right) {
                    temp = temp->parent->right;
               // Otherwise, stick the new node into that empty position
               } else {
                    temp->parent->right = newNode;
                    // Update the parent of the new node
                    newNode->parent = temp->parent;
                    // Update the tail pointer
                    this->tail = newNode;
                    // Fix the rest of the heap so it's ordered correctly for a valid heap
                    this->upheap(newNode);
                    // Exit the function
                    return;
               }
          }
          // Otherwise, if it is the root, then just keep going all the way to the left
          while(temp->left) {
               temp = temp->left;
          }
          // Insert the new node at the leftmost position
          temp->left = newNode;
          // Update the parent of the new node
          newNode->parent = temp;
          // Update the tail pointer
          this->tail = newNode;
          // Fix the rest of the heap so it's ordered correctly for a valid heap
          this->upheap(newNode);
     }
}

// Function to pop the last node off the heap and return the datum it had
int Heap::pop() {
     // Store the value needed to return
     int retVal = this->root->datum;
     // Set root datum to tail datum
     this->root->datum = this->tail->datum;


     // Downheap the root
     this->downheap(this->root);
     // Use a reference pointer, start it at the tail
     Node *temp = this->tail;
     // While the current node is not the root and is not a left node of its parent...
     while(temp->parent && temp->parent->right != temp) {
          // Go up the tree
          temp = temp->parent;
     }
     // If we aren't in the root and we're in a right node, go up one and left one
     if(temp != this->root) {
          // Don't have to check if there's a left child because there's always one in this instance
          temp = temp->parent->left;
     }
     // Then go down to the bottom
     while(temp->right) {
          // Keep moving down the right side
          temp = temp->right;
     }
     if(this->tail != this->root) {
          // Remove the tail from the tree
          if(this->tail->parent->left == this->tail) {
               this->tail->parent->left = 0;
          } else {
               this->tail->parent->right = 0;
          }
     } else {
          // Delete the old tail first
          delete this->tail;
          // Then set the tail equal to temp
          this->tail = temp;
          return retVal;
     }
}

void heapify(int *arr, int size) {
     for(int i = 0; i < size; i++) {
          this->push(arr[i]);
     }
}

ArrHeap::ArrHeap() {
     this->arr = new int[10];
     this->tail = 0;
     this->size = 10;
}

ArrHeap::~ArrHeap() {
     delete this->arr;
}

int ArrHeap::parent(int index) {
     return (index - 1) / 2;
}

int ArrHeap::left(int index) {
     return index * 2 + 1;
}

int ArrHeap::right(int index) {
     return index * 2 + 2;
}

void ArrHeap::swap(int i1, int i2) {
     int temp = this->arr[i1];
     this->arr[i1] = this->arr[i2];
     this->arr[i2] = temp;
}

// Index is the index of the item we want to upheap
void ArrHeap::upheap(int index) {
     int parent = this->parent(index);
     // While we have a parent and the item in that parent is greater than the item in this index
     while(parent >= 0 && this->arr[this->parent(index)] > this->arr[index]) {
          // If whatever is in the parent of the index is greater than what is
          // in the index, then the two need to swap positions
          this->swap(index, parent);
          index = parent;
          // Update for the new parent
          parent = this->parent(index);
     }
}

void ArrHeap::downheap(int index) {
     int left = this->left(index);
     int right = this->right(index);
     // While there is at least a left child
     while(left < this->tail) {
          if(right < this->tail) {
               // Then we have both a left and a right child
               // Check which child is smaller

               // Left child is smaller than the right child
               if (this->arr[left] < this->arr[right]) {
                    // Current is bigger than the left child, so we have to move down
                    if(this->arr[left] < this->arr[index]) {
                         this->swap(index, left);
                         // Move down to that child
                         index = left;
                    }
               } else {
               // Current is bigger than the right child, so we have to move down
               if(this->arr[right] < this->arr[index]) {
                    this->swap(index, right);
                    // Move down to that child
                    index = right;
                    }
               }
          }
          // If there is only a left child
          else {
               // Current is bigger than left child
               if(this->arr[left] < this->arr[index]) {
                    this->swap(index, left);
                    index = left;
               }
          }
          left = this->left(index);
          right = this->right(index);
     }
}

void ArrHeap::push(int num) {
     // If we've reached the end of the array, make a new array that's twice as
     // big and copy the old array into the new array
     if(this->tail == this->size) {
          // Create new array
          int *newArr = new int[this->size*2];
          // Copy the data
          for(int i = 0; i < this->size; i++) {
               newArr[i] = this->arr[i];
          }
          // Double the size of the array
          this->size *= 2;
          // Delete the old array
          delete this->arr;
          // Set the new array
          this->arr = newArr;
     }
     // Push the new item onto the heap
     this->arr[this->tail] = num;
     // Upheap to fix the order
     this->upheap(this->tail);
     // Increment tail
     this->tail++;
}

int ArrHeap::pop() {
     if (this->tail == 0) {
          throw "Heap is empty";
     }
     int retVal = this->arr[0];
     this->tail--;
     this->arr[0] = this->arr[this->tail];
     this->downheap(0);
     return retVal;
}
