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
	int sum = 0, val = 1;
	while (val <= 10)sum += val, ++val;
	cout << sum << endl;
	int sum1;
	cin >> sum1;
	switch (sum1)
	{
	case 10:case 12:case 22:
		cout << "You are lucky!" << endl;
		break;
	default:
		cout << "You are unlucky!" << endl;
		break;
	}
	do {
		sum1++; cout << sum1 << endl;
	} while (sum1 < 11);
	int sum2 = 53;
	while(sum2<54)
	{
		sum2 = sum2 + 1; cout << sum2 << endl;
	}
}
