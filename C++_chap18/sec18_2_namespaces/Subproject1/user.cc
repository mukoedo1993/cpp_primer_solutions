#include"sales_data_sec18_2_1.h"
#include<iostream>
int main()
{
    
    cplusplus_primer::Sales_data trans1("shydh",13,6.8),trans2("shydh",14,8.3),sum,sum1;
    //...
   sum= trans1.combine(trans2);
    std::cout<<sum.ave_price();
    sum1=sum1.add(sum,sum);
    std::cout<<sum;
    std::cout<<"\n"<<sum1;
    return 0;
}
//g++ sales_data_sec18_2_1.h sales_data_sec18_2_1.cc user.cc