#include<iostream>
#include<string>
using std::string;
void func(string &s,const string&suffix,const string &prefix)
{
	auto it = s.begin();
	s.append(suffix);
	s.insert(s.begin(),prefix.cbegin(),prefix.cend());
	//equivalent to s.insert(0,prefix);
}

void func1(string& s, const string& suffix, const string& prefix)
{
	auto it = s.begin();
	s.append(suffix);
	s.insert(0, prefix,0,prefix.size() );
	//equivalent to s.insert(0,prefix);
	//str.insert(pos, str1,pos1,leng);
	//str1, pos1 and size1 are:  string that inserts, up to leng chars 
	//from the character array starting at pos1.
}

int main()
{
	string name = "Tom", name1 = name;
	string prefix = "Mr.", suffix = "III";
	//exercise 9.45:
	func(name, suffix, prefix);
	std::cout << name << std::endl;
	//exercise 9.46:
	func1(name1, suffix, prefix);
	std::cout << name1 << std::endl;
		
}