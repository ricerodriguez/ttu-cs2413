#include "stackqueue.h"
#include <iostream>
#include <exception>
#include <string>

int main() {
     List listerine;
     Stack stack;
     Queue queue;
     int choice_menu, size;
     std::string choice_listtype;
     int dat, ind;
     int popped, peeked;
     std::cout << "The linked list is currently empty." << std::endl;
          std::cout << "Would you like to use a stack or a queue for this? " << std::endl;
          std::cin >> choice_listtype;
     menu:
          if(choice_listtype == "stack"){
                    std::cout << "Stack Menu: " << std::endl
                              << "1. Push new item onto stack" << std::endl
                              << "2. Pop the top off stack" << std::endl
                              << "3. Peek at the top of the stack" << std::endl
                              << "4. Check if the stack is empty" << std::endl
                              << "5. Print the stack" << std::endl
                              << "6. Switch to queue menu" << std::endl
                              << "Type which option to choose." << std::endl
                              << "Press any other key to exit." << std::endl;
                    std::cin >> choice_menu;
                    switch(choice_menu) {
                    case 1:
                         std::cout << "Pushing new item onto stack..." << std::endl
                                   << "What would you like to push?" << std::endl;
                         std::cin >> dat;
                         stack.push(dat);
                         std::cout << "Done, " << stack.peek() << " has been pushed onto the stack." << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 2:
                         std::cout << "Popping the top of the stack..." << std::endl;
                         try {
                              popped = stack.pop();
                         } catch (std::exception& e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              goto menu;
                         }
                         std::cout << "POP! Top of the stack was " << popped << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 3:
                         std::cout << "Peeking at the top of the stack..." << std::endl;
                         try {
                              peeked = stack.peek();
                         } catch (std::exception& e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
                         }
                         std::cout << "Top of the stack contains " << peeked << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 4:
                         std::cout << "Checking if the stack is empty..." << std::endl;
                         if(stack.empty() == 0) {
                              std::cout << "Stack is not empty." << std::endl;
                         } else {
                              std::cout << "Stack is empty." << std::endl;
                         }
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 5:
                         std::cout << "Printing the stack..." << std::endl;
                         try {
                              stack.print();
                         } catch (std::exception& e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                         }
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 6:
                         std::cout << "Switching to queue menu..." << std::endl;
                         choice_listtype = "queue";
                         goto menu;
                    default:
                         return 0;
                    }
          } else if (choice_listtype == "queue") {
               std::cout << "Queue Menu: " << std::endl
                         << "1. Push new item onto queue" << std::endl
                         << "2. Pop the bottom off queue" << std::endl
                         << "3. Peek at the top of the queue" << std::endl
                         << "4. Check if the queue is empty" << std::endl
                         << "5. Print the queue" << std::endl
                         << "6. Switch to stack menu" << std::endl
                         << "Type which option to choose." << std::endl
                         << "Press any other key to exit." << std::endl;
                    std::cin >> choice_menu;
                    switch(choice_menu) {
                    case 1:
                         std::cout << "Pushing new item into the queue..." << std::endl
                                   << "What would you like to push?" << std::endl;
                         std::cin >> dat;
                         queue.push(dat);
                         std::cout << "Done, " << queue.peek() << " has been pushed into the queue." << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 2:
                         std::cout << "Popping the bottom of the queue..." << std::endl;
                         try {
                              popped = queue.pop();
                         } catch (std::exception& e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              goto menu;
                         }
                         std::cout << "POP! Bottom of the queue was " << popped << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 3:
                         std::cout << "Peeking at the top of the queue..." << std::endl;
                         try {
                              peeked = queue.peek();
                         } catch (std::exception& e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
                         }
                         std::cout << "Top of the queue contains " << peeked << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 4:
                         std::cout << "Checking if the queue is empty..." << std::endl;
                         if(queue.empty() == 0) {
                              std::cout << "Queue is not empty." << std::endl;
                         } else {
                              std::cout << "Queue is empty." << std::endl;
                         }
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 5:
                         std::cout << "Printing the queue..." << std::endl;
                         queue.print();
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 6:
                         std::cout << "Switching to stack menu..." << std::endl;
                         choice_listtype = "stack";
                         goto menu;
                    default:
                         return 0;
                    }
          } else {
               std::cout << "Fine then. Bye.";
               return 0;
          }
}
