#include<iostream>
#include<utility>//pair type
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using std::string;
using std::pair;
using std::vector;

/*
* A pair holds two data members. Like the containers, pair is
* a template which we generate specific types. We must supply two
# type names when we create a pair
*/

pair<string, int>
process(vector<string>& v)
{
	//process v.
	if (!v.empty())
	{
		return{ v.back(),v.back().size() };
	}
	else
		return pair<string, int>();//explicitly constructed return value
	//Without the kuo4hao4 on the line above, the type name will not be allowed.
}

//An alternative way:
pair<string, int>
process1(vector<string>& v)
{
	//process v.
	if (!v.empty())
	{
		return pair<string,int> (v.back(),v.back().size() );
	}
	else
		return pair<string, int>();//explicitly constructed return value
	//Without the kuo4hao4 on the line above, the type name will not be allowed.
}

//Another alternative way:
pair<string, int>
process2(vector<string>& v)
{
	//process v.
	if (!v.empty())
	{
		return make_pair(v.back(),v.back().size());
	}
	else
		return pair<string, int>();//explicitly constructed return value
	//Without the kuo4hao4 on the line above, the type name will not be allowed.
}


int main()
{
	//e.g.:
	pair<string, string>annon;//holds two strings
	pair<string, size_t>word_count;//holds a string and a size_t
	pair<string, vector<int>>line;//holds string and vector<int>
	pair<string, string>author{ "James","Joyces" };

	//Unlike other library types, the data members of pairs are public.
	//These members are named first and second, respectively.
	//We access these members using the normal member access notation.
	//.first    .second


	//exercise 11_12 AND 13:
	vector<pair<string, int>>ex11_12_vpair;
	auto ex11_13_vpair1= ex11_12_vpair;
	auto ex11_13_vpair2= ex11_12_vpair;

	std::ifstream input("ex11_12AND13i.txt");
	std::ofstream output("ex11_12AND13o.txt");

	if (!input.is_open())exit(-1);
	string str;
	unsigned cnt = 1;
	while (getline(input, str))
	{
		string str1,str2;
		std::istringstream Ob1(str);
		while (Ob1 >> str1)
		{
			if (cnt % 2)
			{
				str2 = str1;
				cnt++;
			}
			else
			{
				int i = stoi(str1);
				ex11_12_vpair.push_back(pair<string, int>(str2, i));
				ex11_13_vpair1.push_back( make_pair(str2, i));
				ex11_13_vpair2.push_back( {str2,i});
				str2.clear();
				cnt++;
			}
		}
	}
	output << "For exercise 11_12:\n";
	for (auto pr : ex11_12_vpair)
	{
		output <<"The string is: "<< pr.first << "; ";
		output << "The interger is: " << pr.second << std::endl << std::endl;
	}
	output << std::endl << std::endl;

	output << "For exercise 11_13: One more method:\n";
	for (auto pr : ex11_13_vpair1)
	{
		output << "The string is: " << pr.first << "; ";
		output << "The interger is: " << pr.second << std::endl << std::endl;
	}

	output << "For exercise 11_13: The last method:\n";
	for (auto pr : ex11_13_vpair2)
	{
		output << "The string is: " << pr.first << "; ";
		output << "The interger is: " << pr.second << std::endl << std::endl;
	}
}

