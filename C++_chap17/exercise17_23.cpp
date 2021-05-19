#include<regex>
#include<iostream>
#include<string>
bool valid(const std::smatch& sm)
{
    if(!sm[1].matched)
    return !sm[2].matched;
    else
    return true;
}
int main()
{
std::string str;
std::regex r("(\\d{4})?(\\-)?(\\d{5})");
while(getline(std::cin,str)&&str!="q")
{
    for(std::sregex_iterator it(str.begin(),str.end(),r),it_end;it!=it_end;it++)
    {
       if(valid(*it))
       std::cout<<"valid: "<<it->str()<<std::endl;
       else
       {
           std::cout<<"invalid: "<<it->str()<<std::endl;
       }
       
    }
}
}

/*

-09384
invalid: -09384
1203-09836
valid: 1203-09836
120309836
valid: 120309836
q

*/