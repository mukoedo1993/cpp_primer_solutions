#include<vector>
#include<iostream>
#include"sd.h"
using std::vector;
using std::string;
extern template class vector<string>;
template class vector<Sales_data>;
int main()
{
   vector<string>vi={"dfss","s","ni","kimura"};
   for(auto v:vi)
   std::cout<<v<<std::endl;
}
/*
(base) zcw@mukoedo1993:~/C++chap16$ g++ ex16_25a.cc ex16_25b.cc sd.h
(base) zcw@mukoedo1993:~/C++chap16$ ./a.out
dfss
s
ni
kimura
*/