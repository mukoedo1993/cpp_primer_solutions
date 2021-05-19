#include<iostream>
#include<string>
int main()
{
	std::string s(10, 'c');
	s = s + "Coup de'tat!";
	//process characters in s until we run out of characters or we hit a white space:
	for (decltype(s.size())index = 0;
		index != s.size() && !isspace(s[index]); ++index)
	{
		s[index] = toupper(s[index]);
	}
	std::cout << s << std::endl;
}