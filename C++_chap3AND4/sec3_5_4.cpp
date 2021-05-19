#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
/*
C-style strings are not a type. Instead, they are
a convention for how to represent and use character strings. Strings that
follow this convention are stored in character arrays and are null terminated.
*/
int main()
{
	char ca[] = { 'C','+','+' };
	cout << strlen(ca) << endl;//disaster: ca isn't full terminated.
	
	string s1 = "A string example", s2 = "A different string";
	if (!(s1 < s2))cout << "Haha!" << endl;//True: s1<s2 doesn't hold.
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	if (!(ca1 < ca2))//undefined: compares two unrelated addresses
		cout << "114514 haha!" << endl;
	if (strcmp(ca1, ca2) > 0)
		cout << "810 Haha!" << endl;
	//initialize largeStr as a concatenation of s1, a space, and s2
	string largeStr = s1 + " " + s2;
	cout << largeStr << endl;
	char long_char[50];
	return 0;
}