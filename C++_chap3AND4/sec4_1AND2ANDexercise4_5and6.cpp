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
	int i=0;
	cout<<i<<" "<<++i<<endl;//undefined
	*/
	int i = 3.4;
	i == 3 ? cout << "haha; " : cout << "nima; ";//ternary oper
	bool b = true;
	bool b2 = -b;//b2 is true!
	cout << std::boolalpha;
	cout << b2 << endl;
	int t1 = -30 * 3 + 21 / 5;
	int t2 = -30 + 3 * 21 / 5;
	int t3 = 30 / 3 * 21 % 5;
	int t4 = -30 / 3 * 21 % 4;
	//Assume m and n are both positive integers.
	//(-m)/n equals (m)/(-n)equals-1*(m/n)
	//% holds rules almost same as /.
	//exercise4.5:
	cout << t1 << endl << t2 << endl << t3 << endl << t4 << endl;
	//exercise4.6:
	int t5;
	while (cin >> t5)
	{
		t5 % 2 == 0 ? cout << "An even number! " : cout << "An odd number!";
		if (t5 == 666)break;
	}
}