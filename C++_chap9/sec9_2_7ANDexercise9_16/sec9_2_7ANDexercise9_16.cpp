#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<list>
#include<array>
#include<iostream>
using std::vector; using std::list;
using std::array; using std::string;
/*1:Every container type supports the euqality operators(==and !=);
*2:all the containers except the unordered associative containers also support 
*the relational operators.(>,<,<,<=)
*3: The right- and left- operand must have the same type.
*/
int main()
{
	std::string str1, str2;
	std::ifstream input("ex9_16i.txt");
	std::ofstream output("ex9_16o.txt");
	//To check the existence of essential files: 
	if (!input.is_open())
	{
		std::cerr << "error! The output file is also initialized!" << std::endl;
	return 0;
	}

	if (!output.is_open())
		std::cerr << "error!" << std::endl;
	//1: input the vector<int>:
	/*
	output << "Please input the vector:\n";
	getline(std::cin, str1);
	std::istringstream Ob1(str1);
	int k; vector<int>vec_i;
	while (Ob1 >> k)
		vec_i.push_back(k);
		*/
		//2: input the list<int>:
	string str = "exercise 9-16:output:";
	string str_toku1, str_toku2; 
	output << str << std::endl;
	getline(input, str1); int k1; vector<int>vint;
	std::istringstream Ob1(str1);
	Ob1 >> str_toku1;
	while (Ob1 >> k1)
		vint.push_back(k1);

	getline(input, str2); int k2; list<int>lint;
	std::istringstream Ob2(str2);
	Ob2 >> str_toku2;
	while (Ob2 >> k2)
		lint.push_back(k2);

	output << "We compare: " << str_toku1 << " and " << str_toku2 
		<<" . \nTip:Update your data on the input file, then you can restart a experiment!"<< std::endl;

	if (vint.size() == lint.size())
	{
		auto it1 = vint.begin();
		auto it2 = lint.begin();
		if (*it1 < *it2)
		{
			output << "Vector < list!\n" << std::endl;
			return 0;
		}
		if (*it1 > * it2)
		{
			output << "Vector > list!\n" << std::endl;
			return 0;
		}
		while (*it1 == *it2)
		{
			it1++; it2++;
			if (it1 == vint.end())
			{
				output << "Vector = list!\n" << std::endl;
				return 0;
			}
			if (*it1 < *it2)
			{
				output << "Vector < list!\n" << std::endl;
				return 0;
			}
			if (*it1 > * it2)
			{
				output << "Vector > list!\n" << std::endl;
				return 0;
			}
			
			

		}
		return 0;
	}
	else
	{
		auto it1 = vint.begin();
		auto it2 = lint.begin();
		if (*it1 < *it2)
		{
			output << "Vector < list!\n" << std::endl;
			return 0;
		}
		if (*it1 > * it2)
		{
			output << "Vector > list!\n" << std::endl;
			return 0;
		}
		while (*it1 == *it2)
		{
			it1++; it2++;
			if (it1 == vint.end())
			{
				output << "vector<list!\n" << std::endl;
				return 0;
			}
			if (it2 == lint.end())
			{
				output << "vector>list!\n" << std::endl;
				return 0;
			}

			if (*it1 < *it2)
			{
				output << "Vector < list!\n" << std::endl;
				return 0;
			}
			if (*it1 > * it2)
			{
				output << "Vector > list!\n" << std::endl;
				return 0;
			}

		}
		return 0;
	}

}