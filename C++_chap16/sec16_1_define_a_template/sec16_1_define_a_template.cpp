#include<iostream>
#include<vector>
#include<cstring>//strcmp
#include<functional>
using std::vector;
using std::less;
#include"sales_data.h"
/*Function Template*/

//Define a Template
//Rather than defining a new function for each type, we can define a function template.

template<typename T>
int compare(const T&v1,const T&v2)
{
    if(v1<v2)return -1;
    if(v1>v2)return 1;
    return 0;
}
//A template definition starts with the keyword template followed by a template parameter
//list, which is a comma-seprated list of one or more template parameters bracketed by
//the less-than and greater-than tokens.


/*Template Type parameters*/
//Our compare function above has one template type parameter. In general, we can use a 
//type parameter as a type specifier in the same way that we use a built-in or class type
//specifier. In particular, a type parameter can be used to name the return type or a 
//function parameter type, and for variable declarations or casts inside the function body.

template<typename T>T foo(T*p)
{
    T tmp=*p;//tmp will have the type to which p points
    return tmp;
}

//Each type parameter must be preceded by the keyword class or typename:
//error: must precede U with either typename or class
//template<typename T,U>calc(const T&,const U&);

//ok: NO DISTICNTION between typename and class in a template parameter list
template<typename T,class U>T calc(const T&,const U&);


/*Nontype template parameters*/
//In addition to defining type parameters, we can define templates that take nontype
//parameters. A nontype parameter represents a value rather than a type.
//When the template is instantiated, nontype parameters are replaced with a value
//supplied by the user or deduced by the compiler. These values must be constant
//expressions, which allows the compiler to instantiate the 
//templates during compile time.

//A nontype parameter may be an integral type, or a pointer or (lvalue) reference to
//an object or to a function type. 
//1: An argument bound to nontype integral parameter must be a constant expression.
//2: Arguments bound to a pointer or reference nontype parameter must have static
//lifetime.
//3: A pointer parameter can also be instantiated by nullptr or a zero-valued constant expression.
//non-dynamic, 
template<unsigned N,unsigned M>
int compare1(const char(&p1)[N],const char(&p2)[M])
{
    return std::strcmp(p1,p2);
}

/*inline and constexpr Function templates*/
//A function template can be declared inline or constexpr in the same ways as nontemplate
//functions. The inline pr const expr specifier follows the template parameter list
//and precedes the return type:
//ok: inline specifier follows the template parameter list
 template<typename T>inline T min(const T&,const T&);
 //error: incorrect placement of the inline specifier
  //inline template<typename T> T min(const T&,const T&);

  //Most types--including the built-in types and, except for unique_ptr and the IO types,
  //all the library types we've used-- do allow copying. However, there can be class types
  //that do not allow copying. By making our parameters references to const, we ensure that
  //such types can be used with our compare function. Moreover, if compare is called with
  //large objects then this design will also make the function run faster.
  //In fact, if we were truly concerned about types indepedence and portability, we probably
  //should have defined our function using the std::less(inclued in the functional header file).

  template<typename T>int compare2_(const T&v1,const T&v2)
  {less<T> OB1;
      if(OB1.operator()(v1,v2))return -1;
      //less<T>()(v1,v2)
      if(less<T>()(v2,v1))return 1;//less<T>()(v2,v1)//Here we use a temporary object to
      //call the call operation of the std::less class.
      return 0;

  }
  //Unlike nontemplate code, headers for templates typically include definitions as well
  //as declrations.

  //It is up to the caller to guarantee that the arguments passed to the template support
  //any operations that template uses, and that those operations behave correctly in the context
  //in which the template uses them.
int main()
{
    std::cout<<compare(1,0)<<std::endl;//T is int
    //The compiler uses the deduced template parameters to instatiate a specific 
    //version of the function for us. 
    std::cout<<compare(1,0)<<std::endl;//1
    vector<int>vec1{1,2,3},vec2{4,5,6};//1
    std::cout<<compare(vec1,vec2)<<std::endl;//-1

    int a=3,*b=&a; int i;
    std::cout<<foo(b)<<std::endl;//3
    std::cout<<compare1("dead","death");//-16//It indicated lhs<rhs
     i=10;
     int i_yaju=static_cast<int>(i);
    std::cout<<compare2_(i_yaju,int(true));//1

    Sales_data data1,data2;
    //std::cout<<compare2_(data1,data2)<<std::endl;//error: no < on Sales_data
}