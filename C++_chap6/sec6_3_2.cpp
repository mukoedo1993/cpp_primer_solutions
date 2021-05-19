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

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
/*
Every return in a function with a return type other than void must return a value.

*/
//return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string& word, const string& ending)
{
	return(ctr > 1) ? word + ending : word;
}
/*
As with any other reference, when a function returns a reference, that reference is just another name
for the object to which it refers. As an example, consider a function that returns a reference to the 
shorter of its two string parameters.
*/
const string& shortString(const string& s1, const string& s2)
{
	return(s1.size() <= s2.size() ? s1 : s2);
}
//disaster: this function returns a reference to a local object:
/*const string& manip()
{
	string ret;// transform ret in some way
	if (!ret.empty())
		return ret;//WRONG: return a reference to a local object!
    else
	return "Empty"; //WRONG: "EMPTY" is a local temporary string
}*/

//Calls to functions return references are lvalues, other return types yield rvalues.
//Notice that the function below returns a reference. 
char& get_val(string& str, string::size_type ix)
{
	return str[ix];//get_val assumes the given index is valid
}

//List initializing the Return Value
//Under the new standard, functions can return a braced list of values.
vector<string>process()
{
	string expected = "hehehaha!";
	string actual = "666haha!";
	// expected and actual are strings
	if (expected.empty())return{};//return an empty vector
	else if (expected == actual)
		return{ "functionX","Okay!" };
	else
		return{ "functionX",expected,actual };
}

int main()
{
	string t1 = "jhskj";
	string t2 = "HAHA, DAHUFA!";
	cout << shortString(t1, t2)<<endl;
	auto sz = shortString(t1, t2).size();
	cout << sz << endl;

	string s("a value");
	/*
	If a function returns a pointer,reference or class type,
	we can use the result of a call to call a member of the 
	resulting object.
	*/
	cout << s << endl;//print a value

	/*
	For the code below: It might be surprising to see a 
	function call on the left-hand of an assignment. However, nothing
	special is iovolved. The return value is a reference, so the call is
	an lvalue. Like any other lvalue, it may appear as the left-hand operand
	of the assignment operator.
	*/
	get_val(s, 0) = 'A';//changes s[0] to A
	cout << s << endl;//prints a value

	//List initializing the Return Value:
	auto a=process();
	cout << a[0] << endl << a[1] << endl << a[2] << endl;
	return 0;
}