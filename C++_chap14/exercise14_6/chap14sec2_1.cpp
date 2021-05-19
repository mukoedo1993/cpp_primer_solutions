#include<iostream>
#include"Sales_data.h"
#include<fstream>
#include<sstream>
#include<string>
int main()
{
  std::ifstream in("sec14_2_1i.txt");
   std::ofstream of("sec14_2_1o.txt");
   if(of.is_open())std::cout<<"hehe!";
   std::string str;
   while(getline(in,str))
   {
       std::istringstream Ob1(str);
   Sales_data bk1;
      Ob1>>bk1;
      of<<bk1;
    
   }
}