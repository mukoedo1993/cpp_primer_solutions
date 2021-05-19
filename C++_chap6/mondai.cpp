#include<iostream>
#include<string>
using std::cout;
using std::string;
//compares length of two strings
bool lengthCompare(const string&, const string&)
{
	return false;
}



	 //third parameter is a function type and is automatically treated as a pointer 
	 //to a function.


//equivalent definition of useBigger_1 and useBigger_2 using type alias
//void useBigger(const string&, const string&, Func);
//void useBigger_1(const string&, const string&, Funcp2);

//needed for update
void useBigger(const string& s1, const string& s2,
	bool pf(const string&, const string&))
{

}
//equivalent dec;aration: explicilty define the parameter as a pointer to function
void useBigger_1(const string& s1, const string& s2,
	bool(*pf)(const string&, const string&))
{

}


	// pf points to a function returning bool that 
//takes two const string reference.
	bool (*pf)(const string&, const string&);//unitialized
	/*
When we use the name of a function as a value, the function is automatically converted to
a pointer. For example, we can assign the address of lengthCompare to pf as follows:
*/
	//Extra Note: On the left side, it becomes a pointer. On the right sidem it becomes
	// an address, whether & is given.


	pf = lengthCompare;//pf now points to the function named lengthCompare
	pf = &lengthCompare;//equivalent assignment: address-of operator is optional
	/*
	Moreover, we can use a pointer to a function to call the function to which 
	the pointer points. We can do directly-- there is no need to dereference the 
	pointer:
	*/
	bool b1 = pf("hello", "Goodbye!");//calls lengthCompare
	bool b2 = (*pf)("hello", "Goodbye!");//equivalent call
	bool b3 = lengthCompare("hello", "Goodbye");//equivalent call
	/*
	There is no conversion between pointers t one function type and pointers 
	However, as usual, we can assign nullptr on a zero-valued constant expression to a function pointer
	to indicate that the pointer does
	*/
	string::size_type sumLength(const string&, const string&);
	bool cstringCompare(const char*, const char*);
	pf = 0;// ok: pf points to no function
	//pf = sumLength;//error: return type differs
	//pf=cstringCompare;//error: parameter types differ.
	 pf = lengthCompare;//ok: function and pointer types match exactly
	 /*
	 As usual, when we use an overloaded function, the context must make
	 it clear which version is being used. When we declare a pointer to
	 an overloaded function.
	 */
	 void ff(int*);
	 void ff(unsigned int);
	 void(*pf1)(unsigned int) = ff;//pf1 points to ff (unsigned int)
	 //void(*pf2)(int)=ff;//error: no ff with a matching parameter list
	 //double(*pf3)(int*)=ff;//error: return type of ff and pf3 don't match
	 string s1 = "jasdh", s2 = "sjdh";

	 //automatically converts the function lengthCompare to a pointer to function
	 useBigger(s1, s2, lengthCompare);


	 //CASE A:
	 //Func and Func2 have function type
	 typedef bool Func(const string&, const string&);
	 //typedef decltype (lengthCompare)Func2;//equivalent type
	 //CASE B:
	 // FuncP and FuncP2 have pointer to function type
	 typedef bool(*Funcp)(const string&, const string&);
	 //typedef decltype(lengthCompare)* Funcp2;//equivalent type

	 //return a pointer to function
	 /*
	 As with arrays, we can't return a function type but can return 
	 a pointer to a function type. Similarly, we must write the return
	 type as a pointer type; the compiler will not automatically treat 
	 a function return type as a corresponding pointer type. Also as with arrat 
	 returns, by far the easiest way to declare a function that returns a 
	 pointer to function is by using a type alias.
	 */
	 using F = int(int*, int);//F is a function type.
	 using PF = int(*)(int*, int);//PF is a pointer type.
	 /*
	 Here we used type alias declarations to define F as a function type
	 and PF as a pointer to function type. The things to keep in mind is
	 that, unlike what happens to parameters that have function type, the return
	 type is not automatically converted to a pointer type. We must explicitly
	 specify that the return type is a pointer type.
	 */
	 PF f1(int);//ok:
	 //F f1(int);//error: F is a function type; f1 cannot return a function.
	 F* f1(int);//ok: explicitly specify that the return type is a pointer to function.
	 /*

	 */
int main()
{

}
