#include<iostream>
#include<string>
using std::cout;
using std::string;
int main()
{
	//Page 363:
	/*1:s.insert(pos,arg)
	*Insert characters specified by args before pos. pos can be an index
	*or an iterator. Versions takking an index return a reference to s;
	those taking an iterator return an iterator denoting the first inserted
	character.
	*/

	/*2: s.erase(pos,len)
	*Remove len characters starting at positon pos. If len is omitted,
	*removes characters from pos to the end of the s. Returns a reference
	*to s.
	*/
	string s("hello World");

	//Part A:
	s.insert(s.size(), 5, '!');//insert five exclamation points at the end of s
	s.erase(s.size() - 5, 5);//erase the last five chars from s

	//Part B:
	/*
	s.assign(args) //Replace characters in s according to args. Retuen a refere ce to s.
	*/
	const char* cp = "Stately, plump Buck";
	s.assign(cp,7);//equivalent to s.assign(&cp[0],7). It replaces itself with [0,7)indices of cp.
	//s=="Stately"

	s.insert(s.size(), cp + 7);//s=="Stately, plump Buck".
	//null_terminated array pointed to by cp(&cp[0])to the end of the string...
	//(null-terminated). str1.insert(index,cp)


	//Part C:
	string s_a = "some string", s_b = "some other string";
	s_a.insert(0,s_b);//insert a 

	//The append and replace functions
	string s_("C++ Primer"), s2_ = s_;//initialize s_ and s2_ to "C++ Primer"
	s_.insert(s_.size(), " 4th Ed.");//s_=="C++ Primer 4th Ed."
	s2_.append(" 4th Ed.");//equivalent appends "4th Ed." to s2_; s_==s2_

	//equivalent way to replace "4th" by "5th"
	s_.erase(11, 3);
	std::cout << s_ << std::endl;

	/* s.erase(pos,len)
	*Remove len characters starting at position pos. If len is omitted, removes
	* characters from pos to the end of the s. Return a reference to s.
	*/
	s_.insert(11, "5th");//s=="C++ Primer 5th Ed."
	std::cout << s_ << std::endl;



}