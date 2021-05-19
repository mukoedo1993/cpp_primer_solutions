#include<vector>
#include<string>
using std::vector;
using std::string;
#include<iostream>
#include<fstream>
#include<sstream>
#include<numeric>
#include<algorithm>
#include<functional>
using std::placeholders::_1;
//using std::placeholders::_2;

bool check_size(const int i,const string &s2)
{
	if (i > s2.size())return true;
	else return false;
}

int main()
{
	vector<int>vint = { 1,2,3,4,5,6,13,10,12,14,19,8,17 };
	string str = "yiyiyokoyiyoy";
	auto it=find_if(vint.begin(), vint.end(), bind(check_size, _1, str));
	std::cout <<"Its value is:"<< *it<<std::endl<<"The location is: ";
	std::cout << it - vint.begin() << " step(s) away from the beginning.";
}