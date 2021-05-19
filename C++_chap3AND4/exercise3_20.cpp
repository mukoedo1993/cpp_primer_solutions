#include<iostream>
#include<vector>
#include<string>
using std::cin;
int main()
{
	int t;
	std::vector<int>intvec;
	while (cin >> t)
	{
		if (t == 666)break;
		intvec.push_back(t);
	}
	std::cout << "Part a:" << std::endl;
	for (int i = 0; i < intvec.size(); i++)
	{
		if ((i % 2) != 0 && i != 0)
		{
			std::cout << intvec[i] + intvec[i - 1] << "; " << std::endl;
		}

	}
	std::cout << "Part b:" << std::endl;
	for (int i = 0; i < intvec.size(); i++)
	{
		std::cout << intvec[i] + intvec[intvec.size() - 1 - i] << "; " << std::endl;
	}
}