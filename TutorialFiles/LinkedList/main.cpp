#include "LinkedList.h"
#include <iostream>

int main() {
     LinkedList *myLL = new LinkedList;
     std::cout << "helloworld";
     try {
          // myLL.insert(1,5);
          myLL.insert(0,3);
          myLL.insert(1,5);
          myLL.insert(1,7);
          myLL.set(2,13);
          
          for(int i = 0; i < myLL.getSize(); i++) {
               std::cout << myLL.get(1);
          }
     }
     catch (const char *msg) {
          std::cout << msg << std::endl;
     }
     return 0;
}
