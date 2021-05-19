#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::endl;
int main()
{
	string s("Hello World!!!");
	decltype(s.size())punct_cnt = 0;
	//count the number of punctuation characters in s
	for (auto c : s)//for every char in s
		if (ispunct(c))//if the character is the punctuation
			++punct_cnt;
		cout << punct_cnt
			<< "punctuations characters in" << s << endl;
	
}
