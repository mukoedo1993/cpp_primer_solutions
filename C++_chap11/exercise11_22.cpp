#include<iostream>
#include<map>
#include<utility>
#include<fstream>
#include<iterator>
#include<vector>
using std::map;
using std::string; using std::vector;
using std::pair;
int main()
{
	vector<int>V = { 1,4,5,6,7 }; auto V1 = V, V2 = V1;
	(*(V1.begin()))++; V2.at(3)++;
	map<string, vector<int>>map1;
	map1["sadi"] = V;
	map1["sad"] = V1;
	map1["Turkey"] = V2;
	string str = "sad",str1="dshdshshf",str2="sdhdhshg";

	//test:
	pair<map<string,vector<int>>::iterator,bool> it111= map1.insert(make_pair(str, V1));
	std::cout << std::boolalpha;
	std::cout << it111.second;
	pair<map<string, vector<int>>::iterator, bool> it112 = map1.insert(make_pair(str1, V1));
	std::cout << std::boolalpha;
	std::cout << it112.second;
	pair<map<string, vector<int>>::iterator, bool> it113 = map1.insert(make_pair(str2, V1));
	std::cout << std::boolalpha;
	std::cout << it113.second;
	//final result: falsetruetrue
	//It passed the test!
}