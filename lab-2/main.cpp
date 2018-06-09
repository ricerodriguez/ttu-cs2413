#include "list.h"
#include <iostream>

int main() {
     List listerine;
     int choice, size;
     int dat, ind;
     menu:
     std::cout << "Menu: " << std::endl
               << "1. View linked list" << std::endl
               << "2. Insert datum at beginning of list" << std::endl
               << "3. Insert datum at end of list" << std::endl
               << "4. Insert datum at specified place in list" << std::endl
               << "5. Remove datum at beginning of list" << std::endl
               << "6. Remove datum at end of list" << std::endl
               << "7. Remove datum at specified place in list" << std::endl
               << "Type which option to choose." << std::endl;
     std::cin >> choice;
     switch(choice) {
          case 1:
               std::cout << "Displaying linked list..." << std::endl;
               try{
                    listerine.view();
               }
               catch(int error) {
                    std::cerr << "ERROR " << error << ": Linked list is currently empty." << std::endl;
               }
               std::cout << "Returning to menu..." << std::endl;
               goto menu;

          case 2:
               std::cout << "Inserting datum at the beginning of the list..." << std::endl
                         << "Enter the datum to insert:" << std::endl;
               std::cin >> dat;
               listerine.insBeg(dat);
               std::cout << "Done. First node of linked list now contains " << listerine.getDat(0) << "." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 3:
               std::cout << "Inserting datum at the end of the list..." << std::endl
                         << "Enter the datum to insert:" << std::endl;
               std::cin >> dat;
               listerine.insEnd(dat);
               size = listerine.getSize();
               std::cout << "Done. Last node of linked list now contains " << listerine.getDat(size-1) << "." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 4:
               std::cout << "Inserting datum at specified place in list..." << std::endl
                         << "Enter the datum to insert:" << std::endl;
               std::cin >> dat;
               std::cout << std::endl << "Enter location (index) of linked list to enter " << dat
                         << " to:" << std::endl << "There are " << listerine.getSize() << " spaces to choose from." << std::endl;
               std::cin >> ind;
               try {
                    listerine.ins(ind,dat);
               } catch (int error) {
                    std::cerr << "ERROR " << error << ": Hey listen here numbnuts you can't do that" << std::endl;
                    goto menu;
               }
               std::cout << "Done. Space at " << ind << " now contains " << listerine.getDat(ind) << "." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 5:
               std::cout << "Removing datum from beginning of list..." << std::endl;
               listerine.delBeg();
               std::cout << "Done, datum from first node has been removed." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 6:
               std::cout << "Removing datum from end of list..." << std::endl;
               listerine.delEnd();
               std::cout << "Done, datum from last node has been removed." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          case 7:
               std::cout << "Removing datum from specified place in list..." << std::endl
                         << "Enter the location (index) to remove datum from: " << std::endl;
               std::cin >> ind;
               try {
                    listerine.delThis(ind);
               }
               catch(int error) {
                    std::cerr << "ERROR " << error << ": Hey listen here numbnuts you can't do that" << std::endl;
                    goto menu;
               }
               std::cout << "Done. Datum from " << ind << " now empty." << std::endl
                         << "Returning to menu..." << std::endl;
               goto menu;

          default:
               std::cout << "There are 7 options. Choose a number between 1 and 7." << std::endl
                         << "This shouldn't be this difficult." << std::endl;
               goto menu;

     }

}
