/*
*The string search functions return string::size_type, which is
*an unsigned type. As a result, it is a bad idea to use an int, or 
*other signed type, to hold the return from these functions.
*
*/
#include<string>
#include<iostream>
using std::string;

int main()
{
	//The find function deos the simplest search. It looks for its argument and returns
	string name("AnnaBelle");
	auto pos1 = name.find("Anna");//posl==0

	string lowercase("annabelle");
	pos1 = lowercase.find("Anna");//oisk-npos

	string numerbs("0123456789"); name="r2d2";
	//returns 1,i.e., the index of the first dighit in name
	auto pos2 = name.find_first_of(numerbs);

	string dept("03714p3");
	//return 5, which is the index to the character 'p'
	auto pos3 = dept.find_first_not_of(numerbs);
	
	//Specifying where to start the search
	string::size_type pos4 = 0;
	//each iteration finds its next number in name
	while ((pos4 = name.find_first_of(numerbs, pos4)) != string::npos)
	{
		std::cout << "found number at index: " << pos4 << ". element is "
			<< name[pos4] << std::endl;
		++pos4;//move to the next character
	}

	//Searching Backward
	string river("mississippi");
	auto first_pos = river.find("is");//return 1
	auto last_pos = river.rfind("is");//return 4
	std::cout <<std::endl<< "first_pos:" << first_pos << std::endl <<
		"last_pos:" << last_pos << std::endl;
	/*
	*1: find_last_of searches for the last character
	* that matches any element of the search string.
	*2: find_last_not_of searches for the last character that
	*does not match any element of the search string.
	*/


}