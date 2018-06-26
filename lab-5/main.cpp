#include "bst.h"
#include <iostream>
#include <exception>
#include <string>

int main() {
     BST tree;
     int user_sel, user_dat;
     std::string user_trav;
     bool continue_trav = true;
     menu:
     std::cout << "Menu: " << std::endl
               << "1. Insert number into tree." << std::endl
               << "2. Remove number from tree." << std::endl
               << "3. Find a number in tree" << std::endl
               << "4. Traverse the tree" << std::endl
               << "5. Exit program" << std::endl;
     std::cin >> user_sel;
     switch(user_sel) {
          case 1:
               std::cout << "Enter a number to insert into the tree." << std::endl;
               std::cin >> user_dat;
               try {
                    tree.ins(user_dat);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               std::cout << "Done. " << user_dat << " has been inserted into the BST." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 2:
               std::cout << "Enter a number to remove from the tree." << std::endl;
               std::cin >> user_dat;
               try {
                    tree.del(user_dat);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               std::cout << "Done. " << user_dat << " has been removed from the BST." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 3:
               std::cout << "Enter a number to search for in the tree." << std::endl;
               std::cin >> user_dat;
               try {
                    tree.find(user_dat);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               std::cout << "Returning to menu..." << std::endl;
               goto menu;

          case 4:
               std::cout << "Pre-Order Traversal: ";
               tree.traverse(1);
               std::cout << "\nIn-Order Traversal: ";
               tree.traverse(2);
               std::cout << "\nPost-Order Traversal: ";
               tree.traverse(3);
               std::cout << "\nReturning to menu..." << std::endl;
               goto menu;
          // while(continue_trav) {
          //      std::cout << "Enter the type of traversal." << std::endl;
          //      std::cin >> user_trav;
          //      if(user_trav == "preorder" || user_trav == "pre-order" || user_trav == "pre_order" || user_trav == "pre order") {
          //           std::cout << "Pre-Order Traversal: " << std::endl;
          //           tree.traverse(1);
          //           std::cout << "Returning to menu..." << std::endl;
          //           goto menu;
          //      } else if (user_trav == "inorder" || user_trav == "in-order" || user_trav == "in_order" || user_trav == "in order") {
          //           std::cout << "In-Order Traversal: " << std::endl;
          //           tree.traverse(2);
          //           std::cout << "Returning to menu..." << std::endl;
          //           goto menu;
          //      } else if (user_trav == "postorder" || user_trav == "post-order" || user_trav == "post_order" || user_trav == "post order") {
          //           std::cout << "Post-Order Traversal: " << std::endl;
          //           tree.traverse(3);
          //           std::cout << "Returning to menu..." << std::endl;
          //           goto menu;
          //      } else if (user_trav == "exit" || user_trav == "stop" || user_trav == "back") {
          //           std::cout << "Exiting attempts to traverse..." << std::endl;
          //           continue_trav == false;
          //      } else {
          //           std::cout << "Invalid selection. Please choose from pre-order, in-order, or post-order." << std::endl;
          //           continue_trav == true;
          //      }
          // }

          default:
               std::cout << "Exiting the program..." << std::endl;
               return 0;
     }
}
