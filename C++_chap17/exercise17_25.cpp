#include<iostream>
#include<regex>
#include<string>
using namespace std::regex_constants;


int main()
{
     std::string phone=
   "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
   std::regex r(phone);
   std::string fmt="$2.$5.$7.";
   std::string str;
   while(getline(std::cin,str)&&str!="q")
   {
       int cnt=0;
       std::sregex_iterator it(str.begin(),str.end(),r);
          std::string mkft=it->str();
              std::string mkft1=std::regex_replace(mkft,r,fmt);
              std::cout<<mkft1<<std::endl;
   
   }
}

/*

Tom (102)2345687 (103)2673865
102.234.5687.
Sam (103)2567384 103-234-3654
103.256.7384.
q
*/