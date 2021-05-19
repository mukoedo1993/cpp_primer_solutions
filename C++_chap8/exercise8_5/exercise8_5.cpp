#include<iostream>
#include<fstream>//attention!
#include<vector>
using std::ifstream;
using std::ofstream; using std::istream;
using std::ostream; using std::string;
using std::vector;

	string str11 = "";
	istream& read_strings(istream& is)
	{
		is >> str11;
		return is;
	}
	ostream& print_strings(ostream& os)
	{
		os << str11<<std::endl;
		return os;
	}


int main(int argc, char** argv)
{
	string mystrings;
	ifstream input("ex8_5_i.txt");//Notice that my input comes from this file.
	ofstream output("ex8_5_o.txt");
	while (!input.eof())
	{
		 read_strings(input);
		 print_strings(output);
	}
	

	//ofstream output("ex8_4_o.txt");

}
