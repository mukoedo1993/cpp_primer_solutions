#include<iostream>
#include<stdexcept>
int main()
{
  
     std::range_error r("error");
      std::exception *p=&r;//exception is a base class for 
      throw p;   
}
//terminate called after throwing an instance of 'std::exception*'