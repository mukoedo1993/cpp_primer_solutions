convert string to char array in C++
https://www.geeksforgeeks.org/convert-string-char-array-cpp/#:~:text=A%20way%20to%20do%20this,current%20value%20of%20the%20string.


How to safely deal with built-in array in shared_ptr?
1:lambda expression [](int *i){delete []i;}as the second parameter on the constructor of shared_ptr<int>
2: shared_ptr<int>(new int[10],std::default_delete<int[]>());
https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap12/test_4.cpp



Returns the number of different shared_ptr instances (this included) managing the current object. If there is no managed object, ​0​ is returned, EVEN IF
it is constructed by a copy constructor.
https://en.cppreference.com/w/cpp/memory/shared_ptr/use_count

std::make_shared could only be used in a parameter of a constructor of std::shared_ptr.


.......................................................................
std::unique_ptr<type,DeleterType>(new type(),Deleter);
std::shared_ptr<type>(new type(),Deleter);
e.g.:
  https://github.com/mukoedo1993/All_files/blob/master/C%2B%2B_chap12/swine_test1.cpp

.......................................................................
