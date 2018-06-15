#include "BST.h"
#include <iostream>
#include <string>

int main() {
     BST bst;
     string input;
     int num;
     while(true) {
          std::cout << "Enter a command\n: ";
          std::cin >> input;
          try {
               if(input ==  "insert") {
                    std::cin >> num;
                    bst.insert(num);
               } else if (input == "remove") {
                    std::cin >> num;
                    bst.remove(num);
               } else if (input == "search") {
                    if(bst.search(num)) {
                         std::cout << num << " was found" << std::endl;
                    } else {
                         std::cout << num << " was not found" << std::endl;
                    }
               } else if (input == "exit") {
                    break;
               } else if (input == "traverse") {
                    bst.traverse();
               } else {
                    std::cout << "Invalid command" << std::endl;
               }
          } catch (const char* msg) {
               std::cout << msg << std::endl;
          }
     }

     return 0;
}
