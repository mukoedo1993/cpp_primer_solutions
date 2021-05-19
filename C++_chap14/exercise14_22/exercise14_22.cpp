#include"Sales_data3.h"

int main()
{
    string str1="bako",str2="hako",str3="haikou";
    double pc1=13.4,pc2=15.6,pc3=27.8;
    int No1=13,No2=14,No3=15;
    Sales_data item1(str1,No1,pc1);
    
    std::cout<<item1;
    item1=str3;
    std::cout<<item1;
}