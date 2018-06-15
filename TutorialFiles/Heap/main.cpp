#include "Heap.h"
#include <iostream>
#include <string>

int main() {
     Heap myheap;
     string input;
     int val;
     while(true) {
          std::cout << "Enter a command\n: ";
          std::cin >> input;
          if(input == "push") {
               std::cin >> val;
               myheap.push(val);
          } else if (input == "pop") {
               std::cout << myheap.pop() << std::endl;
          } else if (input == "exit") {
               break;
          } else {
               std::cout << "Invalid command" << std::endl;
          }
     }
     return 0;
}
