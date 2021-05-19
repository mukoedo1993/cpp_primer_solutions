#include<iostream>
#include<vector>
using std::vector;
#include "Screen_ver2.h"
int main()
{
	Screen myScreen(5, 3,'H');
	const Screen star(5, 3,'*');
	myScreen.set('%').set(2,4,'^').display(std::cout);
	star.display(std::cout).some_member();
	std::cout << std::endl;
	//exercise 7.27:

	Screen myScreen1(5, 5, 'X');
	myScreen1.move(4, 0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen1.display(std::cout);
	std::cout << "\n";

	//exercise 7.28:

	Screen myScreen2(5, 5, 'X');
	myScreen2.move1(4, 0).set1('#').display1(std::cout);
	// Because, move1, set1 and display1 all return by values, so 
	//no changes of parameters will be reserved outside the funtion.
	std::cout << "\n";
	myScreen2.display1(std::cout);
	std::cout << "\n";
	// My experiment: 
	vector<Screen>k1 = { Screen(2,3,'I') };
	k1.begin()->move(1, 1).set('t');
	k1.begin()->print();
}