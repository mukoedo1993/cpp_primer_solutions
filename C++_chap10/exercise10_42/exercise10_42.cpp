#include<list>
#include<iostream>
#include<fstream>
#include<iterator>
int main()
{
	std::ifstream input("ex10_42i.txt");
	if (!input.is_open())return -1;
	std::ofstream output("ex10_42o.txt");
	std::istream_iterator<std::string> inpt(input), eof;
	
	std::ostream_iterator<std::string> out_it(output, "; ");
	std::list<std::string>lst_str;
	while (inpt != eof)
	{
		lst_str.push_back(*inpt);
		inpt++;
	}

	lst_str.sort();
	lst_str.unique();
	//print out the vector lst_str into the target file:
	copy(lst_str.begin(), lst_str.end(), out_it);
	input.close(); output.close();
}