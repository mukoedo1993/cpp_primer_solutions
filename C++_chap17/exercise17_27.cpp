#include<iostream>
#include<regex>
#include<string>
int main()
{
    std::string str;
    std::string s_reg("(\\d{5})(\\-)?(\\d{4})");
    std::string fmt("$1-$3");
    std::regex r(s_reg);
    while(getline(std::cin,str)&&str!="q")
    {
        for(std::sregex_iterator it(str.begin(),str.end(),r),it_end;it!=it_end;it++)
        {
            std::string mkft=it->str();
            std::cout<<std::regex_replace(mkft,r,fmt)<<"\n";
        }
    }
}
/*

10105-4356 102348753 10394-9763
10105-4356
10234-8753
10394-9763
q

*/