#include<array>
#include<iostream>
#include<algorithm>
#include<deque>
using std::array;
using std::deque;
template<typename T>void print_all(const T&arry)
{
    for(auto it=arry.begin();it!=arry.end();it++)
    std::cout<<*it<<" ";
    std::cout<<std::endl;
}

template<typename T>void print_all1(const T&arry)
{
     
    for(typename T::value_type it=typename T::value_type();it!=arry.size();it++)
    std::cout<<arry[it]<<" ";
    std::cout<<std::endl;
}
int main()
{
     array<int,10>arr={1,2,3,4,5,6,7,8} ;
     print_all1(arr);/*1 2 3 4 5 6 7 8 0 0 */
     deque<int>fi={1,2,3,4,5,6,7,89,10};
     std::cout<<std::endl;/*1 2 3 4 5 6 7 89 10*/
     print_all1(fi);
    
    std::cout<<std::endl;
     print_all(arr);
      std::cout<<std::endl;
     print_all(fi);
}
/*

1 2 3 4 5 6 7 8 0 0 

1 2 3 4 5 6 7 89 10 

1 2 3 4 5 6 7 8 0 0 

1 2 3 4 5 6 7 89 10 
*/