#include<iostream>
#include<fstream>
#include"Sales_data.h"
int main()
{
    std::ifstream input("sec14_2_2.txt");
    if(!input.is_open())exit(-1);
    std::string str="nmsl";
    unsigned usgn=13;
    double p1=13.4;
    Sales_data bk1(str,usgn,p1);
    Sales_data bk2;
    while(true)
    {
        input>>bk2;
    std::cout<<bk2;//It will show failuere at the end of the file
    if(!input)break;
}

}