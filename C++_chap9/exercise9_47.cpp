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
	std::cout << "find first of:\n";
	string target("an2c3d7R4E6");
	string number("0123456789");
	string alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	auto pos = target.find_first_of(number); int index = 0;
	while ((pos = target.find_first_of(number, pos)) != string::npos)
	{
		std::cout << "Times: " << index << " , we find a number at the "
			<<pos<<" position.\n";
			pos = pos + 1;
			index++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "find first not of:\n";
	auto pos1 = target.find_first_of(alpha); int index1 = 0;
		while ((pos1 = target.find_first_of(alpha,pos1)) != string::npos)
		{
			std::cout << "Times: " << index1<< " , we find a alpha at the "
				<< pos1 << " position.\n";
			pos1 = pos1+ 1;
			index1++;
	     }
		std::cout << "\n\nfind first not of:\n";

		auto pos2 = target.find_first_not_of(number); int index2 = 0;
		while ((pos2 = target.find_first_not_of(number, pos2)) != string::npos)
		{
			std::cout << "Times: " << index2 << " , we find a number at the "
				<< pos2 << " position.\n";
			pos2 = pos2 + 1;
			index2++;
		}
		std::cout << std::endl << std::endl;


		auto pos3 = target.find_first_not_of(alpha); int index3= 0;
		while ((pos3 = target.find_first_not_of(alpha, pos3)) != string::npos)
		{
			std::cout << "Times: " << index3 << " , we find a alpha at the "
				<< pos3 << " position.\n";
			pos3= pos3 + 1;
			index3++;
		}
}