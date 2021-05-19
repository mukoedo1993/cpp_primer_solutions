#include<map>
#include<string>
#include<sstream>
#include<iostream>
#include<functional>//The library function type
using std::map;using std::string;using std::function;
int main(){
map<string,function<int(int,int)>>binops=
{
    {"+",std::plus<int>()},
    {"-",std::minus<int>()},
    {"*",std::multiplies<int>()},
    {"/",std::divides<int>()},
    {"%",std::modulus<int>()},
};
string str;
std::cout<<"Please enter a valid command: ";
while(getline(std::cin,str))
{
    
    int a,b;string str1;
    if(str=="q")    
    {
        std::cout<<"Quit!\n";
        break;
    }
   std::istringstream Ob1(str);

   if(Ob1>>a>>str1>>b)
   std::cout<<"Result is: "<<binops[str1](a,b);
   else
   {
    std::cerr<<"Wrong format!\n";
    break;
   }
   std::cout<<"\n"<<"Please enter next command: ";
}



return 0;
}