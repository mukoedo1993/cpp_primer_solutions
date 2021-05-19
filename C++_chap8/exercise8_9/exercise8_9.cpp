#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using std::istream; using std::ostream;
using std::endl; using std::cin;
using std::cout; using std::string;
using std::istringstream; using std::ifstream;
using std::ofstream;

struct Mathd {
	string str;
	double length = 0.;
	double width = 0.;
	Mathd() = default;
};

istream& read(istream& is)
{
	string s;
	is >> s;
	return is;
}

ostream& print(ostream& os,string s)
{
	os << s;
	return os;
}

int main()
{
	ifstream input("exercise8_9i.txt");
	ofstream output("exercise8_9o.txt",ofstream::out|ofstream::app);
	string tst1;
	while (getline(input, tst1))//false reached every time at the end of each line
	{
		Mathd Ob1;
		istringstream record(tst1);//change tst1, a string, by whitespace, to a stream of several strings.
		record >> Ob1.str >> Ob1.length >> Ob1. width;
		output << "Name is:\n";
		print(output, Ob1.str);
		output << "\nLength is:\n";
		auto length1 = std::to_string(Ob1.length);
		print(output, length1);
		output << "\nWidth is:\n";
		auto width1= std::to_string(Ob1.width);
		print(output, width1);
		output << endl<<endl<<endl;
        //output<< "Name is: "<<Ob1.str <<".\nLength is: "<< Ob1.length 
			//<<".\nWidth is: "<< Ob1.width;
	}
}