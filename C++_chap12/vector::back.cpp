//http://www.cplusplus.com/reference/vector/vector/back/
//Access last element
//Returns a reference to the last element in the vector.
//Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
//Calling this function on an empty container causes undefined behavior.

// vector::back
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
