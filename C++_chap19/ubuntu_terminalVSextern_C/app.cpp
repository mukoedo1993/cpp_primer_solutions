#include<iostream>
#include<typeinfo>
#ifdef __cplusplus
extern "C"{
#endif
#include"cfile.h"
#ifdef __cplusplus
}
#endif
using namespace std;
//Question: when to use extern c in c++?
//Answer: When you are wrting C++ code and including c code in that. 


int add(int){return 1;}
int add(float){return 1;}

int main()
{
  
  fcn();
 
  return 0;
}

//hehefcn1(int)!