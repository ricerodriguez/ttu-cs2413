#include <exception>
class Node {
public:
     Node(int);
     int datum;
     Node *next, *prev;
};

struct InvInd : public std::exception {
     const char * what () const throw () {
          return "Invalid index! Please choose something within range. ";
     }
};

struct EmptyList : public std::exception {
     const char * what () const throw () {
          return "List is currently empty! There is nothing to delete. ";
     }
};

class List {
     Node *head, *tail;
     int size;
     void del(Node *node);
public:
     List();
     ~List();
     // This function will accept a value from the user, which will be used to create a new node at
     // the beginning of the linked list
     void insBeg(int); // int datum
     // This function will accept a value from the user, which will be used to create a new node at
     // the end of the linked list
     void insEnd(int); // int datum
     // This function will accept a value and a location from the user, and will then add a node
     // with the provided value in the location specified by the user.
     void ins(int,int); // int index, datum
     // This function will delete the first node of the linked list.
     void delBeg();
     // This function will delete the last node of the linked list.
     void delEnd();
     // This function will take a user input specifying which node to delete.
     void delThis(int); // int index
     // This function will display the linked list.
     void view();
     int getSize();
     int getDat(int);
};
