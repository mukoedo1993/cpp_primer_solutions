#include<iostream>
int i=13;
int fcn1()
{
    std::cout<<"ni.cpp\n";
    return 15;
}
int fcn()
{
    fcn1();
    std::cout<<i<<std::endl;
    return i;
}