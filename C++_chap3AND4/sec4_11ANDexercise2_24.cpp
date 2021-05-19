/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<limits>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	/*
	First,integral promotions happen first.
	Second, when the signedness differs and the type of the unsigned operand
	is the same as or larger than that of the signed operand, the signed operand is converted  to unsigned.
	*/
	bool flag = true; char cval = 'c';
	short sval = 11; unsigned short usval = 123;
	int ival = 456; unsigned int uival = 123;
	long lval = 12123; unsigned long ulval = 122394;
	float fval = 1.234; double dval = 1.2332;

	3.14159L + 'a';//a promoted to int, then  that int converted to long double.
	dval + ival;//ival converted to dval(First case)
	dval + fval;//...
	ival = dval;//dval converted (by truncation) to int.
	flag = dval;//if dval==0 flag=false. Otherwise, flag= true.
	cval + fval;//cval promoted to int, then that int converted to float
	sval + cval;//sval and cval promoted to int.
	cval + ival;//cval converted to long
	ival + ulval;//ival converted to unsigned long
	usval + ival;//promotion depends on the size of unsigned short and int
	uival + lval;//conversion depends on the size of unsigned int and long
	/*
	Array to pointer conversions: In most expressions, when we use an array, the array is...
	automatically converted to the first element in that array:
	*/
	int ia[10];
	int* ip = ia;//convert to a pointer to the first element
	/*
	Conversions to bool: there is an automatic conversion from arithmetic or pointer types to bool.
	*/
	char tt1[] = "ajhshsdh";
	char* cp = tt1;
	if (!cp)cout << "It deosn't point to NULL ";
	if (!(*cp))cout << "It PER SE isn't a NULLPTR";
	int i;
	const int& j = i;//convert a nonconst to a reference to const int
	const int* p = &i;//convert address of a nonconst to the address of a const
	//int& r = j, * q = p;//error: conversion from const to nonconst not allowed
	string i1;
	while (cin >> i1)// If the last read succeeded, then the conversion yields true.
	{
		if (i1 == "END")break;           //If the last attempt failed, then the conversion to bool yields false.
		cout << i1 << endl;
	}
	//cast-name<type>(expression)
	//cast used to force floating-point division
	/*case a: static_cast*/
	double slope = static_cast<double>(j) / i;
	double d_1 = 20.4;
	void* p_1 = &d_1;//ok: address pf any nonconst object can be stored in a void*
	//ok, convert void* back to rge original pointer type
	double* dp = static_cast<double*>(p_1);
	cout << *dp << endl;
	const char* pc_1=&cval;
	/*case b: const_cast*/
	//char* p_1 = static_cast<char*>(pc_1);//error: static_cast cannot change low-level constness.
	char* pc_2 = const_cast<char*>(pc_1);//OK: only const_cast can change low-level constness.
	/*case c:reinterpret_cast*/
	int ip_1114 = 209;
	int* ip_114 = &ip_1114;
	char* pc = reinterpret_cast<char*>(ip_114);
	cout << int(*pc) << endl;
	string tsr(pc);
	cout << tsr << endl;
	int i_yaju = 42;
	void* p_yaju = &i_yaju;
	long* lp_yaju = static_cast<long*>(p_yaju);
	//long* lp_yaju1 = &p_yaju;error: a long pointer could not even points to a void*!!!!
	long* p_yaju_1 = reinterpret_cast<long*>(i_yaju);
	int* ip_yayaju = &ival;
	char* pc_yaju = (char*)ip_yayaju;//ip_yayaju is a pointer to int
	/* The 85th line's code has exactly the same effect as a reinterpret_cast*/

}