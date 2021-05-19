#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	//count the number of grades by clusters 0-9,10-19,...,90-99,100
	unsigned scores[11] = {};//11 buckets, all value initialized to 0
	unsigned grade;
	while (cin >> grade)
	{
		if (grade > 100 || grade < 0)
		{
			cout << "Counters stop working now." << endl; break;
		}
		++scores[grade / 10];
	}
	for (auto i : scores)//for each counter(element) in scores
		cout << i << " " << endl;//print the value of that counter(element)
}