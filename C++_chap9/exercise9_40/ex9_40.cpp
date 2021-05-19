#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
using std::cout; using std::vector; using std::endl;
//Q: explain what the following program fragment does:
using std::string;
int main()
{
	std::ifstream input("ex9_40i.txt");
	std::ofstream output("ex9_40o.txt",std::ofstream::out | std::ofstream::app);
	string str,seed="SEED"; int wrd;
	getline(input, str);
	std::istringstream Ob1(str);
	if (!str.empty())
		if (Ob1 >> wrd)output<<"Number entered successfully!\n";
		else
			return -1;

	vector<string>svec(wrd,seed);
	output << "The number of size is:" <<wrd<<"."<< std::endl;
	output << "The capacity is:" << svec.capacity() << "The size is: " << svec.size() << std::endl;
	svec.reserve(1024);
	output << "After reserve(1024), the capacity is: " << svec.capacity() << ". The size is: " 
		<< svec.size() << std::endl<<std::endl<<std::endl;
	input.close();
	output.close();
	

}