// Node class is inside of the BST class. This is an example of encapsulation. There should be no
// reason to create the node outside this class (in the main function).

class BST {
     class Node {
     public: // Only public to the BST class
          Node *left, *right, *parent;
          int datum;
          Node(int);
     }
     // Top node in the tree
     Node *root;
     void destr_helper(Node*);
public:
     // Constructor
     BST();
     // Destructor
     ~BST();
     // Insert a number iteratively into the tree
     void insert(int);
     // Insert a number recursively into the tree
     void recur_insert(int);
     // Recursive helper function for recur_insert
     void rec_inst_helper(Node*, Node*);
     // Remove a number from the tree
     void remove(int);
     // Returns true if the number being searched for was found, returns false otherwise
     bool search();

}
