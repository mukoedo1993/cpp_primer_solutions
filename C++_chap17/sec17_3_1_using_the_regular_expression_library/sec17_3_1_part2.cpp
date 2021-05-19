#include<regex>
#include<iostream>
int main()
{
      //e.g.1:
    try{

     //error: missing close bracket after alnum; the constructor will throw
     std::regex("[[:alnum:]+\\.(cpp|cc|cxx)$",std::regex::icase);
    }catch(std::regex_error e)
    {
        std::cout<<e.what()<<"\ncode: "<<e.code()<<std::endl;
    }


}

//Result:
/*
Unexpected character in bracket expression.
code: 4
*/