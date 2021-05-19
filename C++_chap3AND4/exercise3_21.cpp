#include<iostream>
// exercise 3.21:
#include<string>
#include<vector>
using std::vector;
using std::string; using std::cout; using std::endl;
int main()
{
	vector<string>hehe = { "ahshsgsA","shdshchAdsf","WWW2JD" };
	cout << hehe.size() << endl;
	for (int i = 0; i < hehe.size(); i++)
		cout << hehe[i] << endl;
}