#include<iostream>
#include<list>
#include<vector>
using std::vector;using std::list;using std::string;
//Basic summary:
//we take three parameters, and our range of searching is [it1,it2), 
//If the value is not found in the range, we will return the
template<typename it,typename v>it find_yaju(it it1,it it2,const v&value)
{  
   for(auto it_=it1;it_!=it2;it_++)
   {
       if(*it_==value)
       return it_;
   }
   return it2;//if not find, return the last iterator given
}
int main()
{
   vector<int>vi={1,3,-5,6,-17,20,-34,-8};
   list<string>vs={"kimura","yaju","oubei","sb"};
   auto it1=find_yaju(vi.cbegin(),vi.cend(),6);
   std::cout<<*it1<<std::endl;//6
   list<string>::const_iterator it2=find_yaju(vs.cbegin(),vs.cend(),string("oubei"));
   std::cout<<*it2<<std::endl;//oubei
   
}