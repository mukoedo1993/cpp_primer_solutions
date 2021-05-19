#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
//https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_43.cpp
using std::string;
using std::cout;
using std::endl;
void func(string& s, const string& old, const string& New)
{
	int pos = 0; //string mkft = s; 
	int flag = 0;  
	//auto benchmark = s.size() - old.size();
	
	for (int pos=0;pos<s.size();pos++)
	{
		if (old[0] == s[pos] && s.substr(pos, old.size()) == old)
			//str.substr(index,length):
		{
			s.replace(pos, old.size(), New);
			//str.replace(index,length,str)

			pos = pos + New.size()-1;

			std::cout << "s:" << s << std::endl;
		}
		else;
		
	}
	//s = mkft;
}
int main()
{
	std::ifstream input("ex9_44i_ver2.txt");
	std::ofstream output("ex9_44o_ver2.txt"); string str_;
	int i = 0;
	while (getline(input, str_))
	{
		string s, old, New;
		std::istringstream Ob1(str_);
		Ob1 >> s >> old >> New;
		output << "Case " << i << ": The old line is: " << s << std::endl;
		output << "The old string is:" << old << ". The new string is:" << New << std::endl;
		func(s, old, New); i++;
		output << "Our new string is: " << s << std::endl << std::endl;
	}
	string s = "thrukkthrue_moon", Old = "thru", New = "through";

	func(s, Old, New);
	cout << s << endl;
}