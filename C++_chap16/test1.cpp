#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
int main()
{
   vector<int>v1(10,5);
   for_each(v1.cbegin(),v1.cend(),[](int i){std::cout<<i<<" ";});
   std::cout<<"\n";
   vector<int>v2(5,10);
    for_each(v2.cbegin(),v2.cend(),[](int i){std::cout<<i<<" ";});
    std::cout<<"\n";
    std::cout<<std::boolalpha;
   std::cout<<(v1>v2)<<std::endl;
}
/*
5 5 5 5 5 5 5 5 5 5 
10 10 10 10 10 
false
*/