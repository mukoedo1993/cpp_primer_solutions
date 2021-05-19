#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<deque>
using std::deque;
using std::stack;
using std::string; using std::vector;

int main()
{
	stack<string>stc_str;
	std::ifstream input("ex9_52i.txt");
	if (!input.is_open())
		return -1;
	std::ofstream output1("ex9_52o1.txt");
	std::ofstream output2("ex9_52o2.txt");
	string open_para("(");
	string close_para("]");
	string str;
	while (getline(input, str))
	{
		string str1;
		std::istringstream Ob1(str);
		while (Ob1 >> str1)
		{
			auto pos1 = str1.find_first_of(open_para);
			if (str1.find_first_of(open_para) != string::npos)
			{
				string mkft = str1;
				//pos1 = pos1 + 1;
				string str2 = str1.substr(pos1);
				if (str2.find_first_of(close_para) != string::npos)
				{
					auto pos2 = str2.find_first_of(close_para);
					//replace&seen:
					string str_visi = str1.substr(pos1 + 1, pos2-1 );
					str1.replace(pos1+1, pos2, ")");
					output1 << "We have seen:"<<str_visi<<
						". The correct one is: " << str1
						<< "The original one is: " << mkft << std::endl;
					stc_str.push("This one is modified.");
				}
				else {
					stc_str.push(str1);
				}
			}
			else
			{
				stc_str.push(str1);
			}
		}
		// print out the stack:
		while (!stc_str.empty())
		{
			output2 << stc_str.top()<<std::endl;
			stc_str.pop();
		}
	}
}