class Adder {
     // Access is private by default
public:
     double operand1, operand2, result;
     int operand_num;
     Adder();
     Adder(double, double);
     double add();
     double subtract();
     double multiply();
     double divide();
     double get(int);
     void set(int, double);

};
