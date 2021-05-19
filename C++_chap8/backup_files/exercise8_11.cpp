/*
*1: The istringstream type reads a string.
*2: ostringstream writes a string.
*3: stringstream reads and writes a string.
*4: An istringstream is often used when we have
*some work to do on an entire line, and other work
*to do with individual words within a line
*/

/*Update:
*1: Delete the part needed for exercise 8.13.
*2: Add the part for Chap.8.3.2.
*3:This file is modified for my convenience.
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>//getline(istream,...) is included in this one.


using std::string; using std::vector;

bool valid(const string& a)
{

	for (auto it = a.begin(); it < a.end() - 1; it++)
	{
		if (!isdigit(*it))//check if *it is a digit
			return false;
	}
	return true;
}

std::ostringstream& format(const string& s)
{
	std::ostringstream Ob1(s);
	return Ob1;
}

struct PersonInfo {

	string name;
	vector<string>phones;
};

int main()
{
	std::ifstream input("exercise8_11i.txt");
	std::ofstream output("exericse8_11o.txt", std::ofstream::out
		//|std::ofstream::app
	);



	string line, word;

	vector<PersonInfo>people;
	std::istringstream record(line);// On line 60, without put in the while loop, the record is not used correctly.
	while (getline(input, line))
	{

		PersonInfo info;//create an object to hold this record's data


		//#include<sstream>
		 //bind record to the line we just read


		record >> info.name;//read the name
		while (record >> word)//read the phone numbers
			info.phones.push_back(word);//and store them
		people.push_back(info);//append this record to people

	}

	for (const auto& entry : people) {//for each entry in people

		std::ostringstream formatted(std::ostringstream::ate), badNums
		(std::ostringstream::ate);//objects created on each loop

		for (const auto& nums : entry.phones) {//for each member

			if (!valid(nums)) {
				badNums << " " << nums;//string in badNums
			}
			else
				//writes to formatted's string
			{
				formatted << ". Number: ";
				formatted << nums;
			}
		}
		if (badNums.str().empty())
			output << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << "invalid number(s)"
			<< badNums.str() << std::endl;

	}

}