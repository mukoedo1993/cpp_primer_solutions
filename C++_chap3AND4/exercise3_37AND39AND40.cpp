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
{/*Part exercise 3.37*/
	constexpr int k = 20;
	const char ca[] = { 'h','e','l','l','o' };
	const char* cp = ca;
	while(*cp){
		cout << *cp << endl;
	++cp;
	}
	/*part exercise 3.39*/
	string parta1, parta2;
	cin >> parta1 >> parta2;
	if (parta1 == parta2)
		cout << "Equal! For part A!" << endl;
	else
		cout << "NOT Equal! For part A!" << endl;
	char partb1[k];
	char partb2[k];
	cin >> partb1 >> partb2;
	if(strcmp==0)

		cout << "Equal! For part B!" << endl;
	else
		cout << "NOT equal! For part B!" << endl;
	/*part exercise 3.40*/
	char partc1[] = "Gouliguojia", partc2[] = "Shengsiyi";
	char partc3[40] = "partcdekaitou";
	strcat(partc3, partc1);
	printf("First part:%s\n", partc3);
	strcpy(partc3, partc2);
	printf("Second part:%s\n", partc3);
	return 0;
}