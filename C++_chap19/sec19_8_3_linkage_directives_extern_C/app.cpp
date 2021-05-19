#include<iostream>
#include<typeinfo>
extern "C"{
#include"cfile.h"
}
using namespace std;

extern "C" void(*pf1_)(int);
extern "C" void funcyaju(int){}
#ifdef __cplusplus
extern "C" 
#endif
void func(int){}//no overloading allowed

int main()
{
  void(*pf1)(int);
  fcn();
  func(12);
 
 auto pf2=fcn1;
 auto pf1__=&funcyaju;
  pf1=pf1__;
  //g++ accepts an error that allows the interchange between C-style function 
  //and C++-style function. But it is still an error, actually... 
 (*pf2)(54);
  return 0;
}

//hehefcn1(int)!