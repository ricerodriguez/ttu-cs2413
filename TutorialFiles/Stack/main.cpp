// Use for StackQueue.cpp and StackQueue.h
#include "Stack.h"
#include <iostream>
#include <string>

int main() {
     Queue queue;
     ArrStack astack;
     ListStack lstack;
     string input;
     int datum;
     // Test by replacing astack with lstack or queue
     while(true) {
          std::cout << "Enter command\n: ";
          std::cin >> input;
          try {
               if(input == "push") {
                    std::cin >> datum;
                    astack.push(datum);
               }
               else if(input == "pop") {
                    std::cout << astack.pop() << std::endl;
               }
               else if(input == "peek") {
                    std::cout << astack.peek() << std::endl;
               }
               else if(input == "exit") {
                    break;
               }
               else {
                    std::cout << "invalid command" << std::endl;
               }
          }
          // A string literal is a constant, so you need to use const
          catch (const char* msg) {
               std::cout << msg << std::endl;
          }
     }
}
