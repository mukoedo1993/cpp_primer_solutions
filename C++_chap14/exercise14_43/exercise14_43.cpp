#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<iterator>
bool holds(int i1)
{
    std::modulus<int>mdls;
    std::vector<int>v={12,13,18,16};
    for(auto i:v)
if(mdls(i,i1)==0)return true;//if i1%i==0
return false;
}
int main()
{
    std::vector<int>v={12,13,18,16};
    int i=2,i1=7,i2=3;
     std::cout<<std::boolalpha;
     std::cout<<holds(i)<<std::endl;//true
     std::cout<<holds(i1)<<std::endl;//false
     std::cout<<holds(i2)<<std::endl;//true
    

    
}