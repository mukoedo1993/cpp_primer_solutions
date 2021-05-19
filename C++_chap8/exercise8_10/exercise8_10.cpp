#include<iostream>
#include<fstream>//attention!
#include<sstream>
#include<vector>
#include<string>

//http://www.cplusplus.com/reference/sstream/ostringstream/ostringstream/


using std::ifstream;
using std::ofstream; using std::istream;
using std::ostream; using std::string;
using std::vector;

int main(
	//int argc, char** argv
)
{
	string line; string elmnt;
	vector<string>mystrings;


	ifstream input("ex8_10_i.txt");//Notice that my input comes from this file.
	ofstream output("ex8_10_o.txt");
	while (getline(input, line))
	{
		std::istringstream record(line);
		string word;
		while (record >> word)
		{
			mystrings.push_back(word);
		}
	}

	
	size_t size1 = mystrings.size();
	for (auto it = mystrings.begin(); it < mystrings.end() - 1; it++)
	{
		std::ostringstream record(std::ostringstream::ate);//// out|ate
		record.str(*it);
		record << "\n";
		output << record.str() ;
	}
}


