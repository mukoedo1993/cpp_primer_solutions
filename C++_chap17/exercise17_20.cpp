#include<regex>
#include<iostream>
#include<string>
#include<stdexcept>
bool valid(const std::smatch& sm)
{
    
    if(sm[2].str()!="0731")
    throw std::invalid_argument("Not a nationwide acceptable Changsha phone number within P.R. China!");
    if(sm[1].matched) 
    return ((sm[3].matched)
    &&(0==sm[5].matched));
  
    else
        return
        !sm[3].matched
        &&(sm[5].matched);
       

   
}
int main()
{
    std::string str1;
    std::string str("(\\()?(\\d{4})(\\))?(\\d{4})([-. ])?(\\d{4})");
    std::regex r(str);
    while(getline(std::cin,str1)&&str1!="q")
    {
    for(std::sregex_iterator it(str1.begin(),str1.end(),r),it_end;it!=it_end;it++)
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

0731)85116511
invalid: 0731)85116511
(0731)8511-6511
invalid: (0731)8511-6511
07318511 6511
valid: 07318511 6511
07318511-6511
valid: 07318511-6511
07318511.6511
valid: 07318511.6511
q

*/