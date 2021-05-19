//The constructors that take a string or a const char* take additional (optional)
//arguments that let us specify how many chaacters to copy. When we pass a string, we can also
//specify the index of where to start the copy:
#include<string>
#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>
#include<sstream>
using std::vector;
using std::string;
int main()
{

	const char* cp = "Hello World!!!";//null_terminated array
	char noNull[] = { 'H','i' };//NOT null terminated!

	string s1(cp);//copy up to the null in cp;s1=="Hello World!!!"
	string s2(noNull, 2);//copy two characters from no_null; s2=="Hi"
	string s3(noNull);//undefined: noNull not null terminated
	string s4(cp + 6, 5);//copy 5 characters starting at cp[6]; s4="World"
	string s5(s1, 6, 5);//copy 5 characters starting at s1[6]; s5="World"
	string s6(s1, 6);//copy from s1[6] to end of s1; s6="World!!!"
	string s7(s1, 6, 20);//ok, copies only to end of s1; s7=="World!!!"
	try {
		string s8(s1, 16);//throws an out_of_range exception
	}
	catch (const std::out_of_range & oor)
	{
		std::cerr << oor.what() << std::endl;
	}

	//The substr operation
	/* The substr operation returns a string that is a copy of part or
	*all of the original string. We can pass substr an optional starting
	* position and count.
	*/

	string s_("Hello world");
	string s2_ = s_.substr(0, 5);//s2="Hello"
	string s3_ = s_.substr(6);//s3="world"
	string s4_ = s_.substr(6, 11);//s4="world"
	try {
		string s5_ = s_.substr(12);//throws an out_of_range exception
	}
	catch (const std::out_of_range & Ob1)
	{
		std::cerr << Ob1.what() << std::endl;
	}


	//exercise 9.41:
	vector<char>vecc = { 'k','i','t','e','i','s','n' };
	string str;
	str = str.assign(vecc.begin(), vecc.end());
	std::cout << std::endl << str;//kiteisn

	//exercise 9.42:
	std::ifstream input("ex9_42i.txt"); string str_;
	if (input.is_open()) ; //null statement
	else return -1;

	char a;
	vector<char>v_char_42;
	while (getline(input, str_))
	{
		std::istringstream Ob1(str_);
		while (Ob1 >> a)
			v_char_42.push_back(a);
	}
	//To get the string: 
	str_.assign(v_char_42.cbegin(), v_char_42.cend());


	std::ofstream output("ex9_42o.txt");
	for (string::iterator it = str_.begin(); it != str_.end(); it++)
	{
		output << *it;
	}
	output << std::endl << "We have printed the string above.";
}