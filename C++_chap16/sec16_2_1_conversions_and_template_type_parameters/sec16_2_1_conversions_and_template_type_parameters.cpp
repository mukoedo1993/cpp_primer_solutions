/*
As with a nontemplate function, the arguments we pass in a call to a function
template are used to initialize that function's parameters.
*/

//As usual, top-level consts that is a reference(or pointer)to a const can be passed 
//a reference (or pointer) to a const can be passed a reference (or pointer) to
//a nonconst object.

//Built--in Array or function-to-pointer conversions:
//If the function parameter is not a reference type, then the normal pointer conversion.
//will be applied to arguments of array or function type. An array argument will be converted
//to a pointer to its first element. Similary, a function argument will be converted
//to a pointer to the function's type.
#include<iostream>
#include<iterator>
#include<algorithm>
#include<fstream>
using std::string;
template<typename T>T fobj(T a,T b)
{
    return a;
}
template<typename T>T fref(const T& a1,const T& b)//arguments are referenced
{
    T a2;
    return a2;
}
template<typename T>T fobj(T,T);//arguments are copied

template<typename T>int compare(const T&v1,const T&v2)
{
    if(v1<v2)return -1;
    if(v1>v2)return 1;
    return 0;
}

template<class A,class B>int flexiblecompare(const A&v1,const B&v2)
{
    if(v1>v2)return -1;
    if(v1<v2)return 1;
    return 0;
}

template<class T>std::ostream &print(std::ostream&os,const T&obj)
{
    return os<<obj;
}

int main()
{
      string s1("a value");
      const string s2("another value");
      std::cout<<fobj(s1,s2);//calls fobj(string,string);const is ignored
      std::cout<<fref(s1,s2);//calls fref(const T&,const T&);
      //uses permissable conversion to const on s1

      int a[10],b[42];
      fobj(a,b);//calls fobj(int*,int*)
      //fref(a,b);//error: array types doesn't match
      //When the parameter is a reference, the arrays are not converted to pointers,
      //The types of a and b don't match, so the call is in error.
        

        /*Function parameter that use the same template parameter type*/
        long lng;
        //compare(lng,1024);//error: no matching function for call to comare(long int&,int)
        //This call is in error because the arguments to compare don't have the same type,
        //the template argument deduced from the first argument is long; the one for the second
        //is int. These types don't match, so template argument deduction fails.
        
        //If we want to allow normal conversions on the arguments, we can define the 
        //function with two type parameters:
        
         long lng1;
         flexiblecompare(lng1,1024);//ok: calls flexible Compare(long,int)
       
       /*Normal conversions apply for ordinary arguments*/
       //A function template can have parameters that are defined using ordinary types--
       //that is, type that do not involve a template type parameter. Such arguments have 
       //no special processing; they are converted as usual to the corresponding type of the
       //parameter. For example, consider the following template:
     int ob_mkft1=14;
     print(std::cout,ob_mkft1);//14
     
     std::ostream_iterator<int> it(std::cout,"h");
     int i_mkft[10]={1,2,3,4,5,6,7,8,9,-10};
     copy(std::begin(i_mkft),std::end(i_mkft),it);

     std::ofstream f("output");
     print(f,10);
}
