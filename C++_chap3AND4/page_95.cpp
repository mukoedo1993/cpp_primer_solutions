#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< "separated by spaces. HIT ENTER when finished:"
		<< std::endl;
	string result;//will hold he resulting hexify'd string
	string::size_type n;//holding numbers from the input
	while (cin >> n)
	{
		if (n < hexdigits.size())
			result = result + hexdigits[n];
		if (n == 'E')
			break;
	}
	cout << result << endl;
}