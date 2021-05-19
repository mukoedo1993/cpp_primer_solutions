#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::boolalpha; using std::endl;
string::size_type sumLength(const string& a1, const string&a2)
{
	string::size_type z;
	z = a1.size() + a2.size();
	return z;
}
string::size_type largerLength(const string&a1, const string&a2)
{
	if (a1.size() <= a2.size())
		return a2.size();
	else
		return a1.size();
}
//depending on the value of its string parameter
//getFcn returns a pointer to sumLength or to largerLength
int main()
{
	decltype(sumLength)* getFcn(const string&);

}