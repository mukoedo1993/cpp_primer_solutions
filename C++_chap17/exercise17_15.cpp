#include<regex>
#include<iostream>

int main()
{
   std::smatch result;
   std::string str;
   std::string reg("[[:alpha:]]*[^c]ei[[:alpha:]]*");
   std::regex rex1(reg);
   while(std::cin>>str&&str!="q")
   {
   if(std::regex_search(str,result,rex1))
   std::cout<<result.str()<<std::endl;
   else
   {
       std::cout<<"Not found!\n";
   }
   
   }
}

/*

3dkei
dkei
@dkei
dkei
@d$dkei
dkei
keiceisd%54d^d
keiceisd
qq
Not found!
cei
Not found!
3c3ei
c3ei
crei
crei
clei
clei
c^ei
c^ei
c#ei
c#ei
cei2637    
Not found!
weird2637
weird
wei2637
wei
q
*/