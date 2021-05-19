#include<iostream>
#include<regex>
#include<vector>
#include<algorithm>
int main()
{

    std::string seq("weird ceird teird albeit null sjd neighbor loot ferind");
    std::string reg("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::regex r(reg);
    for(std::sregex_iterator it(seq.begin(),seq.end(),r),end_it;it!=end_it;it++)
    {
       std::cout<<it->str()<<std::endl;
    }
    //exercise 17_18:
    std::vector<std::string>correct_word_set={"albeit","neighbor","weird"};
    std::cout<<"exercise 17_17 above, 17_18 below:\n";
    for(std::sregex_iterator it(seq.begin(),seq.end(),r),end_it;it!=end_it;it++)
    {
        std::string str1=it->str();
        if(!std::binary_search(correct_word_set.begin(),correct_word_set.end(),str1))
        std::cout<<it->str()<<std::endl;
    }
}

/*

weird
teird
albeit
neighbor
exercise 17_17 above, 17_18 below:
teird

*/