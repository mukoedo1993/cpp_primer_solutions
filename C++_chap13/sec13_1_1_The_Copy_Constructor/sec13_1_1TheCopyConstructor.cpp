#include<iostream>
#include<string>
#include<vector>
#include"Sales_data_chap13_ver1.h"
using std::string;
using std::vector;
//A constructor is the copy constructor if its first parameter is a reference to the class type and
	//any additional parameters have default values.
class Foo {
public:
	Foo();//default constructor
	Foo(const Foo&);//copy constructor
};

void f(vector<int>)
{}//f's parameter is copy initialized


/*The synthesized Copy Constructor*/
//When we do not define a constructor for a class, the compiler synthesizes one for us. 
//Unlike the synthesized default default constructor, a copy constructor is synthesized even if we define other constructors.

//The synthesized copy constructor for some classes prevents us from copying objects of that class type.
//Otherwise, the synthesized copy constructor memberwise copies the members of its argument into the object being created.
//The compiler copies each nonstatic member in turn from the given object into the one being created.

//Members of class type: copied by the copy constructor for that class
//Members of built-in type: copied directly
//Although we cannot directly copy an array, the synthesized copy constructor for our Sales_data class is equivalent to:

//See the class Sales_data in Sales_data_chap13_ver1.h



int main()
{
	string dots(10, '.');//direct initialization
	string s(dots);//direct initialization
	string s2 = dots;//copy initialization
	string null_book = "9-999-99999-9";//copy initialization
	string nlines = string(100, '9');//copy initialization

	//When we use direct initialization, we are asking the compiler to use ordinary function matching to 
	//select the constructor that best matches the argument we provide


	//Copy initialization:
	//1:=
	//2: pass an object as an argument to a parameter of nonreference type
	//3: return an object from a function that has a nonreference return type
	//4:aggregate class

	//!!!!!!!!!!!!!
	/*Parameters and return types*/
	//The fact that the copy consructor is used to initialize nonreference parameters of class type explains 
	//why the copy's constructor's own parameter must be a reference.

	/*Consrtaints on copy initialization*/
	
	//The vector constructor that takes a single size parameter is explicit.
	vector<int>v1(10);//ok: dierect initializatopm
	//vector<int>v2 = 10;//error: constrictor that takes a size is explicit
	
	//f(10);//error: cannot use an explicit constructor to copy an argument
	f(vector<int>(10));

	/*The compiler can bypass the copy constructor*/
	//During copy initialization, the compiler is permitted (but not obligated) to skip the copy/move constructor and
	//create the object directly.
	string null_book1="9-999";//copy initialization
	string null_book2("9 - 999");//compilers omits the copy constructor
}