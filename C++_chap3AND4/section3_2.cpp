#include<iostream>
using std::cin;
using std::cout;
using std::string;
int main()
{
	string s1;//default initialization:s1 is the empty string
	string s2 = s1;//s2 is a copy of s1
	string s3 = "hiya";//s3 is a copy of the string literal
	string s4(10, 'c');//direct initialization: s4 is cccccccccc
	cout << s4 << std::endl;
	string s5("hiyaa");//direct initialization.
	string s6;
	s6 = s4 + s5;
	cout << s6 << std::endl;
	bool d, d1;
	d = s1.empty();
	cout << d << std::endl;
	d1 = s4.empty();
	cout << d1 << std::endl;

	//page 86:
	cout << "page 86: Read unknown number of strings:" << std::endl;
	string word; int i = 0;
	while (cin >> word && i < 10)
	{
		i++;
		if (word.size() > 10)
			cout << "Long line! ";
		cout << word << std::endl;
	}
	string str = "Hello";
	string phrase = "Hello World!";
	string slang = "Hiyaa";
	if (str < phrase)
		cout << "phrase is larger!";
	if (str < slang)
		cout << "slang is larger!";
	// warning: If adding two literals of string, things will go wrong!

	return 0;
}