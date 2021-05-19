#include"Sales_data1.h"
#include <iostream>
#include <string>
#include<utility>
using std::string;
using std::istream;
using std::ostream;
int main()
{
 Sales_data item1("str",13);
 std::cout<<item1<<std::endl;

auto item2=static_cast<double>(item1);
auto item3=static_cast<std::string>(item1);
 std::cout<<item2<<std::endl;
  std::cout<<item3<<std::endl;
}