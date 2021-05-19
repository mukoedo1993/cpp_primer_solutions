#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Sales_item.h"

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;
void reset(int* ip);
void reset(int ip);
void swap(int* a, int* b);
int main()
{
	int n = 0, i = 42;
	int* p = &n, * q = &i;// p oints to n;q points to i
	*p = 42;//value n is changed. p is unchanged.
	p = q;//
	reset(i);
	cout << "i= " << i << endl;// output: i=42
	reset(&i);
	cout <<"i= "<< i << endl;//output: i=0
	int a1 = 23, b1 = 67;
	swap(&a1, &b1);
	cout << "a1= " << a1 << endl << "b1= " << b1 << endl;

}
//Passing arguments by values:
void reset(int* ip)
{
	*ip = 0;//change value of the object to which ip points.
	ip = 0;// changes only the local copy of ip; the arguments
}
void reset(int ip)
{
	
	ip = 0;// changes only the local copy of ip; the arguments
}
void swap(int* a, int* b)
{
	int mkft = 0;
	mkft = *a;
	*a = *b;
	*b = mkft;
	cout << *a <<"!!!!"<< *b << endl;
}