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
	auto benchmark = s.end() - old.size();
	for (auto it = s.begin(); it < benchmark; it++)
	{
		if (s.substr(pos, old.size()) == old)// keypoint!!!
		{
			s.replace(it,it+old.size(),New);
			//str.replace(begin,end,str)
			
			pos = pos + New.size();
			it = s.begin() + pos - 1;//pointer become invalid once after erase and insert.
			benchmark = s.end() - old.size();//...
		}
		else
			pos++;
	}
	//s = mkft;
}
int main()
{
	std::ifstream input("ex9_44i.txt");
	std::ofstream output("ex9_44o.txt"); string str_;
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
