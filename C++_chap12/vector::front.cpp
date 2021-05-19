#http://www.cplusplus.com/reference/vector/vector/front/

// vector::front
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

  return 0;
}

//A reference to the first element in the vector container.
//If the vector object is const-qualified, the function returns a const_reference. Otherwise, it returns a reference.
//Member types reference and const_reference are the reference types to the elements of the container (see vector member types).
