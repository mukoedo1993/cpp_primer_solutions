#include<iostream>
#include<string>
using std::cout;
void f()
{
	cout << "void f()funtion!\n";
}
void f(int)
{
	cout << "void f(int)function!\n";
}
void f(int,int)
{
	cout << "void f(int,int)function!\n";
}
void f(double,double=3.14)
{
	cout << "void f(double,double=3.14)function!\n";
}
/*Part: exercise 6.53_c
int calc(char*, char*)

{return 2; }
int calc(char* const, char* const)
{return 3; }*/
int main()
{
	int a = 4, b = 13;
	double c = 3.5849;
	f(); f(a);
	//f(2.56, 42);//error(more than instances fit:(...)
	f(a, b);
	f(c);
	char k1 = '!', k2 = '2', k3 = 'e';
	char* k1_1 = &k1;
	char* const k2_1 = &k2;
	//Part: exercise 6.53_c
	//cout<<std::endl<<calc(k1_1,k1_1)<<std::endl;
	//cout<<calc(k2_1, k2_1);
}