#include"Sales_data2.h"

int main()
{
    string str1="bako",str2="hako",str3="hako";
    double pc1=13.4,pc2=15.6,pc3=27.8;
    int No1=13,No2=14,No3=15;
    Sales_data item1(str1,No1,pc1);
    Sales_data item2(str2,No2,pc2);
    Sales_data item3(str3,No3,pc3);
    Sales_data item4;
    item4=operator+(item1,item2);
     std::cout<<item3;
    item3+=item4;
    std::cout<<item1;
    std::cout<<item2;
    std::cout<<item4;
      std::cout<<item3;
}