#include<iostream>
//A variadic template is a template function or class that can take 
//a varying number of parameters. The varying parameters are known a parameter pack.

//2 kinds:
//1: The varying parameters are known as a parameter pack/
//2: A template parameter pack represents zero or more function parameters.


//Args is a template parameter pack; rest is a function parameter pack
//Args represents zero or more template type parameters
//rest represents zero or more function parameters
template<class T,typename ...Args>
void foo(const T&t,const Args& ... rest)
{
   std::cout<<sizeof...(Args)<<std::endl;//number of type parameters
   std::cout<<sizeof...(rest)<<std::endl;//number of function parameters
}
//As usual, the compiler deduces the template parameter types from teh function's
//arguments. For a variadic template, the compiler also deduces the number of parameters
//in the pack. e.g.:
struct B{};

struct A{
    A()=default;
    A(B b){}
};

void fcn(A a,const char*)
{}
void fcn(B b,std::string str)
{}

int main()
{
    int i=0;double d=3.14; std::string s("how now brown now");


  //function parameter pack and template parameter pack.


    foo(i,s,42,d);//three parameters in the both two packs
    //foo(T=const int&,Args=const string&,const int&,const double&): 
    //rest=s,42,d are packed in the function parameter pack.

    foo(s,42,"hi");//two parameters in the the both two packs
    //foo(T=const string&,Args=const int&, const char(&)[3])
    //rest= 42,"hi" are packed in the function 

    foo(d,s);//one parameter in the the both two packs
    //foo(T=const double&,Args=const string&)

    foo("hi");//two empty packs//T=const char(&)[3]
    //foo(T=const char(&)[3]),foo(T=const char(&)[3],Args=empty)
     

    B b;A a;

    //An ambiguous call:
    //fcn(b,"skt");//Either overloaded function will require a different
    //user_defined conversion.
    //const char(&)[3]->std::string, or A::A(B). They 
  
    
}
/*

3
3
2
2
1
1
0
0
*/