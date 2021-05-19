//A using declaration lets us use a name from a namespace without...
// A using declaration has the form:
//using namespace::name;
#include<iostream>
//using declaraion; when we use the name cin, we get the one from...
// the namespace std

//PAGE 82:
using std::cin;
using std::endl;// Each using declaration introduces a single...
//namespace member.
int main()
{
	int i;
	cin >> i;//OK: cin is a synonym for std::cin
	//cout<<i;//error: no using declaration; we must use the full name
	std::cout << i<<endl;
	int* p;// A pointer doesn't need to be initialized.
}