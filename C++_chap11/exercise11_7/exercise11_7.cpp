#include<map>
using std::map;
#include<iostream>
#include<fstream>
#include<vector>
using std::vector;
#include<sstream>
#include<string>
#include<iterator>
using std::string;
using std::cin; using std::cout;
using std::endl;
int main()
{
	
	map<string, vector<string>>family;
	std::ifstream input("ex11_7i.txt");
	if (!input.is_open())return -1;
	std::ofstream output("ex11_7o.txt");
	std::ostream_iterator<string> it114(output, "; ");
	string str;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		string str1; vector<string>v_str;
		while (Ob1 >> str)
		{
			
			if (str1 == "")
				str1 = str;
			else
				v_str.push_back(str);
			
		}
		family[str1] = v_str;
		str1.clear(); v_str.clear();
	}
	for (auto a_family : family)
	{
		output <<"Family's parent name is:"<< a_family.first<<endl;
		output << "Family's children's names are:";
		copy(a_family.second.begin(), a_family.second.end(), it114);
		output << endl << endl<<endl;
	}
}