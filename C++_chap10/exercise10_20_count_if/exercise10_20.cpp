#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
using std::vector;
using std::string;
using std::endl; using std::cout;
//http://www.cplusplus.com/reference/algorithm/count_if/
int main()
{
	vector<int>ex10_20 = { 10,19,-23,24,15,-26,13,15,-26 };
	cout<<count_if(ex10_20.begin(), ex10_20.end(),
		[](const int& a)->bool {if (a > 0)return true; else return false; });
	//The result is 6. correct.
}