// bad_alloc example
#include <iostream>     // std::cout
#include <new>          // std::bad_alloc

int main () {
  try
  {
    std::cout << "allocating memory\n";
    int* myarray= new(std::nothrow) int[1000000000];
    
    //if std::nothrow is not used, bad_alloc exception will be thrown 
    
    if(!myarray)
      std::cout << "Memory allocation failed";
  
  }
  catch (std::bad_alloc& ba)
  {
    //std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    std::cout << "bad_alloc caught: " << ba.what() << '\n';
  }
  
  return 0;
}
