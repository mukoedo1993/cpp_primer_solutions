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
       std::sregex_iterator it(str.begin(),str.end(),r),it_end;
       
        if(it!=it_end)it++;else break;
           while(it!=it_end)
          {std::string mkft=it->str();
              std::string mkft1=std::regex_replace(mkft,r,fmt);
              std::cout<<mkft1<<std::endl;
              it++;
          }
   }
}
/*

Tom 1234567890 132-013.5960 (133)023-5436
132.013.5960.
133.023.5436.
q

*/