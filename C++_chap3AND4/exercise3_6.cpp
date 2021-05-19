#include<iostream>
#include<string>
using std::string;
//If we want to change the value of the characters in a string, we must define the loop variable as
//a reference type.
int main()
{
	string s = "s saves you!";
	for (auto &c : s)
	{
		c = toupper(c);
	}
	for (auto &c : s)
	{
		if (c == tolower(c))
			c = '&';
	}
	std::cout << s << std::endl;
	string s2("Ka haha!");
	 s2[1] = 'b';
	 std::cout << s2 << std::endl;
}