#include<iostream>
#include<fstream>//attention!
#include<vector>
using std::ifstream;
using std::ofstream; using std::istream;
using std::ostream; using std::string;
using std::vector;
vector<string> read_strings(istream&is,vector<string>v_str)
{
	string str;
	is >> str;
	v_str.push_back(str);
	return v_str;
}

int main(int argc,char **argv)
{
	vector<string>mystrings = {};
	ifstream input("ex8_4_i.txt");//Notice that my input comes from this file.
	while (!input.eof())
		mystrings=read_strings(input,mystrings);

	//test:
	std::cout << mystrings[3] << std::endl;

	//ofstream output("ex8_4_o.txt");

}