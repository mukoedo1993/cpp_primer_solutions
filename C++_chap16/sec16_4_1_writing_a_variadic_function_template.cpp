#include<iostream>
//We'll define a function like our earlier error_msg function, only
//this time we'll allow the argument types to vary as well.


//Variadic functions are often recursive. The first call processes the first
//argument in the pack and calls itself on the remaining arguments. Our print
//function will execute this way-- each call will print its second argument on
//the stream denoted by its first argument. To stop this recursion, we'll also 
//need to define a nonvariadic print function that will take a stream and an object

//function to end the recursion and print the last element
//this function must be declared before the variadic version of print is defined

template<class T>
std::ostream &print(std::ostream &os,const T&t)
{
    return os<<t;//no separator after the last element in the pack
}

template<class T,typename... Args>
std::ostream &print(std::ostream &os,const T& t,const Args&... rest)
{
    print(os,t);
   
    return print(os,rest...);
}
//Caveat 1: Both functions provide an equally good match for the call. However, a
//non-variadic template is more specialized than a variadic template, so the nonvariadic
//version is chosen for this call.

//Caveat 2: A declaration for the nonvariadic version of print must be in scope when
//the variadic version is defined. Otherwise, the variadic function will recurse indefinitely.

//Without the declaration here, it will be an error to call func114 directly.
template<class T>std::ostream& func114(std::ostream&os,const T&t);


template<class T,class... Args>
std::ostream& func114(std::ostream&os,const T&t, const Args&... args)
{
    os<<t<<" ";
    return func114(os,args...);

}

template<class T>std::ostream& func114(std::ostream&os,const T&t)
{
    
    os<<t;
    return os;//I will rewrite only this line of code to make it more easily to understand.
}

int main()
{
    double d=13.4;int s=14;
    print(std::cout,"sk",12,d);
    func114(std::cout,"sk",12,d);
    std::cout<<std::endl<<std::endl;
    //1 element:
    func114(std::cout,17);
    std::cout<<std::endl<<std::endl;
    //2 elements:
    func114(std::cout,19,"jdjs");
    std::cout<<std::endl<<std::endl;
    //5 elements:
    func114(std::cout,18,"sjsdsj",s,std::string("nimsl"));
}

/*
sk1213.4sk 12 13.4

17

19 jdjs

18 sjsdsj 14 nimsl

*/