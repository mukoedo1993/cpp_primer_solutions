#include<regex>
#include<iostream>
#include<string>
bool valid(const std::smatch& m)
{
    //if there's an open parathesis before the area code
    if(m[1].matched)
    //the area code must be followed by a close parenthesis
    //and followed immediately by the rest of the number or a space
    return m[3].matched
    &&(m[4].matched==0||m[4].str()==" ");
    else
    //then there can't be a close after the area code
    //and followed immediately by the rest of the number or a space
    return !m[3].matched
    &&m[4].str()==m[6].str();
}


int main()
{
    //A pattern in a regular expression often contains one or more
    //subexpressions. A subexpression is a part of the pattern that
    //itself has meaning. Regular-expression grammars typically use 
    //paratheses to denote subexpressions.

    //r has two subexpressions: the first is the part of the file name before
    //the period
    //the second is the file extension
    std::regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$",std::regex::icase);
     std::string str("roku.cpp rock.sd rock.cc");
     //Our pattern now has two parathesized subexpressions:
     //([[:alpha:]]+) which is a sequence of one or more characters
     //(cpp|cxx|cc), which is the file extension
       std::smatch results;
     if(std::regex_search(str,results,r))
     std::cout<<results.str(1)<<std::endl;//print to first subexpression

     /*
     As in our original program, we call regex_search to look for our pattern
     r in the string named filename, and we pass the smatch object results to hold
     the results of the match. If the call succeeds, then we print the results. 
     However, in this program, we print str(1), which is the match for the first 
     subexpression.
     In addition to providing information about the overall match, the amtch objects 
     provide access to each matched subexpression in the pattern. The submatches are
     accessed positionally. 
     */

    /* subexpressions for data validation*/
    //One common use for subexpressions is to validate data that must match a specific 
    //format. For example, U.S. phone numbers have ten digits, consisting of an area code
    //and a seven-digit local number. The area code is often, but not always, enclosed
    //in paratheses. The remaining seven digits can be separated by a dash, a dot, or 
    //a space; or not separated at all. We might want to allow data with any of these
    //formats and reject numbers in other forms. We'll do a two-step process:
    //First: we'll use a regular express
    //Second:  we'll call a function to complete the validation
    //of the data.
    
    //a few more aspects of the ECMAscript regular-expression language:
    /*
    1: \{d}represents a single digit and \{d}{n}represents a sequence of n digits.
    2: A collection of characters inside square brackets allows a match to any of 
    those characters. (E.g. [-. ] matches a dash, a dot, or a space. Note that a dot 
    has no special meaning inside brackets.)
    3: A component followed by "?" is optional. 
    e.g.:
    \{d}{3}[-. ]?\{d}{4}
    This pattern would match 555-0132 555.0132 or 555 0132 5550132
    4: Like C++, ECMAscript uses a backlash to indicate that a character should
    represent itself, rather than its special meaning. Because our pattern includes
    paratheses, which are speical characters in ECMAscript, we must represent the parathese
    that are part of our pattern as\(  or \).
    
    Because backlash is a special character in C++, each place that a \ appears in the pattern,
    we must use a second backlash to indicate to C++ that we want a backlash.
    */

   //our overall expression has seven subexpressions: (ddd) separator ddd separator dddd
   //subexpressions 1,3,4 and 6 are optional; 2,5, and 7 hold the number
      
   std::string phone=
   "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";

   std::regex r1(phone);//a regex to find our pattern

   std::smatch m;
   std::string s;
   //read each record from the input file


   while(getline(std::cin,s)&&s!="q")
   {
       //for each matching phone number
       for(std::sregex_iterator it(s.begin(),s.end(),r1),it_end;it!=it_end;it++)
       {
              //check whether the number's formatting is valid
              if(valid(*it))
              std::cout<<"valid: "<<it->str()<<std::endl;
              else
              {
                  std::cout<<"not valid: "<<it->str()<<std::endl;
              }      
       }
   }
   /*
   We start by checking the first subexpression (i.e., the open parathesis)matched. That
   subexpression is in m[1]. If it matched, then the number starts with an open parenthesis.
   In this case, the overall number is valid if the subexpression following the area code
   also matched (meaning that there was a close parathesis after the area code). Moreover, if 
   the number is correctly parenthesized, then the next character must be a space or the first digit
   in the next part of the number.
   
   */
  

}
/*

rock
(100)2003345
valid: (100)2003345
(100)200 3345
valid: (100)200 3345
(100 200 3345
not valid: (100 200 3345
100 200 3345
valid: 100 200 3345
100-200-3345
valid: 100-200-3345
100.200.3345
valid: 100.200.3345
100200.3345
not valid: 100200.3345
*/