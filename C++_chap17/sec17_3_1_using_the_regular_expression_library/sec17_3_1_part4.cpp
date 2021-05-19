#include<regex>
#include<iostream>

int main()
{
    std::regex r("[[:alnum:]]+\\.(cpp|cc|cxx)$",std::regex::icase);
    std::cmatch results;//will match character array input sequences
    if(std::regex_search("mylife.cc",results,r))
    std::cout<<results.str()<<std::endl;//print the current match
    //In general, our programs will use string input sequences and the 
    //corresponding string verisons of the RE library components.
}

//Result:
//mylife.cc