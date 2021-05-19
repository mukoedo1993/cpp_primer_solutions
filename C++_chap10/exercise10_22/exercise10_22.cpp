#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<functional>//bind; ref; cref
//http://www.cplusplus.com/reference/functional/ref/
//
using std::vector;
using std::string;
using std::endl; using std::cout;

using std::placeholders::_1;
using std::placeholders::_2;//!!!!!!!

bool isLarger(const string& s, const int& i)
{
	if (s.size() > i)return true;
	else return false;
}

int main()
{

	std::ifstream input("ex10_22i.txt");
	std::ofstream output("ex10_22o.txt");
	if (!input.is_open())return-1;
	string str; vector<string>vstr;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		string str1;
		while (Ob1 >> str1)
		{
			vstr.push_back(str1);
		}
	}
	int i1 = 8;
	output<<"The number of words whose size are larger then 8:\n "<<count_if(vstr.begin(), vstr.end(), bind(isLarger, _1, i1));
	input.close(); output.close();
	//correct!
}