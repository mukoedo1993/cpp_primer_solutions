#include<functional>
std::less
operator():
https://en.cppreference.com/w/cpp/utility/functional/less

less<T>()(13,14):a temporary object of less<T>calls the call operator and takes 13 and 14 as parameters.

compare two different vectors: 
https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap16/test1.cpp



exercise16_13:
non-template non-member friend function:(see the approach 3):
https://web.mst.edu/~nmjxv3/articles/templates.html

......
Now, you may be wondering why I switched my example function defnition. 
As it turns out, this sort of non-template friend function is unusual since the function is neither 
in the global scope nor a member of class BlotPtr. This means that our function doesn't live in the "standard" places you'd expect it to; neither ::operator== nor BlotPtr<int>::operator== exist. Fortunately, C++ has a feature called ADL, or Argument Dependent Lookup, that can search through functions that aren't in the current scope, but exist in a class or namespace that is suggested by the type of the arguments handed to the function call:
......


......
Any default argument of a class member function must be given inside a class, rather than outside the class, i.e., given simultaneously within the declaration.
https://github.com/mukoedo1993/All_files/tree/master/C%2B%2B_chap16/exercise16_16
e.g.:
template<class T>
Vec<T>::resize();



......
https://github.com/mukoedo1993/All_files/edit/master/C++_chap12/README.txt
......


exercise16_60:
16_60ver2 is a better one. Because, when we want to pass a parameter of a function to another function within the block, it is automatically passed as a
lvalue. If we use std::forward<Args>(args)... here, things will be much better.
