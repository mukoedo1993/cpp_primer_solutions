//A regular expression is a way of descrbing a sequence of characters.
#include<iostream>
#include<regex>
#include<stdexcept>
/*Using the regular expression library*/
//find the characters ei that follow  a character other than c
void prnt()
{
    static int i=0;
    i++;
    printf("%d",i);
}

//specifying options for a regex object
/*
When we define a regex or call assign on a regex to give it new value, we can
specifying one or more flags that affect how the regex operates. These flags control
the processing done by that object. Exactly one of the flags that specify a language
must be set. By default, the ECMAScrpit flag is set, which causes the regex to use the
ECMA-262 specification, which is the regular expression language that many Web browser
use.
The other three flags let us specify language-independent aspects of the regular expression
processing. For example, we can use the icase flag to find file names that have a particular
file extension. Most operating systems recognize extensions in a case-indeoendent manner--
we can store a C++ program in a file that ends in .cc, or .cC, or .CC.
*/

int main()
{
    //find the characters ei that follow a character other than c
   std::string pattern("[^c]ei");
   //we want the whole word in which our pattern appears
   pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
   std::regex r(pattern);//consider a regex to find pattern
   std::smatch results;//define an object to hold the results of a search
   //define a string that has text that does and doesn't match pattern
   std::string test_str="receipt freind theif freeind receive";
   //use r to find a match to pattern in test_str
   if(std::regex_search(test_str,results,r))//if there is a match
   std::cout<<results.str()<<std::endl;//print the matching word
   

   //one or more alphanumeric characters followed by a '.' followed by "cpp" or "cxx"
   //or "cc"
   std::regex r1("[[:alnum:]]+\\.(cpp|cxx|cc)$",std::regex::icase);
   std::smatch results1;
   std::string filename;
   while(std::cin>>filename&&filename!="q")
    if(regex_search(filename, results1,r1))
    std::cout<<results1.str()<<std::endl;//print the current match
    else
    {
        std::cout<<"Not matched!\n";
    }
    //Just as there are special characters in C++, regular expression languages 
    //typically also have special characters. For example, the dot(.) character 
    //usually matches any character. As we do in C++, we can escape the special nature
    //of a character by preceeding it with a blacklash. Because we can escape the special
    //nature of a character in C++, we must use a second backlash inside a string literal
    //indicate to C++ that we want a backlash.


    /*Errors in specifying or using a regular expression*/
    //We can think of a regular expression as itself a "program" in a simple programming
    //language. That language is not interpreted by the C++ compiler. Instead, a regular
    //expression is "compiled" at run time when a regex object is initialized with or assigned
    //a new pattern. As with any programming language, it is possible that the regular
    //expressions we write can have errors. 

    //If we make a mistake in writing a regular expression, then at run time  the library
    //will throw an exception of type regex_error. Like the standard exception types, 
    //regex_error has a what operation has describes the error that occured. A regex_error
    //also has a member named code that returns a numeric code corresponding to the type of
    //error that was encountered.
    //The values code returns are implementation defined. The standard errors that the RE
    //library can throw are listed.

    //e.g.1:
    try{
     //error: missing close bracket after alnum; the constructor will throw
    }catch(std::regex_error e)
    {
        std::cout<<e.what()<<"\ncode: "<<e.code()<<std::endl;
    }

    
}
