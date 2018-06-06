#include "Car.h"

Car::Car(){
     // The "this" pointer refers to this class, communicates to you that this variable is
     // associated with this class
     // Pointers use arrows
     this->model = 0;
     this->miles = 0;
}

Car::Car(char* model, int miles) {
     // This pointer is now necessary because the variable names here and the ones defined in the
     // class are the same name
     // This will cause it to fail due to not declaring it as a new variable and then trying to
     // delete it. This should be fixable via the string library.
     this->model = model;
     this->miles = miles;
}

char* Car::get_miles(){
     // Returns the class variable
     return this->miles;
}

void Car::drive(int miles){
     // Increments class variable by input miles
     this->miles += miles;
}

char* Car::get_model() {
     return this->model;
}

void Car::set_model(char* model) {
     // delete this->model;
     this->model = model;
}

Car::~Car(){
     // Only this->model because it was the only pointer, only have to do this for pointers
     // This will cause it to fail due to not declaring it as a new variable and then trying to
     // delete it. This should be fixable via the string library.
     delete this->model;
}
