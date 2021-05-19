
#include<iostream>
#include<vector>
using std::vector; using std::string;

int main()
{
   //test:
   vector<string>svec1={"stone","neck"};
   vector<string> svec2={"stone","neck2"};
   auto svec3=svec1;
std::cout<<std::boolalpha;
std::cout<<"part a: "<<("cobble"=="stone")<<"\n";//false
std::cout<<"part b: "<<(svec1[0]==svec2[0])<<"\n";//true
std::cout<<"part c: "<<(svec1==svec2)<<"\n";//false
std::cout<<"part d: "<<(svec1[0]=="stone")<<"\n";//true
std::cout<<"part extra: "<<(svec1==svec3)<<"\n";//true

}