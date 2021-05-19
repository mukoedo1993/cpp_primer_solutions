/*
*Excepting array, all of the library containers provide flexible memory management.
* We can add or remove elements dynamically changing the size of the container at run ime.
*/

//Attention!
/*
*1:Adding elements anywhere but at the end of a vector or string, or anywhere but the beginning
* or end of a deque, requires elements to be moved.
*2: Moreover, adding elements to a vector or a string may cause the entire object to be reallocated.
* Reallocating an object requires allocating new memory and moving elements from the old space to the 
*new.
*/

//push_back: every sequential container(including the string type),aside from array and forward_list, support
//push_back.
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using std::string; using std::vector;
using std::cin;
void pluralize(size_t cnt, string& word)
{
	if (cnt > 1)
		word.push_back('s');//same as word+='s'
}
int main()
{
	std::ifstream input("sec9_3i.txt");
	std::ofstream output("sec9_3o.txt");
	if (!input.is_open())
	{
		std::cerr << "error!" << std::endl;
		return 0;
	}
	string word, str;
	vector<string>container;
	
	while (getline(input,str))
	{
		std::istringstream Ob1(str);
		while(Ob1>>word)
		container.push_back(word);
		container.push_back("\\\\");
	}
	output << "\\\\ means the end of the line of original file:\n";
	for (auto it = container.begin(); it != container.end(); it++)
	{
		output << *it<<"; " ;
		if(*it=="\\\\")
		{
			output << std::endl;
		}
	}

}