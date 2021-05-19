#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
using std::cout; using std::vector; using std::endl;
//Q: explain what the following program fragment does:
using std::string;
int main()
{
	std::ifstream input("ex9_39i.txt");
	std::ofstream output("ex9_39o.txt");
	if (!input.is_open())
		return -1;
	vector<string>svec;
	svec.reserve(1024);
	string word;
	string str;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);

		while (Ob1 >> word)
		{
			svec.push_back(word);
			output << "Now size is:"<<svec.size()<<". And capacity is: "<<svec.capacity()<<endl<<"One more test:";
		}
	}
	svec.resize(svec.size() + svec.size() / 2);
	output << "After resize: Now size is:" << svec.size() << ". And capacity is: " << svec.capacity() << endl;
	
		
}