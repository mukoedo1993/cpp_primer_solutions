#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::boolalpha; using std::endl;

bool lengthCompare(const string&, const string&)
{
	return false;
}


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

int main()
{
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
	//typedef decltype(lengthCompare)* Funcp2;//equivalent 

	//equivalent definition of useBigger_1 and useBigger_2 using type alias
   void useBigger(const string&, const string&, Func);
   void useBigger_1(const string&, const string&, Funcp);

}