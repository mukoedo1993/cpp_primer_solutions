#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
int main()
{
    std::vector<int>sts={1,3,-4,-23,19,58,-13,16};
    for(int st:sts)std::cout<<st<<" ";
    std::cout<<std::endl;
    std::set<int*>sts_ptr;
    for(auto &it:sts)sts_ptr.insert(sts_ptr.begin(),&it);
    for(auto it=sts_ptr.begin();it!=sts_ptr.end();it++)
       std::cout<<*(*it)<<" ";
    std::cout<<std::endl;
}