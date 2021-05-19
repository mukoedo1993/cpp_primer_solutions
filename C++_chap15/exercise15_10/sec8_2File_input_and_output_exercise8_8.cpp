#include<iostream>
#include<fstream>
#include"sec_8_2.h"
using std::ifstream; using std::ofstream;
using std::string; using std::fstream;



int main(int argc,char **argv)//attention,here!!!
{
	ifstream in("input.txt");//construct an ifstream and open the given file
	ofstream out;//output file stream that is not associated with any file
	string s = "ba87";
	fstream fstrm(s);



	//Using an fstream in place of an iostream&
	
	ifstream input("input.txt");//open the file of sales transactions


	ofstream output("output.txt",ofstream::app);//open the output file

	ofstream output1("output.txt",ofstream::out|ofstream::app);//exercise8_8
	output1.close();
	Sales_data total;//variable to hold the running sum
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << std::endl;
				total = trans;
			}
		}
		print(output, total) << std::endl;



	}
	else
		std::cerr << "No data?!" << std::endl;

	



	//
	
}