#include "Adder.h"

// Default constructor, initializes both operands to 2
Adder::Adder(){
     operand1 = 2;
     operand2 = 2;
}

// Second constructor, initializes both operands to the inputs it takes as arguments
Adder::Adder(double op1, double op2) {
     operand1 = op1;
     operand2 = op2;
}

// Adds the operands, returns the result
double Adder::add() {
     return operand1 + operand2;
}

// Subtracts the operands, returns the result
double Adder::subtract() {
     return operand1 - operand2;
}

// Multiplies the operands, returns the result
double Adder::multiply() {
     return operand1 * operand2;
}

// Divides the operands, returns the result
double Adder::divide() {
     return operand1 / operand2;
}

// Returns the operand asked for based on the argument given to it
// Uses extremely lazy way to "index" the two objects, I'm sorry lol
double Adder::get(int which_op) {
     // Too lazy to index into an array
     if(which_op == 1) {
          return operand1;
     } else if(which_op == 2) {
          return operand2;
     }
}

// Sets new values to the operands, returns nothing
void Adder::set(int which_op, double op) {
     if(which_op == 1) {
          operand1 = op;
     } else if (which_op == 2) {
          operand2 = op;
     }
}
