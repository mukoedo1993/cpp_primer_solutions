#include<fstream>
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using std::vector;
using std::list;
using std::string;

int main()
{
	std::ofstream output("ex10_28o.txt");

	vector<int>vint = { 1,2,3,4,5,6,7,8,9 };
	list<int>vint1 = { 13,127,89 };
	auto vint2 = vint1, vint3 = vint1,vint4=vint1;

	output << "vint=={ 1,2,3,4,5,6,7,8,9 } \n";

	copy(vint.begin(), vint.end(), front_inserter(vint1));
	output << " original vint1 is{13,127,89};\n vint1:front_inserter\n";
	for (auto it : vint1)
	{
		output << it << " ";
	}
	output << std::endl;


	copy(vint.begin(), vint.end(), back_inserter(vint2));
	output << "vint2:back_inserter\n";
	for (auto it : vint2)
	{
		output << it << " ";
	}
	output << std::endl;


	copy(vint.begin(), vint.end(), inserter(vint3,vint3.begin()));
	output << "vint3:inserter at begin()\n";
	for (auto it : vint3)
	{
		output << it << " ";
	}
	output << std::endl;

	copy(vint.begin(), vint.end(), inserter(vint4, vint4.end()));
	output << "vint4:inserter at end()\n";
	for (auto it : vint4)
	{
		output << it << " ";
	}
	output << std::endl;
}