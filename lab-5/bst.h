class BST {
     class Node {
     public:
          Node *left, *right, *parent;
          int datum;
          Node(int);
     };
     Node *root;
     void destr_helper(Node*);
     void pre_order(Node*);
     void in_order(Node*);
     void post_order(Node*);
     void ins_helper(Node*, Node*);
     Node* find(int);
public:
     BST();
     ~BST();
     void ins(int);
     int find_main(int);
     void del(int);
     void traverse(int);
};

struct NoDups : public std::exception {
     const char * what () const throw () {
          return "No duplicate nodes allowed! The BST may already contain a node of that datum. ";
     }
};

struct NotFound : public std::exception {
     const char * what () const throw () {
          return "Node of entered datum could not be found! ";
     }
};
