#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<initializer_list>//  new operations!
#include <system_error>   // std::error_code, std::generic_category
// std::error_condition
#include<cstdlib>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
//const cast and overloading
//return a reference to the shorter of two strings
const string& shorterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
string &shorterString(string &s1,string &s2)
{
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}
/*
The former function has non low-level consts, while the latter one has. So, they have two different
parameters. They are two different functions.
*/
string& shorterString1(string& s1, string& s2)
{
	const string& r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int main()
{
	string s1, s2;
	
	cin >> s1;cin>> s2;
	const string s1_1 = s1, s1_2 = s2;
	cout<<shorterString(s1, s2)<<endl;
	cout << shorterString(s1_1, s1_2) << endl;
	cout << shorterString1(s1, s2) << endl;

}