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
	int grade;
	cin >> grade;
	string finalgrade = (grade < 60) ? "fail" : "pass";
	cout << finalgrade << endl;
	string finalgrade1 = (grade > 90) ? "high pass" : (grade < 60) ? "fail!" : "pass!";
	cout << finalgrade1 << endl;
	/*
	The conditional operator has fairly low precedence. When we embed a conditional expression in a larger expression,
	we usually
	must parenthesize the conditional subexpression. For example, we often use the conditional operator to print one 
	or another value,
	depending on the result of a condition. An incompletely parenthesized conditional operator in an output expression  
	can have surprisng
	results.
	*/
	// Case 1:
	cout << ((grade < 60) ? "1:fail!" : "1:pass!") << endl;//rpints 1:fail or 1:pass
	//Case 2:(below)
	cout << (grade < 60) ? "2:fail!" : "2:pass!";//prints 1 or 0!
	cout << endl;
	//Notice that case 2 is equivalent to:
	cout << (grade < 60);//prints 1 or 0
	cout ? "fail" : "pass";// test cout and then yield one of the two literals depending on ...
	//whether cout is true or false
	//Case 3_1:(error)
	/*
	cout<<grade<60?"fail":"pass";
	//Case 3_2(==Case3_1)
	cout<<grade;// less-than has lower precedence than shift, so print grade first.
	cout<<60?"fail":"pass";//then compare cout to 60!
	*/
	

}