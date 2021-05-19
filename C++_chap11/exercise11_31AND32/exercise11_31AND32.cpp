#include<map>
using std::multimap;
#include<iostream>
using std::string;
#include<set>
using std::set;
#include<fstream>
#include<sstream>
#include<iterator>
#include<utility>
using std::pair;
int main()
{
	multimap<string, string>works;
	std::ifstream input("ex11_31i1.txt");
	std::ifstream input1("ex11_31i2.txt");
	if (!input.is_open())exit(-1); if (!input1.is_open())exit(-1);
	std::ofstream output("ex11_31o.txt"),output1("ex11_32o.txt");
	string str; unsigned int cnt = 1;
	string search_Item;
	string str1;
	while (getline(input, str))
	{
		if (cnt % 2)
		{str1 = str;cnt++;//author
		}
		else
		{
			string str2; set<string>Set_str;
			std::istringstream Ob1(str);
			while (Ob1 >> str2)
			{
				works.insert(make_pair(str1, str2));
			}
			str1.clear(); str2.clear();
			cnt++;
		}
	}
	str.clear(); unsigned int cnt1 = 1;

	string str_, str1_;
	input.close();


	while (getline(input1, str))
	{
		std::cout << str << std::endl;
		if (cnt1 % 2)
		{
			str_ = str;
			output << "The author is: " << str_ << ". "<<std::endl;
			cnt1++;
		}
		else
		{
			pair<string, string>pair1 = make_pair(str_, str);
			auto ret = works.find(pair1.first);
			if (ret == works.end())
				output << "We cannot find " << pair1.first <<" "<<pair1.second<< std::endl;
			else
			{
				int flag = 1;
				for (auto it1=works.begin();it1!=works.end();it1++)
				{
					if (it1->first == pair1.first && it1->second == pair1.second)
					{
						works.erase(it1);
						output << "We can find the pair and erase it: " << pair1.first << " " << pair1.second << std::endl;
						flag = 0;
						break;
					}
					 
				}if(flag==1)
				output << "We can find the first but not the second of " << pair1.first << " " << pair1.second << std::endl;
			}
			cnt1++;
		}
	}
	//exercise11_32:
	set<string>works_name;
	output1 << "Print out all works left:\n";
	unsigned int flag = 1;
	string author_name;
	for (auto it_1 : works)
	{
		if (flag == 1)
		{
			author_name = it_1.first;
			output1 << "\n\nThe author is: " << it_1.first;
			output1 << ". And, his(her) works are:\n";
			works_name.insert(it_1.second);
			flag = 2;
		}
		else
		{
			if (it_1.first == author_name)
			{
				works_name.insert(it_1.second);
				
			}
			else
			{
				//print out all works_name:
				for (auto it_yaju : works_name)
				{
					output1 << it_yaju<<" ";
				}
				output1 << "\n";
				works_name.clear();
				author_name = it_1.first;
				output1 << "\n\nThe author is: " << it_1.first;
				output1 << ". And, his(her) works are:\n";
				works_name.insert(it_1.second);
				
			}
		}
	}	
	//Print out the last part:
	for (auto it_yaju : works_name)
	{
		output1 << it_yaju << " ";
	}
}