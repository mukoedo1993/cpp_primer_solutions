#define _CRT_SECURE_NO_WARNINGS
/*The definition above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::boolalpha;
int exercise6_21(int a, int* b)
{
	if (a < *b)
		return *b;
	else return a;
}
void exercise6_22(int** c, int** d)
{
	int* e = *c;
	*c = *d;
	*d = e;
}

int main()
{
	int a = 10, a1 = 11, a2 = 12;
	int* b = &a;
	int* b1 = &a1;
	int* b2 =&a2;
	cout << "exercise 6.21: "<<exercise6_21(a, b) << endl<<"exercise 6.22:\n";
	cout << "Before: b1= " << *b1 << "; " << "b2= " << *b2 << "; " << endl;
	exercise6_22(&b1, &b2);
	cout << "After: b1= " << *b1 << "; " << "b2= " << *b2 << "; " << endl;

}