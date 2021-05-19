//first version: can compare any two types:
#include<cstring>
#include<iostream>
#include<functional>
template<typename T>int compare(const T& lhs,const T& rhs)
{
    std::cout<<"template<typename T>int compare(const T& lhs,const T& rhs)\n";
    if(lhs<rhs)return 1;
    if(lhs>rhs)return -1;
    return 0;
}

template<size_t N,size_t M>
int compare(const char(&LHS)[N],const char(&RHS)[M])
{
    std::cout<<"template<size_t N,size_t M>int compare(const char(&LHS)[N],const char(&RHS)[M])\n";
    return strcmp(LHS,RHS);
}

//special version of compare to handle pointers to character arrays
template<>
int compare(const char* const &p1,const char* const &p2)
{
    return strcmp(p1,p2);
}
//The hard part in understanding this specialization is the function parameter types.
//When we define a specialization, the function parameter types must match the correspnding
//types in a previously declared template. Here we are specializing:

//template<class T>int compare(const T&,const T&);
//Here, the type we need to use in our specialization is const char* const & which
//is a reference to a const ptr to const char.





int main()
{
    const char*p1="hi",*p2="mom";
    //However, the version of compare that has nontype template parameters will be called
//only when we pass a string literal or an array. If we call compare with character
//pointers, the first version of the template will be called:
    std::cout<<compare(p1,p2);//calls the first template
    compare("hi","mom");//calls the template with nontype parameters
    /*Defining a function template specialization*/
    //When we specialize a function template, we must supply arguments for every template
    //parameter in the original template. To indicate that we are specializing a template,
    //we use the keyword template followeded by an empty pair of angle brackets(<>).
    
}

//Result:
//-5template<size_t N,size_t M>int compare(const char(&LHS)[N],const char(&RHS)[M])