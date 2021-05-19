#include<iostream>

int j11 = 10;
constexpr int i11 = 42;//type of i is const int.
//i and j must be defined outside of any function. ...
//...Otherwise, their addresses might be changed. ERRORs will appear.
int main()
{
    int j11 = 3;
    constexpr int i11 = 420;//type of i is const int.
    //i and j must be defined outside of any function.
    //Otherwise, their addresses might be changed. ERRORs will appear.
    const int* p = &::i11;//p is a constant pointer to the const int i1
   int* p1 = &::j11;//p1 is a constant pointer to the int j1.
    std::cout << *p << " " << *p1 << std::endl;
    //int null = 0, * p = null;//A value of type int* cannot be used to
    //...initialize *p.
    int null = 0, * p2 = &null;
    std::cout <<*p2<< std::endl;

}