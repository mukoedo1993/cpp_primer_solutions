#include<iostream>
#include<string>
using std::string;
inline bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
int main()
{
	string s1, s2;
	std::cin >> s1;
	std::cin >> s2;
	std::cout << std::boolalpha;
	std::cout << isShorter(s1, s2);
}