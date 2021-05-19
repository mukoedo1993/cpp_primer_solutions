#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using std::vector;
using std::string;
int main()
{
	std::ifstream input("ex9_22i.txt");
	std::ofstream output("ex9_22o.txt");
	if (!input.is_open())
	{
		std::cerr << "Error!" << std::endl;
		return 0;
	}
	vector<int>iv; string str; int some_val;
	while (getline(input, str))
	{
		std::istringstream Ob1(str); int i;
		Ob1 >> some_val;//first line's first element from the input file
		while (Ob1 >> i)
		{
			iv.push_back(i);
		}
	}

	

	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2; int flg = 0;
	while (iter != mid)
	{
		
		//mid = iv.begin() + iv.size() / 2;
		if (*iter == some_val)
		{
			iter=iv.insert(iter, 2 * some_val);
			iter++; 
		}
		iter++;
		mid = iv.begin() + iv.size() / 2;
		flg++;
	}
	output << "Times of iteration::" << flg << std::endl << std::endl;
	output << "Current vector:\n ";
	for (auto it1 = iv.begin(); it1 < iv.end(); it1++)
	{

		output << *it1 << "; ";

	}
}