#include <map>
#include <list>
#include <queue>
#include <string>
#include <utility>
#include <iostream>
#include <exception>

#include "Dijkstra.h"

int main() {
     Graph *grapharoo = new Graph();
     int user_sel, user_weight;
     char user_label, user_label_from, user_label_to;
     std::string user_dir;
     // bool ask_again = true;
     menu:
     std::cout << "Dijkstra Menu: " << std::endl
               << "1. Add node to the graph" << std::endl
               << "2. Add edge to the graph" << std::endl
               << "3. Remove node from the graph" << std::endl
               << "4. Remove edge from the graph" << std::endl
               << "5. Print the nodes with their weight " << std::endl
               << "6. Breadth First Traversal of the Tree" << std::endl
               << "7. DIJKSTRA'S ALGORITHM" << std::endl
               << "Enter anything else to exit the program." << std::endl;
     std::cin >> user_sel;

     switch(user_sel) {
          case 1:
               std::cout << "Enter a label for your new node: " << std::endl;
               std::cin >> user_label;
               try {
                    grapharoo->add_node(user_label);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               std::cout << "Done! A new node labeled " << user_label << " has been created." << std::endl;
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
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
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
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
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
               std::cout << "Enter the label of the node you'd like to remove: " << std::endl;
               std::cin >> user_label;
               try {
                    grapharoo->remove_node(user_label);
               } catch (std::exception &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               std::cout << "Done, node " << user_label << " and all connecting edges have been removed." << std::endl;
               std::cout << "Returning to menu..." << std::endl;
               goto menu;

          case 4:
               std::cout << "Enter the node this edge starts from: " << std::endl;
               std::cin >> user_label_from;
               std::cout << "Enter the node this edge ends on: " << std::endl;
               std::cin >> user_label_to;
               std::cout << "Is this edge directed or undirected?" << std::endl;
               std::cin >> user_dir;
               while (true) {
                    if (user_dir == "directed" || user_dir == "d") {
                         try {
                              grapharoo->remove_edge(user_label_from, user_label_to);
                         } catch (std::exception &e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
                         }
                         std::cout << "Done! The edge connecting node " << user_label_from << " to node " << user_label_to << " in one direction has been removed." << std::endl;
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "undirected" || user_dir == "u") {
                         try {
                              grapharoo->remove_edge(user_label_from, user_label_to);
                              grapharoo->remove_edge(user_label_to, user_label_from);
                         } catch (std::exception &e) {
                              std::cerr << "ERROR: " << e.what() << std::endl;
                              std::cout << "Returning to menu..." << std::endl;
                              goto menu;
                         }
                         std::cout << "Done! The edge connecting node " << user_label_from << " to node " << user_label_to << " going both directions has been removed." << std::endl;
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "exit" || user_dir == "e") {
                         std::cout << "Returning to menu..." << std::endl;
                         goto menu;
                    } else if (user_dir == "help" || user_dir == "h") {
                         std::cout << "directed --- remove edge in only one direction" << std::endl
                                   << "undirected --- remove edge going both ways" << std::endl
                                   << "exit --- return to main menu" << std::endl
                                   << "help --- view these tips again" << std::endl;
                    } else {
                         std::cout << "Invalid command. Try again or type 'help' if you're having trouble. " << std::endl;
                         std::cin >> user_dir;
                    }
               }
          case 5:
               grapharoo->print_nodes();
               std::cout << "Returning to menu..." << std::endl;
               goto menu;

          case 6:
               std::cout << "What node does this start with?" << std::endl;
               std::cin >> user_label;
               try {
                    grapharoo->BFT(user_label);
               } catch (std::exception &e){
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               goto menu;

          case 7:
               std::cout << "What node does this start with?" << std::endl;
               std::cin >> user_label_from;
               std::cout << "What node does this end with?" << std::endl;
               std::cin >> user_label_to;
               try {
                    grapharoo->dijkstra(user_label_from, user_label_to);
               } catch (std::exception &e){
                    std::cerr << "ERROR: " << e.what() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    goto menu;
               }
               goto menu;

          default: std::cout << "Goodbye!"; return 0;
     }
}
