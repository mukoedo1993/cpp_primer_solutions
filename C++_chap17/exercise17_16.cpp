#include<regex>
#include<iostream>

int main()
{
   std::smatch result;
   std::string str;
   std::string reg("[^c]ei");
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


//Result: only related alphabetical part is catched at each time.
/*
cei
Not found!
sei
sei
2sei
sei
23sei
sei
23csei
sei
csei234
sei
scei234
Not found!
sdei234
dei
2sei56
sei
q
*/
