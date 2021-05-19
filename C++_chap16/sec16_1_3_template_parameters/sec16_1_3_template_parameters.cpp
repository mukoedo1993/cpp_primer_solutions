//Template parameters
//Like the names of function parameters, a template parameter name has no intrinsic
//meaning. We ordinarily name type parameters T, but we can use any name:
#include<iostream>
#include<array>
#include<functional>
#include<cstring>
#include"sales_data.h"
bool compareIsbn(const Sales_data&ob1,const Sales_data&ob2)
{
   if(ob1.isbn()<ob2.isbn())return false;
    if(ob1.isbn()>ob2.isbn())return true;
    return false;
}
using std::array;
template<class Foo>Foo calc(const Foo&a,const Foo&b)
{
    Foo tmp=a;//tmp has the same type as the parameters and return type
    return tmp;//return type and parameters have the same type
}

/*template parameters and scope*/
//Template parameters follow normal scoping rules.
//The name of a template parameter can be used after it has ben declared 
//and until the end of teh template declaration or definition. As with any other name,
//a template parameter hides any declaration of that name in an outer scope.


typedef double A;
template<typename A,typename B>void f(A a,B b)
{
    A tmp=a;
    //double B;//error: redeclares template parameter B
}
/*template declarations*/
//A template declaration must include the template parameters:
//declares but does not define compare and Blob
template<typename T>int compare(const T&,const T&);
template<typename T>class Blob;


//As with function parameters, the names of a template parameter need not be
//the same across the declaration(s) and the definition of the same template:

//all 3 uses of calc refer to the same function template
template<typename T>T calc1(const T&,const T&);
template<typename U>U calc2(const U&,const U&);
//definition of the template
template<class Type>Type calc3(const Type& a,const Type&b){/*...*/}
//Of course, every declaration and the definition of a given template must have
//the same number and kind(i.e.e type and nontype) of parameters.

/*Using class members that are types*/
//Recall that we use the scope operator(::)to access both static members and type
//members. In ordinary code, the compiler had access to the class definition. As 
//a result, it knows whether a name accessed through the scope operator is a type
//or a static member. 
//e.g.: string::size_type: the compiler has the definiton of string and can see that
//size_type is a type.

//Assuming T is a template type parameter, when the compiler sees code such as T::mem
//It won't know until instantiation time whether mem is a type or a static data member
//However, in order to process the template, the compiler must know whether a name
//represents a type. For example, assuming T is the name of a type parameter, when
//the compiler sees a statement of teh following form:

//T::size_type *p;
//It needs to know whether we're defining a varibale named p or are multiplying
//a static data member name size_type by a variable named p.

//By default, the language assumes that a name accessed through the scope operator is 
//not a type.

//As a result, if we want to use a type member of a template type parameter, we must 
//explicitly tell the compiler that the name is a type. We do so by using the keyword
//typename:
template<typename T>
typename T::value_type top(const T&c)noexcept
{
    if(!c.empty())
    return c.back();
    else
    {
        std::cerr<<"empty!\n";
        return typename T::value_type();
    }
    
}

/*default template arguments*/
//Just as we can supply default arguments to function parameters, we can also supply
//default template 


template<typename T,typename F=std::less<T>>
int compare_sakebi(const T&v1,const T&v2,F f=F())
{
    if(f(v1,v2))return -1;
    if(f(v2,v1))return 1;
    return 0;
}


/*template default arguments and class */
template <class T=int>class Numbers{
    public:
    Numbers(T v=0):val(v){}
    //various operations on number
    const T& print_out(){return val;}
    private:
    T val;
};
int main(){
std::cout<<"//";

array<int,10>arr={1,2,3,4,5,6,7,8,9,10};
array<int,0>arr1;
std::cout<<top(arr)<<std::endl;
std::cout<<top(arr1)<<std::endl;
std::greater<int>grtr;
std::cout<<compare_sakebi(12,-18)<<std::endl;//1
std::cout<<compare_sakebi(-13.,15.6)<<std::endl;//-1

//It uses the thrid parameter to deduct the F, and use first two parameters to
//deduct the type of T.
std::cout<<compare_sakebi(13,-15,grtr)<<std::endl;//-1
Sales_data item1,item2;
std::cin>>item1;
std::cin>>item2;
std::cout<<compare_sakebi(item1,item2,compareIsbn)<<std::endl;//1
//For the code above, we pass compareIsbn
const char s[]="ddt";
const char c_str2[]="ddk";

//Actually, the function below could just determine the equality, if!=,return -1,otherwise, 0.
std::cout<<compare_sakebi(const_cast<char*>(s),const_cast<char*>(c_str2),std::strcmp);//-1
std::cout<<std::endl;
Numbers<long double>lots_of_precisionss;
Numbers<>average_precision;//empty<>says we want the default type
std::cout<<typeid(lots_of_precisionss.print_out()).name()<<std::endl;//e
std::cout<<typeid(average_precision).name()<<std::endl;//7NumbersIiE
}

/*

//10
empty!
0
1
-1
-1
china 3 4
jap 4 5
1
-1
e
7NumbersIiE

*/