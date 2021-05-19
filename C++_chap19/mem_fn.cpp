#include<iostream>
#include<cmath>
#include<functional>
struct A{
  double fcn(int i){
      std::cout<<"i is: "<<i<<std::endl;
      return 3.52;
  }
};
int main()
{
    A a;
    double (A::*ptr)(int);
    ptr=&A::fcn;
    std::cout<<"max one: "<<std::max<double>(13,std::mem_fn(ptr)(a,6))<<'\n';
    //A mem_fn is an adapter. It takes a pointer to a member function, and then
    //becomes a function that takes an object as the first parameter, and then, actually,
    //works as a literally variadic, takes the rest of parameters as parameter of the member function.
}
/*
max one: i is: 6
13
*/