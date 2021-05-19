/*#include<iostream>
#include<string>
using std::string;
using std::cin;
int main()
{
	string str1, str2, str3;
	cin >> str1; int i;
	std::cout << str1 << std::endl;
	for (auto &c:str1)
	{
		if (!ispunct(c))
			str2 = str2 + c;
	}
	std::cout <<str1<<std::endl<< str2 << std::endl;
}*/
// Write a program that reads a string of characters including punctuation
// and writes what was read but with the punctuation removed.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;
#include <string>
#include <iostream>
#include <cctype>

int main() {

    std::string text = ".his. is my string. it's here...";

    for (int i = 0, len = text.size(); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            text.erase(i--, 1);/* The erased element will be moved out
                               and its subindex will not be counted!*/
            len = text.size();
        }
    }

    std::cout << text;
    return 0;
    const std::string s1 = "Keep Out!";
    for (auto& c : s1)
    {
        /* */
    }
}