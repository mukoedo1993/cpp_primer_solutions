#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<map>
#include<string>
#include<sstream>
using std::vector;
using std::map;
using std::string;
int main()
{
	std::ifstream input("ex11_8i1.txt"),input1("ex11_8i2.txt");
	if (!input.is_open())return -1; if (!input1.is_open())return -1;
	std::ofstream output("ex11_8o.txt");
	


	std::istream_iterator<string>in_it(input1),eof;
	vector<string>exclude;

	while (in_it != eof)
	{
		exclude.push_back(*in_it);
		in_it++;
	}
	input1.close();
	std::ostream_iterator<string>out_it(output,"; ");
	
	map<string, size_t>names;
	string str;
		while (getline(input, str))
		{
			std::istringstream Ob1(str);
			string str1;
			while (Ob1 >> str1)
			{
				int cnt = 0;
				
				for (auto it = exclude.begin(); it < exclude.end(); it++)
				{
					if (*it == str1)cnt = 1;
				}
				if(cnt==0)
					names[str1]++;
			}
			
		}
		input.close();
		for (auto it : names)
		{
			output << "The name: " << it.first << " appears " << it.second <<((it.second>1)?" times.":" time.")
				<<std::endl;
		}
		output.close();
}