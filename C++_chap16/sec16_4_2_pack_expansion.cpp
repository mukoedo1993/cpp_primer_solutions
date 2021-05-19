#include<iostream>
#include<sstream>

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


template<typename T>std::string debug_rep(const T&t)
{
    std::cout<<"\n\template<typename T>std::string debug_rep(const T&t)\n";
    std::ostringstream ret;
    ret<<t;//use T's output operator to print a representation of t
    return ret.str();//return a copy of the string to which ret is bound
}

//print pointers as their pointer type, followed by the object to which the pointer 
//points
//NB: this function will not work properly with char*
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

std::string debug_rep(const std::string &s)
{
    return '"'+s+'"';
}

//convert character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char*p)
{
    return debug_rep(std::string(p));
}

/*understanding pack expansions*/
//call debug_rep on each agrument in the call to print

//More complicated patterns are also possible when we expand a function
//parameter pack. For example, we might write a second variadic function
//that calls debug_rep on each of its arguments  and then call print to
//print the resulting stringc.
template<class... Arg>
std::ostream& errorMsg(std::ostream& os,const Arg&... rest)
{
    //print(os,debug_rep(a1),debug_rep(a2),...,debug_rep(an))
    return print(os,debug_rep(rest)...);
    /*
    In contrast, the following pattern would fail to compile:
    print(os,debug_rep(rest...));
    debug_rep is not a variadate template function. We couldn't do thatl
    */
}
struct Code{
int num()
{
    return 4;
}
};



int main()
{
   char item[]="djs"; int fcnName=13.6, *fcnName1=new int(15);
    std::string otherData="dlsakdjs";Code code;
   errorMsg(std::cerr,fcnName1,code.num(),otherData,"other",item);
   
       delete fcnName1;
       fcnName1=nullptr;
}

/*

        emplate<typename T>std::string debug_rep(const T&t)

template<class T>std::string debug_rep(T *p)

        emplate<typename T>std::string debug_rep(const T&t)
 pointer: 0x55555556beb0 154"dlsakdjs""other""djs"

*/