#include<iostream>
#include<stdexcept>
int main()
{
  
     std::range_error r("error");
      throw r;
    
     /*
     terminate called after throwing an instance of 'std::range_error'
  what():  error
     */
}