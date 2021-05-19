#include<iostream>
#include<fstream>
#include<string>
#include"Blob_ver4.h"
int main()
{
	std::ifstream input("ex12_20i.txt");
	std::ofstream output("ex12_20o.txt");
	if (!input.is_open())exit(-1);
	std::string str;
	StrBlob libr;
	//part 1: read a file
	while (getline(input,str))
	{
		libr.push_back(str);//
	}

	//part 2: print:
	string empty_str = "";
	try {
		for (StrBlobPtr hakushin(libr);; hakushin = hakushin.incr())
		{

			output << hakushin.deref() << std::endl;

		}
	}
	catch (std::out_of_range& Ob1)
	{
		output << "END OF THIS MISSION!(THIS SENTENCE IS ADDED ON THE ORIGINAL CONTENT.) BY HAKUSHIN";
		exit(0);
	}
	catch (std::runtime_error & Ob2)
	{
		output << "Runtime error!";
		exit(-1);
	}
}