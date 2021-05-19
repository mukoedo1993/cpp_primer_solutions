#include<regex>
#include<iostream>
#include<string>
//When we want to find and replace a regular expression in the input sequence, we call
//regex_replace. Like the search functions, regex_replace. 
/*
We compose a replacement string by including the characters we want, intermixed with
subexpressions from the matched substring...
...
...

*/
int main()
{
    //Use the 2nd, 5th and 7th parts of our original data.
   std::string fmt="$2.$5.$7.";//reformat numbers to ddd.ddd.dddd

   std::string phone=
   "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
   std::regex r(phone);

   std::string number("(908) 555-0132");
   std::string str;
    std::cout<<regex_replace(number,r,fmt)<<std::endl;//908.555.0132.
   while(getline(std::cin,str)&&str!="q")
   {
           std::cout<<regex_replace(str,r,fmt)<<std::endl;
   }
   /*Flags to control matches and formatting*/
   //Just as the library defines flags to direct how to process a regular expression,
   // the library also defines flags that we can use to control the match process or
   //the formatting done during a replacement. These values are listed. These flags can
   //be passed to the regex_search or regex_search functions or to the format members
   //of class smatch.

   //The match and format flags have type match_flag_type. These values are defined in a
   //namespace named regex_constants. Like placeholders, which we used with bind, regex_constants
   //is a namespace defined inside the std namespace. To use a name from regex_constants,
   //we must qualify that name with teh names of both namespaces:
   using std::regex_constants::format_no_copy;

   //This declaration says that when our code uses format_no_copy, we want the object of
   //that name from the namespace std::regex_constants. We can instead provide the alternative
   //form that we will cover:
   using namespace std::regex_constants;

   /*Using Format flags*/
   //By default, regex_replace outputs its entire input sequence. The parts that don't match
   //the regular expression are output without change; the parts that match are formatted as indicated by 
   //the given format string. We can change this default behavior by specifying format_no_copy in the
   //call to regex_replace

    //generate just the phone numbers: use a new format string
   std::string fmt2="$2.$5.$7.";//put space after the last number as a separator
   //tell regex_replace to copy only the text that it replaces
   std::string num1("Tom 1032345678");
   std::cout<<std::regex_replace(num1,r,fmt2,format_no_copy)<<std::endl;

}
/*

908.555.0132.
(100)2003456
100.200.3456.
100-200.3456
100.200.3456.
100 020-6789
100.020.6789.
q
103.234.5678.

*/