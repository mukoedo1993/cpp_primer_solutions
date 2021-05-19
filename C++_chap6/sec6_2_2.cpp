#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Sales_item.h"

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;
//Recall that operations on a reference are actually operations on  
//the object to which the reference refers.
//Reference parameters exploit this behavior. They are often used to allow
// a function to change the value of one or more of its arguments.
void reset(int& i);
bool isShorter(const string& s1, const string& s2);
string::size_type find_char(const string& s, char c, string::size_type& occurs);
int main()
{
	int n = 0, i = 42;
	int& r = n;//r is bound to n(i.e. r is another name for n)
	r = 42;// n is now 42
	r = i;// n now has the same value as i
	i = r;//i has the same value as n

	int j = 42;
	reset(j);//j is passed by reference; the value in j is changed.
	cout << "j= " << j << endl;//prints j=0
	string s = "Detat_cocp";
	string s1 = "Russland";
	string s2 = "Deutschland!";
	string::size_type ctr;
	cout << std::boolalpha;
	cout<<isShorter(s1, s2)<<endl;
	auto index= find_char(s, 'O',ctr);
	cout << s << endl << ctr << endl;
}
void reset(int& i)//i is just another name for the object passed to reset
{
	i = 0;//changes the value of the object to which i refers
}
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() > s2.size();
}
//Using reference parameters to return additional information
//returns the index of the first occurrence of c in s
//the reference parameter occurs how often c occurs
string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	auto ret = s.size();//position of the first occurence, if any
	occurs = 0;//set the occurence count parameter
	for (decltype(ret)i = 0; i != s.size(); ++i)
	{
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;//remember the first occurrence of c
			++occurs;//increment the occurrence count
		}

	}
	return ret;
}

/*
Conclusion: using references to avoid copies:
It can be inefficient to copy objects of large class types or large containers.
*/