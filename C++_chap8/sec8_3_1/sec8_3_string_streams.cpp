/*
*1: The istringstream type reads a string.
*2: ostringstream writes a string.
*3: stringstream reads and writes a string.
*4: An istringstream is often used when we have
*some work to do on an entire line, and other work
*to do with individual words within a line
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>//getline(istream,...) is included in this one.


using std::string; using std::vector;

struct PersonInfo {
	
	string name;
	vector<string>phones;
};

int main()
{
	std::ifstream input("sec8_3i.txt");
	std::ofstream output("sec8_3o.txt",std::ofstream::out|std::ofstream::app);



	string line, word;//will hold a line and word from input,respectively

	vector<PersonInfo>people;//will hold the records from the input

	//read the input a line at a time unitil cin hits the end-of-file (or another error)

	while (getline(input, line)) 
    {

		PersonInfo info;//create an object to hold this record's data


		std::istringstream record(line);//#include<sstream>
		 //bind record to the line we just read
		

		record >> info.name;//read the name
		while (record >> word)//read the phone numbers
			info.phones.push_back(word);//and store them
		people.push_back(info);//append this record to people

	}
	int ppl_size = people.size();
	for (int i=0;i<ppl_size;i++)
	{
		output << "name is: "<<people[i].name<<". First phone No. is: " ;
		for (auto it = people[i].phones[0].begin(); it < people[i].phones[0].end(); it++)
		{
			output <<*it;
		}
		output << std::endl;
	}

}