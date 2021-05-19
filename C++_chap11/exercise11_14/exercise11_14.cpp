#include<map>
#include<utility>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
using std::map;
using std::pair;
using std::vector;
using std::string;
int main()
{
	map<string, vector<pair<string, int>>>genealogy;
	std::ifstream input("ex11_14i.txt"); std::ofstream output("ex11_14o.txt");
	if (!input.is_open())exit(-1);
	string str,str1; unsigned int cnt= 1;

	vector<pair<string, int>>vec_child;
	//e.g.:
	/*
	Johnson
	Tom 19970308 Keck 19890402 Tim 19780229
	*/
	while (getline(input, str))
	{
		
		if (cnt % 2)
		{
			str1 = str;
			cnt++;
		}
		else
		{
			string str2,str3; unsigned int cnt1 = 1;
			int DoB;
			std::istringstream Ob1(str);
			while (Ob1 >> str2)
			{
				
				if (cnt1 % 2)
				{
					str3 = str2;//name
					cnt1++;
				}
				else
				{
					DoB = stoi(str2);
					cnt1++;
					vec_child.push_back({ str2,DoB });
				}

			}
			genealogy[str1] = vec_child;
			cnt++;
		}
	}

	for (auto it_ge : genealogy)
	{
		output << "The family name is: " << it_ge.first << std::endl;
		for (auto it_child : it_ge.second)
		{
			output << "The name of child is: " << it_child.first<<". ";
			output << "And, the DoB of child is: " << it_child.second << ". ";
		}
		output << "\n\n\n";
	}
}