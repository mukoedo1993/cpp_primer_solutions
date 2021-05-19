#include<iostream>
#include"Sales_data.h"
int main()
{
    Sales_data bk1,bk2;
    std::cin>>bk1;
    bk2=bk1;
    bk1+=bk2;
std::cout<<std::endl<<bk1;
}