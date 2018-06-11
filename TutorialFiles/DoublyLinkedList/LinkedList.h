// First thing we need is the node (a on Fig 3.1 from the Chapter 3 slides on slide 5)
// Thus we need a node class

class Node {
     // You should use a private class usually, but it's easier to make it public
public:
     int datum; // Top part of the structure on a from the slides
     // For linked lists, destructors in this Node class are unwanted as they will delete the entire
     // linked list
     Node *next; // Bottom part of the structure on a from the slides
     Node *prev;
     Node(int);
}

// Our actual linked list class
class LinkedList {
private:
     // Pointer to the first node in the list, aka the head of the list
     // Private because there should be no reason for anything outside of the class to mess with this
     Node *head; // p in the structure on a from the slides
     // Points to the last element of the list
     Node *tail;
     // Note, if there's only one element, head = tail
     // Integer to keep track of the size of the list, not completely necessary but helpful
     int size;
     void destr_helper(Node *head);
public:
     LinkedList();
     // Destructor is necessary for the linked list class because in this class, deleting the entire linked list is unwanted
     ~LinkedList();
     // Four primary functions: insert, get, set, remove
     // ^ These are the minimum requirements for it to be a linked list
     void insert(int,int) // index, datum
     // This isn't necessary to be int type but for this example, we will show how to make this function also return something or other idk I zoned out
     int remove(int); // index , although alternatively you could set this to datum and have it find the datum in the list
     int get(int); // index
     void set(int,int) // index, datum
     int getSize();
}
