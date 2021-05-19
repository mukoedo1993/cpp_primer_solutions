/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<limits>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	// exercise 4.22:
	int grade;
	cin >> grade;
	string finalgrade = (grade < 60) ? "fail" : (grade<=75)?"low pass":(grade>90)?"high pass":"pass";
	cout << finalgrade << endl;
	string finalgrade1;
	if (grade < 60)
		finalgrade1 = "fail!";
	else if (grade <= 75)
		finalgrade1 = "low pass!";
	else if (grade <= 90)
		finalgrade1 = "pass!";
	else
		finalgrade1 = "high pass!";
	cout << finalgrade1 << endl;
	//exercise 4.23:
	string s = "word";
	string p1 = s + (s[s.size() - 1] == 's' ? " " : "s");
	// The precedence of the conditional operator is lower than arithmetic operator.
	cout << s << endl << p1 << endl;
	return 0;

}