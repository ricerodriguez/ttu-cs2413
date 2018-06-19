#include "Heap.h"
#include <iostream>
#include <string>

int main() {
     ArrHeap myheap;
     // Heap myheap;
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
     // Overloaded constructor demo
     int arr[] {14, 9, 7, 13, 23, 29};
     Heap heap2(arr,6);
     for(int i = 0; i < 7; i++) {
          std::cout << heap2.pop() << std::endl;
     }
     return 0;
}
