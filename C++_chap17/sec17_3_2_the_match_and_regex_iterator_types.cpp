#include<regex>
#include<iostream>
//We can get all the matches by using an sregex_iterator. The regex iterators are iterator adaptors 
//matches by using an sregex_iterator.
//The regex iterators are iterator adaptors that are bound to an input sequence and a regex
//object.

/*Using an sregex_iterator*/
//For now, what we need to know is that these types let us see the context of a match.
//The match types have members named prefix and suffix, which return a ssub_match object
//representing the part of the input sequence ahead of and after the current match, respectively.
int main()
{
    std::string file("weird wek cei cao ni freind reard korose cei");
    //find the characters ei that follow a character other than c
    std::string pattern("[^c]ei");
    
    //we want to whole word in which our pattern appears
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
     std::regex r(pattern);
    for(std::sregex_iterator it(file.begin(),file.end(),r),end_it;it!=end_it;it++)
    {
      std::cout<<it->str()<<std::endl;//matched word
    }

    //same for loop header as before
    for(std::sregex_iterator it(file.begin(),file.end(),r),end_it;end_it!=it;it++)
    {
       auto pos=it->prefix().length();//size of the prefix
       pos=pos>40?pos-40:0;//we want up to 40 characters
       std::cout<<it->prefix().str().substr(pos)//last part of the prefix
        <<"\n\t\t>>> "<<it->str()<<" <<<\n"//matched word
       <<it->suffix().str().substr(0,40)//first part of the suffix
       <<std::endl;
       
    }
}

/*

weird
freind

                >>> weird <<<
 wek cei cao ni freind reard korose cei
 wek cei cao ni 
                >>> freind <<<
 reard korose cei

*/