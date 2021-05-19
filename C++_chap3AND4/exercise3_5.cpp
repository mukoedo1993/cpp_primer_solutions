#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
int main()
{
//Part 1:he2 bing4
	string strng,strng1;
	string mkft, mkft1; int i = 0;
	while (cin >> strng&&i<10)
	{
		mkft = mkft + strng;
		strng = mkft1;
		i++;
	}
	mkft = mkft + strng;
	strng = mkft1;
	cout << mkft << std::endl;

	//Part 2:fen1 li2
	string strng3, strng4;
	string mkft2, mkft3; int i1 = 0;
	while (cin >> strng3 && i1 < 10)
	{
		mkft2 = mkft2 + strng3+" ";
		strng3 = mkft3;
		i1++;
	}
	mkft2 = mkft2 + strng3 + " ";
	strng3 = mkft3;
	cout << mkft2 << std::endl;


}