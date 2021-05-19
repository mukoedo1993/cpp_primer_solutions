#include<iostream>
#include<sstream>
template<typename T>std::string debug_rep(const T&t)
{
    std::cout<<"\n template<typename T>std::string debug_rep(const T&t)\n";
    std::ostringstream ret;
    ret<<t;//use T's output operator to print a representation of t
    return ret.str();//return a copy of the string to which ret is bound
}
template<class T>std::string debug_rep(T *p)
{
    std::cout<<"\ntemplate<class T>std::string debug_rep(T *p)\n";
    std::ostringstream ret;
    ret<<" pointer: "<<p;//print the pointer's own value:
    if(p)
    ret<<" "<<debug_rep(*p);//print the value to which p points
    else
    {
        ret<<" nullptr ";//or indicate that the p is null
    }
    return ret.str();//return a copy of the string to which ret is bounded
    
}
template<>std::string debug_rep(char *p)
{
    std::cout<<"\ntemplate<>std::string debug_rep(char *p)\n";
       return debug_rep(std::string(p));
}
template<>std::string debug_rep(const char *p)
{
    std::cout<<"\ntemplate<>std::string debug_rep(const char *p)\n";
    return debug_rep(std::string(p));
}

int main()
{
    std::cout<<debug_rep("hi world")<<std::endl;
    std::cout<<debug_rep(const_cast<char*>("hi world"))<<std::endl;
}

/*


template<>std::string debug_rep(const char *p)

 template<typename T>std::string debug_rep(const T&t)
hi world

template<>std::string debug_rep(char *p)

 template<typename T>std::string debug_rep(const T&t)
hi world

*/