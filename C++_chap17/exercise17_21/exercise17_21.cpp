#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>//getline(istream,...) is included in this one.
#include<regex>

using std::string; using std::vector;


bool valid(const std::smatch& sm)
{
    
    if(sm[2].str()!="0731")
    throw std::invalid_argument("Not a nationwide acceptable Changsha phone number within P.R. China!");
    if(sm[1].matched) 
    return ((sm[3].matched)
    &&(0==sm[5].matched));
  
    else
        return
        !sm[3].matched
        &&(sm[5].matched);
       

   
}

std::ostringstream& format(const string&s)
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
 std::string str("(\\()?(\\d{4})(\\))?(\\d{4})([-.])?(\\d{4})");
    std::regex r(str);

	std::ifstream input("ex17_21i.txt");
	std::ofstream output("ex17_21o.txt",std::ofstream::out
		//|std::ofstream::app
	);



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
	
	for (const auto& entry : people) {//for each entry in people

		std::ostringstream formatted(std::ostringstream::ate), badNums
		(std::ostringstream::ate);//objects created on each loop

		for (const auto& nums : entry.phones) 
        {//for each member
			for(std::sregex_iterator it(nums.begin(),nums.end(),r),it_end;it!=it_end;it++){
			if (!valid(*it)) {
				badNums << " " << nums;//string in badNums
			}
			else
				//writes to formatted's string
			{
				formatted << ". Number: ";
				formatted<<nums;
			}
		}
		if (badNums.str().empty())
			output << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << "invalid number(s)"
			<< badNums.str() << std::endl;
        }
	}
input.close();
output.close();
}