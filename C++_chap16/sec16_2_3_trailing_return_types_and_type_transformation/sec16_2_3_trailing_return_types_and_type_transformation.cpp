#include<vector>
#include<type_traits>
using std::vector;

//Using an explicit template argument to represent a template function's
//return type works well when we want to let the user to determine the return type.


/*
template<typename It>
??? &fcn(It beg,It end)
{
      //process the range
    return *beg;//return a reference to an element from the range
}
*/
//Here, we know that our function will return *beg, and we know that
//we could use decltype(*beg) to obtain the type of that expression. 
//However, beg doesn't exist until wthe parameter list has been seen.
//Because a trailing rteurn appears after the parameter list, it can use
//the function's parameters.


#include"Blob_chap16_2_3.h"
template<typename It>
auto fcn(It beg,It end)->decltype(*beg)
{
    //process the range
    return *beg;
}

//must use typename to use a type member of a template parameter
template<class It>//typename declration within the return is necessary.
auto fcn2(It beg,It end)->typename std::remove_reference<decltype(*beg)>::type
{
       //process the range
       return *beg;//return a copy of an element from the range
}

//To obtain the element type, we can use a library type transformation template.
//These templates are defined in the type_traits header. In geenral the classes
//in type_traits are used for so-called template metaprogramming, a topic rgar us 
//beyond the scope of this Primer. However, the type transformation templates are
//useful in ordinary programming as well. 

//Each template has a public member named type that represents a type
//If it is not possible (or not necessary) to transform the template's parameter, the type member 
//is the template parameter type itself.


int main()
{
    using vit=vector<std::string>::iterator;

    vector<int>vi={1,2,3,4,5};
    Blob<std::string>ca={"hi","bye"};
    auto &i=fcn(vi.begin(),vi.end());//fcn should return int&
    auto &s=fcn(ca.begin<vit>(),ca.end<vit>());//fcn should return string&
    std::cout<<s<<std::endl;
    auto s1=fcn2(ca.begin<vit>(),ca.end<vit>());
    s1="sk";
    std::cout<<s1<<std::endl;
    std::cout<<s<<std::endl;
}


