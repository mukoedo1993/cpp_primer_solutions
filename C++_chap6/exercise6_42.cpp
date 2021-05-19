#include<iostream>
using std::string;
//return the plural version of success or failure if ctr
//is greater than 1
string make_plural(size_t ctr, const string& word, const string& ending,string s="s")
{
	return(ctr > 3) ? word+s :  ending + s;
}
int main()
{
	std::cout<<make_plural(1, "success","failure")<<std::endl;
	std::cout << make_plural(4, "success", "failure","es") << std::endl;

	
}