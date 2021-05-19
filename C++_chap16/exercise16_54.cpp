#include<iostream>
template<class T>std::ostream& print(std::ostream& os,const T&t1)
{
    os<<t1;
    return os;
}

template<class T,class... Args>
std::ostream& print(std::ostream& os,const T&t,const Args&... args)
{
    os<<t;
   
     std::cout<<" At this time we have: "<<sizeof...(args)<<
     "No. of args and: "<<sizeof...(Args)<<" No. OF Args.\n";
       return print(os,args...);
}

struct B{
    
};

int main()
{
   // B b;
     //print(std::cout,b);
     //no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘const B’)
     //no type named ‘type’ in ‘struct std::enable_if<false, std::basic_ostream<char>&>’
     print(std::cout,114,514,'c');
}

/*
114 At this time we have: 2No. of args and: 2 No. OF Args.
514 At this time we have: 1No. of args and: 1 No. OF Args.
c
*/