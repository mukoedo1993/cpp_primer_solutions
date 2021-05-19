#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<fstream>
using std::string;
int main()
{
	std::ifstream input("ex12_24i.txt");
	std::ofstream output("ex12_24o.txt");
	if (!input.is_open())exit(-1);
	string str;
	unsigned gvn;
	getline(input, str);
	auto k = str.find_first_of("123456789");
	auto k1 = str.substr(k).find_first_not_of("1234567890");
	if (k == string::npos)exit(-1);
	if (k1 != string::npos)
		 gvn = stoi(str.substr(k));
	else
		  gvn = stoi(str.substr(k, k1 - k));
	const unsigned gvn_it = gvn;
	while (getline(input, str))
	{
		
		if (str.size() >= gvn_it)
		{
			char* C_arr = new char[(str).size() + 1];
			strcpy(C_arr, str.c_str());
			
			output << "Larger than given size: " << gvn_it << " ";
			output << C_arr << std::endl;
			delete[] C_arr;
			
		}
		else
		{
			char* C_arr = new char[gvn_it];
			strcpy(C_arr, str.c_str());
			
			output << C_arr << std::endl;
			delete[] C_arr;
		}
		
	}
}