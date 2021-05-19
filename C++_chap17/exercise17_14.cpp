#include<regex>
#include<iostream>
int main()
{   std::string seq("nimasile hehe.cc!");
     std::string rex("[[:alnum:]]+\\.(cpp|ckk|ctt)$");
     try{
     std::regex rex2("[[:alnum:]+\\.(cpp|ckk|ctt)$");
     }catch(std::regex_error rer0)
     {
         std::cerr<<rer0.what()<<" "<<rer0.code()<<std::endl;
         //Unexpected character in bracket expression. 4
     }
     try{
         std::regex rex3("[[:alnu:]]+\\.(cpp|ckk|ctt)$");
     }catch(std::regex_error rer0)
     {
         std::cerr<<rer0.what()<<" "<<rer0.code()<<std::endl;
         //Invalid character class. 0
     }
       try{
         std::regex rex3("[[:alnum]]+\\.(cpp|ckk|ctt)");
     }catch(std::regex_error rer0)
     {
         std::cerr<<rer0.what()<<" "<<rer0.code()<<std::endl;
         //Unexpected end of character class. 1
     }

     try{
         std::regex rex3("[[:alnum:]]+\\.cpp+[[:alpha:]]");
     }catch(std::regex_error rer0)
     {
         std::cerr<<rer0.what()<<" "<<rer0.code()<<std::endl;
         //Not error
     }
      
        try{
         std::regex rex3("[[:alnum:]]+\\.cpp");
     }catch(std::regex_error rer0)
     {
         std::cerr<<rer0.what()<<" "<<rer0.code()<<std::endl;
         //Not error
     }
     


     std::regex rex1(rex);
    std::cmatch cmtch1;
    std::smatch smtch1;
    //not compiled
    /*
    try{
    if(std::regex_search(seq,cmtch1,rex1))
    std::cout<<cmtch1.str()<<std::endl;
    }catch(...)
    {
       std::cerr<<rer.what()<<" "<<rer.code()<<std::endl;
    }
    */

      try{
     std::string r1("[[:alpha:]]*[^k]cp[[:alpha:]]{1,0}");
     std::regex r2_(r1);
     }catch(std::regex_error reg)
     {
         std::cout<<reg.what()<<std::endl<<reg.code()<<std::endl;
     }
    /*
    Invalid range in brace expression.
7
    */

   }
