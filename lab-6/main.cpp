#include <map>
#include <list>
#include <queue>
#include <string>
#include <utility>
#include <iostream>
#include <exception>

#include "Graph.h"

int main() {
     Graph *grapharoo = new Graph();
     int user_sel, user_weight;
     char user_label, user_label_new, user_label_from, user_label_to;
     std::string user_dir;
     // bool ask_again = true;
     menu:
     std::cout << "Graph Menu: " << std::endl
               << "1. Add node to the graph" << std::endl
               << "2. Add edge to the graph" << std::endl
               << "3. Breadth First Traversal of the Tree" << std::endl
               << "Enter anything else to exit the program." << std::endl;
     std::cin >> user_sel;

     switch(user_sel) {
          case 1:
               std::cout << "Enter a label for your new node: " << std::endl;
               std::cin >> user_label_new;
               try {
                    grapharoo->add_node(user_label_new);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
               }
               std::cout << "Done! A new node labeled " << user_label_new << " has been created." << std::endl;
               std::cout << "Returning to menu..." << std::endl;
               goto menu;

          case 2:
               std::cout << "Enter the label of the node to start this edge from: " << std::endl;
               std::cin >> user_label_from;
               std::cout << "Enter the label of the node where this edge ends: " << std::endl;
               std::cin >> user_label_to;
               std::cout << "Enter length of edge, i.e. distance from node " << user_label_from << " to node " << user_label_to << ":" << std::endl;
               std::cin >> user_weight;
               std::cout << "Is this edge directed or undirected?" << std::endl;
               std::cin >> user_dir;
               while (true) {
                    if (user_dir == "directed" || user_dir == "d") {
                         try {
                              grapharoo->add_edge(user_label_from, user_label_to, user_weight);
                         } catch (std::exception &e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                         }
                         std::cout << "Done! A new edge has been created, connecting node " << user_label_from << " to node " << user_label_to << " in one direction." << std::endl;
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "undirected" || user_dir == "u") {
                         try {
                              grapharoo->add_edge(user_label_from, user_label_to, user_weight);
                              grapharoo->add_edge(user_label_to, user_label_from, user_weight);
                         } catch (std::exception &e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                         }
                         std::cout << "Done! A new edge has been created, connecting node " << user_label_from << " to node " << user_label_to << " going both directions." << std::endl;
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "exit" || user_dir == "e") {
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "help" || user_dir == "h") {
                         std::cout << "directed --- new edge will be directed" << std::endl
                                   << "undirected --- new edge will be undirected (bidirectional)" << std::endl
                                   << "exit --- return to main menu" << std::endl
                                   << "help --- view these tips again" << std::endl;
                    } else {
                         std::cout << "Invalid command. Try again or type 'help' if you're having trouble. " << std::endl;
                         std::cin >> user_dir;
                    }
               }

          case 3:
               std::cout << "What node does this start with?" << std::endl;
               std::cin >> user_label;
               try {
                    grapharoo->BFT(user_label);
               } catch (std::exception &e){
                    std::cerr << "ERROR: " << e.what() << std::endl;
               }
               goto menu;
          default: std::cout << "Goodbye!"; return 0;
     }
}
