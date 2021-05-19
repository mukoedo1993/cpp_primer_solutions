#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	/*
	The left-hand operand of an assignment operator must be a modifiable lvalue. For exmaple, given
	*/
	int i = 0, j = 0, k = 0;//initializations, not assignment
	const int ci = i;//initialization, not assignment
	/*
	Each of these assignments is illegal:
	1024=k;//error: literals are lvalues
	i+j=k;//error:arithmetic expressions are rvalues
	ci=k;//error:
	/*
	Assignment is right associative
	*/
	int ival, jval;
	ival = jval = 0;//ok: each assigned 0
	int ival1, * pval;
	string s1, s2;
	s1 = s2 = "OK";//string literal "OK" converted to string
	int i_1, i1;
	double d, d1;
	d = i_1 = 3.5; i1 = d1 = 3.5;
	cout << d << ";" << i_1 << "<-part a" << endl;
	cout << d1 << ";" << i1 << "<-part b" << endl;

		
}