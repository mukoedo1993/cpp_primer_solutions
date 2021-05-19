#include<iostream>
#include<string>
using std::string;
//If we want to change the value of the characters in a string, we must define the loop variable as
//a reference type.
int main()
{
	string s = "s saves you!";
	for (char& c : s)
	{
		c = toupper(c);
	}
	for (char& c : s)
	{
		if (c == tolower(c))
			c = '&';
	}
	std::cout << s << std::endl;
	string s2("Ka haha!");
	s2[1] = 'b';
	std::cout << s2 << std::endl;
}