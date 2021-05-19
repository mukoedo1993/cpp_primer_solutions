#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<functional>//bind; ref; cref
//http://www.cplusplus.com/reference/functional/ref/
//
using std::vector;
using std::string;
using std::endl; using std::cout;

using std::placeholders::_1;
using std::placeholders::_2;//!!!!!!!

std::ostream& print1(std::ostream& os, const string& s, char c)
{
	return os << s << c;
}



bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

bool check_size(int k,const string&a)
{
	if (a.size() > k)return true;
	else return false;
}

std::ostream& print(const vector<string>& words, std::ostream& os)
{
	for (auto it = words.begin(); it < words.end(); it++)
	{
		os << *it << "; ";
	}
	os << endl;
	return os;
}


int main()
{
	std::ostream& os = cout;
	//bind:
	/*The general form of a call to bind is:
	* auto newCallable=bind(callable,arg_list);
	*where callable is itself a callable object and arg_list is a comma-separated
	* list of arguments that correspond to the parameters of the given callable.
	*/
	//That is, when we call newCallable, newCallable calls callable, passing the
	//arguments in arg_list.

	//name form:
	/*
	*The arguemnts in arg_list may include names of the form _n, where n is an integer.
	*
	*/
	
	//using placeholders Names
	//using namespace std::placeholders;
	//e.g.: using std::placeholders::_1;
	vector<string>words = { "i","hate","maths","coupdetat","vladivostokistki","run" };
	int sz = 4;
	auto wc = find_if(words.begin(), words.end(), bind(check_size,sz,_1));
	cout << *wc << endl;

	//Using to bind Reorder Parameters:
	auto words1 = words, words2 = words;
	sort(words1.begin(), words1.end(), isShorter);
	print(words1, cout);
	cout << endl << endl;
	sort(words2.begin(), words2.end(), bind(isShorter, _2, _1));
	print(words2, cout);

	/* Binding reference parameters:
	*Because bind COPIES its arguments and we cannot copy an ostream. If we want to pass an 
	*object to bind without copying it, we must use the library ref function:
	*/
	for_each(words.begin(), words.end(), bind(print1, ref(os), _1, ' '));

	/*The ref function returns an object that contains the given reference and that is itself 
	copyable. 
	*2:There is also a cref function that generates a class that holds a reference to
	*const. 
	*3:Like bind, the ref and cref functions are defined in the functional header.
	*
	*/
	//All results are corect!!!
}