#include<string>
#include<iostream>
#include<fstream>
//#include<sstream>
#include<vector>
using std::string;
using std::vector;
int count = 0;
/*
* Notice that, we treat the format NUM/NUM/NUM as  MM/DD/YYYY.
*
*/
class date_format {
public:
	date_format(const string &str)
	{
		
		//string dash("/"); 
		string  str1;
		string comma(",");
		string number("0123456789");
		string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
		vector<string>months = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		int flag = 0; int pos = 0;

		//First, for the format like Jan 28,1994:
		if (str == "")exit(-1);
			if (str.find_first_of(alphabet) != string::npos&&
				str.find_first_of(comma) != string::npos)
			{
				for (int i = 0; i < 12; i++)
				{
					if (str.substr(0, 3) == months[i])
					{
						month = i + 1; flag = 1;
						break;

					}
				}
				if (flag == 1)
				{
					auto pos_ = str.find_first_of(number);
					string str_f11 = str.substr(pos_);
					day = stoi(str_f11);

					auto pos_1 = str.find_first_of(comma);
					pos_1++;
					string str_f1 = str.substr(pos_1);
					year = stoi(str_f1);

						flag = 0;
					
				}
			}
			//then, for MM/DD/YYYY
			else
			{
				if (str.find_first_of(number) == string::npos)
					exit(-1);
				else
				{
					month = stoi(str);
					auto i3 = str.find_first_not_of(number);
					i3 = i3 + 1;
					string str2_ = str.substr(i3);
					day = stoi(str2_);
					auto i4 = str2_.find_first_not_of(number);
					i4 = i4 + 1;
					str2_ = str2_.substr(i4);
					year = stoi(str2_);
				}
			}
		
		
	}
	std::ostream& print(std::ostream& os)
	{
		os << "Month is:" << month << ". "
			<< "Year is:" << year << ". "
			<< "Day is:" << day << ". "
			<< std::endl;
		return os;
	}
	int month=13;
	int day=13;
	int year=1000;
};
int main()
{
	std::ifstream input("ex9_51i.txt");
	if (!input.is_open())
	{
		std::cout << "Error! Cannot find a file!";
		return -1;
	}
	std::ofstream output("ex9_51o.txt");
	string str;
	while (getline(input, str))
	{
		::count++;
		output<< "It is " << count << "th(st,nd,rd) of data we enter. "<<std::endl;
		output << "Orignial data is: " << str << std::endl;
		date_format Ob1(str);
		Ob1.print(output);
		output << std::endl;
	}
	input.close(); output.close();
}