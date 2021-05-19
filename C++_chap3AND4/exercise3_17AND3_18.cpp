#include<iostream>
#include<vector>
#include<string>
using std::cout; using std::cin; using std::vector;
using std::endl; using std::string;
int main()
{
	vector<string> inpt1;
	string tt;
	while (cin >> tt)
	{
		if (tt == "END")break;
		inpt1.push_back(tt);
		
	}
	for(int i=0;i<inpt1.size();i++)
	{
		for (auto& c : inpt1[i])
		{
			c = toupper(c);
		}
		cout << inpt1[i]<<endl;
	}
	//3.18: Modify:
	vector<int> ivec10;
	ivec10.push_back(42);
}