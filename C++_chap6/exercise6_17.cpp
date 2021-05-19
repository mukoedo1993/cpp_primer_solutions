#define _CRT_SECURE_NO_WARNINGS
/*The definition above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::boolalpha;
bool upper_detector(const string& s1)
{// If an uppercase letter is contained, return true.
	//Otherwise, return false.
	string::size_type t = s1.size();
	for (string::size_type i = 0; i < t; i++)
	{
		if (isupper(s1[i]))
			return true;
	}
	return false;
}
void lowerization( string& s2)
{
	string::size_type t = s2.size();
	
	for (int i=0; i<t; i++)
	{
		s2[i]=tolower(s2[i]);
	}
	//return s2;
}
int main()
{
	string k;
	cin >> k;
	cout << std::boolalpha<<endl;
	cout <<"It is " <<upper_detector(k)<<" that the string contains at least one uppercase letter."<<endl;
	lowerization(k);
	cout <<"After we turn all chars to lowercase, the final string is: "<< k << endl;

}