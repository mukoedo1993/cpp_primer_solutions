#include"Vec_ex16_58Vec.h"
#include"ex16_58_implementation.h"
#include"sales_data.h"

int main()
{


  //test 1:
  Sales_data sales(std::string("kimura"),13);


  //test 2:
    Vec<Sales_data>v_sa;
    v_sa.emplace_back("item",13,8.5);//OK

  //  v_sa.push_back("item",13,8.5);//error
    std::cout<<*(v_sa.begin());
}


/*

bookNo is:item
 units sold: 13
revenue is: 110.5
*/