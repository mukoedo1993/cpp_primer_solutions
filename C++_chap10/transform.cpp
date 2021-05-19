//transform:
#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
using std::vector;
using std::string;
using std::endl; using std::cout;
//http://www.cplusplus.com/reference/algorithm/transform/
int main()
{
	vector<int>vsec = { 10,8,-7,4,5 ,-8,2,5,7,-12,-10,-24 };
	vector<int>vsec1 = { -110,8,7,4,5 ,-8,2,5,7,-12,-10,-24 };

	transform(vsec.begin(), vsec.end(), vsec.begin(), [](int i) {return i < 0 ? -i : i; });
	cout << "eg3:\n";
	for (auto it : vsec)
	{
		cout << it << "; ";
	}
	cout << endl;
	transform(vsec1.begin(), vsec1.end(), vsec1.begin(), [](int i)
		->int {if (i < 0)
		return -i;
		else return i; });
	cout << "eg4:\n";

	for (auto it : vsec1)
	{
		cout << it << "; ";
	}

	//Conclusion: transform actually works like an abs function.
}
