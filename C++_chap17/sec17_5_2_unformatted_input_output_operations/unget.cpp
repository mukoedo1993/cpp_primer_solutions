#include<iostream>
#include<sstream>
int main()
{
    char ch;std::string str;
    std::istringstream stre("coup de'tat!");
    while(std::cin>>str&&str!="q")
    {
       ch= stre.get();stre.get();
       std::cout<<ch;
       stre.unget();//move stre back one byte, return is.
       std::cout<<ch;
    }
}

/*

 
 
 
 
 
s
ccd
ood
uud
ppd
  d
ddd
eed
''d
ttd
aad
ttd
!!d
��d
��q

*/