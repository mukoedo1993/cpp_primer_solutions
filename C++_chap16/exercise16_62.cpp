#include"sales_data.h"
#include<iostream>
#include<unordered_set>

namespace std{
    template<>
    class hash<Sales_data>
    {
        friend  bool operator==(const Sales_data&lhs,const Sales_data&rhs);
        public:
        //friend class unordered_multiset<Sales_data>;
        
       typedef Sales_data type;
       size_t operator()(const Sales_data& orig)const&{
           return hash<std::string>()(orig.bookNo)^
           hash<unsigned>()(orig.units_sold)^
           
           hash<double>()(orig.revenue);
       }
      
    };

}
 bool operator==(const Sales_data&lhs,const Sales_data&rhs)
      {
          return std::hash<Sales_data>()(lhs)==std::hash<Sales_data>()(rhs);
      }

int main()
{
   Sales_data yaju1("sjd",13,2.8),yaju2("sbk",17);
   std::unordered_multiset<Sales_data>unms;
   unms.insert(yaju1);
   unms.insert(yaju1);unms.insert(yaju2);unms.insert(yaju1);
   for(auto it=unms.begin();it!=unms.end();it++)
   {
       
       std::cout<<*it<<std::endl;
       if(it!=unms.begin())
       {   
         bool tr=std::hash<Sales_data>()(*it)==std::hash<Sales_data>()(*it);
         
         std::cout<<std::boolalpha<<tr<<std::endl;
       }
     
   }
   std::hash<Sales_data>Ob1;
   std::cout<<(Ob1(yaju1)==Ob1(yaju2));
}

/*

bookNo is:sbk
 units sold: 17
revenue is: 1377

bookNo is:sjd
 units sold: 13
revenue is: 36.4

true
bookNo is:sjd
 units sold: 13
revenue is: 36.4

true
bookNo is:sjd
 units sold: 13
revenue is: 36.4

true
false

*/