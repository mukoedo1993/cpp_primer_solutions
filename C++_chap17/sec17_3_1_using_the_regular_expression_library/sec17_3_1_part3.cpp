/* Regular expression classes and the input sequence type */
//We can search any of several types of input sequence. The input can be ordinary
//char data or wchar_t data and those characters can be stored in a library string 
//or in an array of char (or the wide character versions, wstring or array of wchar_t).
//The RE library defines separate types that correspond to these differing types of
//input sequences.
// For example, the regex class holds regular expressions of type char. The libraru also
//defines a wregex class that holds type wchar_t and has all the same operations as regex
//The only difference is that the initializers of a wregex must use wchar_t instead of char.


#include<iostream>
#include<regex>

int main()
{
    std::regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$",std::regex::icase);
    std::smatch results;//will match a string input sequence, but not char*
    if(std::regex_search("mylife.cc",results,r))//error: char*input
    std::cout<<results.str()<<std::endl;
}

//error code:
/*
 error: no matching function for call to ‘regex_search(const char [10],
  std::__cxx11::smatch&, std::__cxx11::regex&)’
*/