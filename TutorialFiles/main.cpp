#include "Car.h"
#include <iostream>

using namespace std;

int main(){
     Car car1;
     char model1[] = "Ford";
     Car car2(model1, 0);
     char model2[] = "Chevy";
     Car *car3 = new Car(model2, 0);
     // Pointer
     cout << "Car 3 miles: " << car3->get_miles() << endl;
     // Not pointer
     cout << "Car 1 miles: " << car1.get_miles() << endl;
     delete car3;
     return 0;

}
