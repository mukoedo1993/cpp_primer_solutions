#include<iostream>
#include<string>
using std::string;
//If we want to change the value of the characters in a string, we must define the loop variable as
//a reference type.
// It is for exercise 3.8.
int main()
{
	string s = "s saves you!"; int i0 = 0, i1 = 0;
	while (s.size()>i0)
	{
		s[i0] = toupper(s[i0]);
		++i0;
	}
	while (s.size()>i1)
	{
		if (s[i1] == tolower(s[i1]))
			s[i1] = '&';
		++i1;
	}
	std::cout << s << std::endl;
	string s2("Ka haha!");
	s2[1] = 'b';
	std::cout << s2 << std::endl;
	// exercise:3_9
	/*string s11;
	std::cout << s11[1] << std::endl;*/
	
}