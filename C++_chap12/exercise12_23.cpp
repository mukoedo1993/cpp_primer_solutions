//We need to suppress the warning by adding the line 2 code.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory>
using std::string;
int main()
{
	//Part 1:
	char* concatenate_string = new char[strlen("Coup ") + strlen("de'tat") + 1]();//C style string
	//char* ptr = new char[](2);
	
	strcat(concatenate_string, "Coup ");
	strcat(concatenate_string, "de'tat");
	
	std::cout << "Part 1: " << concatenate_string;
	std::cout<< std::endl;

	if (concatenate_string[11] == '\0')
		std::cout << "The last char in concatenate_string is null_char!"<<std::endl;//It prints out!
	delete[] concatenate_string;
	concatenate_string = nullptr;
	//Part 2:
	string str="Coup ",str1="de'tat";
	std::cout << "Part 2:" << (str + str1) << std::endl;
	

}