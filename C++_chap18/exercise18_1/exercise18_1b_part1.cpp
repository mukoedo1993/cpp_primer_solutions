#include<iostream>
#include<stdexcept>
int main()
{
  
     std::range_error r("error");
      std::exception *p=&r;//exception is a base class for 
      //range_error
      throw *p;
     //It should throw the object to which exception points.
     //However, th pointer p points to an range_error object r.
     //The object r should be sliced down.

    
   
}

/*

terminate called after throwing an instance of 'std::exception'
  what():  std::exception

*/