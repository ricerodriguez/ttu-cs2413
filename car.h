class Car {
     // Access is private by default
     // private:
          char* model;
          int miles;
          char* myfunc();

     public:
          // Constructor has no return type and has the same name as the class
          Car();
          // You can have multiple constructors of the same name but they need to have different
          // parameters so that the program can differentiate the two.
          Car(char*, int);

          // * Destructor, needed if you have pointers in your program
          // * Deallocates memory once you exit program, prevents memory leaks
          // * Destructor is needed to do this within the class, which is required because the
          // variables have private access so they cannot be deallocated outside of the class
          ~Car();
          // Getters
          int get_miles();
          char* get_model();
          // Setters
          void set_model(char*);
          // Since this is a car, we'll just name it drive();
          void drive();

}
