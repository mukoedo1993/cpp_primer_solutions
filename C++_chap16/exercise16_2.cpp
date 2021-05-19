#include<functional>
#include<vector>
#include<cstring>
using std::greater;using std::string;using std::vector;
#include<iostream>
template<typename T>int compare(const T &lhs,const T&rhs)
{

    if(greater<T>()(lhs,rhs))return 1;
    if(greater<T>()(rhs,lhs))return -1;
    return 0;
}
template<unsigned M,unsigned N>int compare1(const char(&p)[M],const char(&q)[N])
{
    return std::strcmp(p,q);
}


int main()
{ 
   vector<int>v1(5,10);
   vector<int>v2(10,5);
   std::cout<<compare(v1,v2);//1
   std::cout<<compare(string("sn"),string("sn"));//0
   std::cout<<compare1("snz","snk");//15

}