#include"Blob_chap16_1_5.h"

template bool compare(const int&,const int&);
template class Blob<std::string>;


//If we comment line 3 and lin 4, we will get: 
/*

/usr/bin/ld: /tmp/ccfewM0A.o: in function `__static_initialization_and_destruction_0(int, int)':
Application.cc:(.text+0x3bf): undefined reference to `bool compare<int>(int const&, int const&)'
collect2: error: ld returned 1 exit status

*/