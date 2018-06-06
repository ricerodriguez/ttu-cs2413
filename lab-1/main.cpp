#include "Adder.h"
#include <iostream>

int main(){
     int menu_op, num_op;
     double op, out;
     Adder calc;
     std::cout << "Operands initialized to 2." << std::endl;

     menu:
     std::cout << "Menu: " << std::endl <<
                  "1. Set new values of operands" << std::endl <<
                  "2. Add " << calc.operand1 << " and " << calc.operand2 << std::endl <<
                  "3. Subtract " << calc.operand1 << " and " << calc.operand2 << std::endl <<
                  "4. Multiply " << calc.operand1 << " with " << calc.operand2 << std::endl <<
                  "5. Divide " << calc.operand1 << " by " << calc.operand2 << std::endl <<
                  "6. Return value of one of the operands" << std::endl;
     std::cin >> menu_op;
     switch(menu_op) {
          case 1: std::cout << "Setting new values of operands..." << std::endl <<
                               "Which operand would you like to change? " << std::endl <<
                               "Choose 1 or 2." << std::endl;
                  std::cin >> num_op;
                  std::cout << "Okay, setting new value of operand " << num_op << "..." << std::endl <<
                               "Choose a new value for this operand: " << std::endl;
                  std::cin >> op;
                  calc.set(num_op, op);
                  std::cout << "Done. Operand " << num_op << " is now set to " << op << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          case 2: std::cout << "Adding the operands... " << std::endl <<
                               "Done. Result: " << calc.add() << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          case 3: std::cout << "Subtracting the operands... " << std::endl <<
                               "Done. Result: " << calc.subtract() << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          case 4: std::cout << "Multiplying the operands..." << std::endl <<
                               "Done. Result: " << calc.multiply() << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          case 5: std::cout << "Dividing the operands..." << std::endl <<
                               "Done. Result: " << calc.divide() << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          case 6: std::cout << "Returning value of the operands... " << std::endl <<
                               "Which operand would you like returned? " << std::endl <<
                               "Choose 1 or 2." << std::endl;
                  std::cin >> num_op;
                  calc.get(num_op);
                  std::cout << "Operand " << num_op << " is currently set to " << calc.operand1 << std::endl;
                  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                  goto menu;
                  break;
          default: std::cout << "Invalid user input. Type your selection from the given options. " << std::endl;
                   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                   goto menu;
     }
}
