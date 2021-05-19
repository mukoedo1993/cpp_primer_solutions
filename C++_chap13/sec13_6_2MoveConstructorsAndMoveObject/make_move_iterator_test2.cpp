#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iterator>
using std::vector;
using std::string;
int main()
{
    
    vector<string>v2={"naka","dashi","sicupo","dj"};
    vector<string>v1(std::make_move_iterator(v2.begin()),std::make_move_iterator(v2.end()-1));
    //for_each(v1.begin(),v1.end(),[](int i)->void{std::cout<<i<<" ";});
    for_each(v1.cbegin(),v1.cend(),[](const string& i)->void{std::cout<<i<<" ";});
    std::cout<<std::endl;
    for_each(v2.cbegin(),v2.cend(),[](const string& i)->void{std::cout<<i<<" ";});
    std::cout<<std::endl;
}
//Result:
/*
naka dashi sicupo 
   dj

*/