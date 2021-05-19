#include<memory>
#include<iostream>
struct B{};
struct D1 final:B{

};
int main()
{
    B b1,*b2=&b1,*b3;
    D1 d1,*d2=&d1;
      b3=d2;
    std::shared_ptr<const int>sptr(std::make_shared<int>(13));//ok
    std::shared_ptr<const int>sptr1(std::make_shared<const int>(14));//also ok
    
   
}



/*
A: The compiler cannot deduct the type of make_shared<typename T>we want to use.
For example: I made above.

*/
//FUrther reading:
//https://stackoverflow.com/questions/32724136/why-stdmake-shared-has-to-be-provided-type-info-but-stdmake-pair-doesnt-hav