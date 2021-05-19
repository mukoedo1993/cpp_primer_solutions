#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	// Note s as a reference to const; the elements aren't copied and can;t be changed
	vector<string> text = { "ttkasdksdsdk", "kasaj","ahjash","s","sdj","","ttl"};
	for (const auto& s : text)//for each element in text
	{
		cout << s;//print the current element
		//blank lines and those that end with a period get a newline
		if (s.empty() || s[s.size() - 1] == '.')
			cout << s<<endl;
		else
			cout << " ";//Otherwise, just separated with a space


	}
	int i = 3, j = 4, k = 2;
	//Oops, this condition compares k to the bool results of i<j
	if (i < j < k)
		cout << "The bool results of i<j is smaller than k." << endl;
	//exercise 4.9:
	const char* cp = "Hello World"
		;
	if (cp && *cp)//If cp is not a nullptr AND cp points to a non-value...
		cout << "hehe!";

}