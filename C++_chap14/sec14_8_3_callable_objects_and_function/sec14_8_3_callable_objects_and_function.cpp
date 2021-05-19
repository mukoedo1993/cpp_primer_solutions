//C++ has several kinds of callable objects: functions and pointers to functions,
// lambdas, objects created by bind, and classes that overloaded the function-call operator.

//Like any other object, a callable object has a type.
//e.g.1: each lambda has its own unique unnamed class type.
//e.g.2: function and function-pointer types vary by their return type and argument types,
//and so on.
//However, two callable objects with different types may share the same call signature.
//call signature->specifies the type returned by a call to the object and the argument type(s)
//that must be passed in the call.
//e.g.1: int(int,int)
#include<map>
#include<iostream>
#include<functional>//The library function type
#include"Sales_data1.h"
using std::map;using std::string;using std::function;
//Different types can have the same call signature
//ordinary function
int add(int i,int j){return i+j;}
Sales_data add1(const Sales_data&,const Sales_data&);
//lambda, which generated an unnamed function-object calss
auto mod=[](int i,int j){return i%j;};

//functio-object class
struct divide{
int operator()(int denominator,int divisor){return denominator/divisor;}
};

int add1(int i,int j){return i+j;}
int main()
{

//We could define a function table->to store "pointers to these callables"

//maps an operator to a pointer to a function taking two ints and returning an int
map<string,int(*)(int,int)>binops;

const string pls="+";
//We could put a pointer to ad into binops as follows:
binops.insert({"+",add});
//However, we can;t store mode or an object of type divide in binops
binops.insert({"%",mod});//error: mode is not a pointer to the function
//But, actually it works well in VS code.
std::cout<<binops["%"](14,3)<<std::endl;//2

//library function type:
function<int(int,int)>f1=add;//function pointer
function<int(int,int)>f2=divide();//object of a function-object class
function<int(int,int)>f3=[](int i,int j){return i*j;};//lambda

std::cout<<f1(4,2)<<std::endl;//6
std::cout<<f2(4,2)<<std::endl;//2
std::cout<<f3(4,2)<<std::endl;//8


//table of callable objects corresponding to each binary operator
//all the callables must take two ints and return an int
//an element can be a function pointer, function object or lambda
map<string,function<int(int,int)>>binops1=
{{"+",add},//function pointer
{"-",std::minus<int>()},//library function object
{"/",divide()},//user defined function object
{"*",[](int i,int j){return i*j;} },//unnamed lambda
{"%",mod}//named lambda object
};

std::cout<<binops1["+"](10,5)<<std::endl;//15
std::cout<<binops1["-"](10,5)<<std::endl;//5
std::cout<<binops1["*"](10,5)<<std::endl;//50
std::cout<<binops1["/"](10,5)<<std::endl;//2
std::cout<<binops1["%"](10,5)<<std::endl;//0

//We cannot store the name of an overloaded function in an object of type function

map<string, function<int(int,int)>>binops2;
//binops2.insert({"+",add1});//error

//One way to resolve the ambiguity is to store a function pointer instead of 
//the name of the function:
int(*fp)(int,int)=add;
binops1.insert({"+1",fp});
binops1.insert({"+2",[](int a,int b){return add(a,b);}});

std::cout<<binops1["+1"](8,3)<<std::endl;//11
std::cout<<binops1["+2"](8,3)<<std::endl;//11
}
