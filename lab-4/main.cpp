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
     std::cout << "The linked list is currently empty." << std::endl;
          std::cout << "Would you like to use a stack or a queue for this? " << std::endl;
          std::cin >> choice_listtype;
     menu:
          if(choice_listtype == "stack"){
                    std::cout << "Stack Menu: " << std::endl
                              << "1. Push new item onto stack" << std::endl
                              << "2. Pop the top off stack" << std::endl
                              << "3. Peek at the top of the stack" << std::endl
                              << "4. Empty the stack" << std::endl
                              << "5. Print the stack" << std::endl
                              << "6. Switch to queue menu"
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
                         std::cout << "Popping the top of the stack..." << std::endl
                                   << "POP! Top of the stack was " << stack.pop() << " but now it's " << stack.peek() << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 3:
                         std::cout << "Peeking at the top of the stack..." << std::endl
                                   << "Top of the stack contains " << stack.peek() << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 4:
                         std::cout << "Emptying the stack..." << std::endl;
                         stack.empty();
                         std::cout << "All gone!" << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 5:
                         std::cout << "Printing the stack..." << std::endl;
                         stack.print();
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 6:
                         std::cout << "Switching to queue menu..." << std::endl;
                         choice_listtype = "queue";
                         goto menu;
                    }
          } else if (choice_listtype == "queue") {
               std::cout << "Queue Menu: " << std::endl
                         << "1. Push new item onto queue" << std::endl
                         << "2. Pop the top off queue" << std::endl
                         << "3. Peek at the top of the queue" << std::endl
                         << "4. Empty the queue" << std::endl
                         << "5. Print the queue" << std::endl
                         << "6. Switch to stack menu"
                         << "Type which option to choose." << std::endl
                         << "Press any other key to exit." << std::endl;
                    std::cin >> choice_menu;
                    switch(choice_menu) {
                    case 1:
                         std::cout << "Pushing new item onto queue..." << std::endl
                                   << "What would you like to push?" << std::endl;
                         std::cin >> dat;
                         queue.push(dat);
                         std::cout << "Done, " << queue.peek() << " has been pushed onto the queue." << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 2:
                         std::cout << "Popping the top of the queue..." << std::endl
                                   << "POP! Top of the queue was " << queue.pop() << " but now it's " << queue.peek() << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 3:
                         std::cout << "Peeking at the top of the queue..." << std::endl
                                   << "Top of the queue contains " << queue.peek() << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 4:
                         std::cout << "Emptying the queue..." << std::endl;
                         queue.empty();
                         std::cout << "All gone!" << std::endl
                                   << "Returning to menu..." << std::endl;
                         goto menu;
                    case 5:
                         std::cout << "Printing the queue..." << std::endl;
                         stack.print();
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    case 6:
                         std::cout << "Switching to stack menu..." << std::endl;
                         choice_listtype = "stack";
                         goto menu;
                    }
          } else {
               while(choice_listtype != "stack" && choice_listtype == "queue") {
                    std::cout << "No idea what you typed. Just type stack or queue." << std::endl;
                    std::cin >> choice_listtype;
                    if(choice_listtype == "stack or queue") {
                         std::cout << "Well aren't you clever?" << std::endl;
                    }
               }
               goto menu;
          }
}
