#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::boolalpha; using std::endl;
//compares length of two strings
bool lengthCompare(const string&, const string&)
{
	return false;
}

int main()
{
	// pf points to a function returning bool that 
//takes two const string reference.
	bool (*pf)(const string&, const string&);//unitialized
	/*
	When we use the name of a function as a value, the function is automatically converted to
	a pointer. For example, we can assign the address of lengthCompare to pf as follows:
	*/
	bool (*pf1)(const string&, const string&);

	pf = lengthCompare;//pf now points to the function named lengthCompare
	pf1 = &lengthCompare;//equivalent assignment: address-of operator is optional
	/*
	Moreover, we can use a pointer to a function to call the function to which
	the pointer points. We can do directly-- there is no need to dereference the
	pointer:
	*/
	bool b1 = pf("hello", "Goodbye!");//calls lengthCompare
	bool b2 = (*pf1)("hello", "Goodbye!");//equivalent call
	bool b3 = lengthCompare("hello", "Goodbye");//equivalent call
	cout << boolalpha;
	cout << b1 << endl << b2 << endl << b3 << endl;
	string::size_type sumLength(const string&, const string&);
	bool cstringCompare(const char*, const char*);
	pf = 0;// ok: pf points to no function
	//pf = sumLength;//error: return type differs
	//pf=cstringCompare;//error: parameter types differ.
	pf1 = lengthCompare;//ok: function and pointer types match exactly
}
