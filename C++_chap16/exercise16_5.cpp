#include<iostream>
#include<array>
using std::array;
template<typename T>void print(const T&only_element)
{
    for(auto it=only_element.cbegin();it!=only_element.cend();it++)
    std::cout<<*it<<" ";
    
}

int main()
{
   array<int,10>a_int={1,2,-3,5,7,8,9,6,-4};
   array<std::string,7>a_s={"sjd","sj","khong","pat","kyjuu"};
   print(a_int);
   print(a_s);
   std::cout<<std::endl;
}
/*Our result:*/
/*
1 2 -3 5 7 8 9 6 -4 0 sjd sj khong pat kyjuu
*/