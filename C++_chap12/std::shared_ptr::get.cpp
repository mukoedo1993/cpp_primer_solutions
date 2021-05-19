//http://www.cplusplus.com/reference/memory/shared_ptr/get/#:~:text=std%3A%3Ashared_ptr%3A%3Aget&text=Returns%20the%20stored%20pointer.,same%20as%20its%20owned%20pointer.

//It returns a bulit-in pointer to the object that the smart pointer is managing.

// shared_ptr::get example
#include <iostream>
#include <memory>//shared_ptr<type> 

int main () {
  int* p = new int (10);
  std::shared_ptr<int> a (p);

  if (a.get()==p)
    std::cout << "a and p point to the same location\n";

  // three ways of accessing the same address:
  std::cout << *a.get() << "\n";
  std::cout << *a << "\n";
  std::cout << *p << "\n";

  return 0;
}
