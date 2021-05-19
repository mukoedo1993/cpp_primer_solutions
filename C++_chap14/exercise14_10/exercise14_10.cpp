#include<iostream>
#include<fstream>
#include"Sales_data.h"
int main()
{
    std::ifstream input("ex14_10i.txt");
    while(true)
    {
        Sales_data item1;
        input>>item1;
        std::cout<<item1;
        if(!input)break;
    }

}