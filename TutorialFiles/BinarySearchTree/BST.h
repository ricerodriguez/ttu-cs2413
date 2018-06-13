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
     // Insert a number recursively into the tree using a helper function
     void recur_insert(int);
     // Helper function for the recursive insert function
     void rec_inst_helper(Node*, Node*);
     // Remove a number iteratively from the tree
     void remove(int);
     // Returns the node being searched for if it's found, otherwise returns null
     Node *search();

}
