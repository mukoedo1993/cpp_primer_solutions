#include<iostream>
#include<string>
using std::string;
int main()
{
	string s("Wir Sind Verloren!");
	for (auto& c : s)
		c = toupper(c);
	std::cout << s << std::endl;
	string s1(10, 't');
	s1 = s1 + "Kill all";
	if (!s1.empty())
	{
		std::cout << s1[0] << std::endl;
		std::cout << s1[s1.size() - 1] << std::endl;
	}
}