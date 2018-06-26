#include "bst.h"
#include <iostream>
#include <exception>

int main() {
     BST tree;
     int user_sel, user_dat;
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
               std::cout << "Enter a numer to remove from the tree." << std::endl;
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
               } catch {

               }
     }
}
