#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"Strong_sales_data.h"
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;



bool compareIsbn(Sales_data& Ob1, Sales_data& Ob2)
{
	return Ob1.isbn().size() < Ob2.isbn().size();
}
int main()
{
	std::ifstream input("ex10_17i.txt");
	std::ofstream output("ex10_17o.txt");
	if (!input.is_open())return-1;
	string str; vector<Sales_data>SalesDataClass;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		Sales_data Clss(Ob1);
		SalesDataClass.push_back(Clss);
	}

	//step2: sort.
	sort(SalesDataClass.begin(), SalesDataClass.end(),
		[](Sales_data& Ob1, Sales_data& Ob2)
		{return Ob1.isbn().size() < Ob2.isbn().size(); });
	int cnt = 1;
	for (auto it = SalesDataClass.begin(); it < SalesDataClass.end(); it++)
	{
		output << "The " << cnt << "st(nd,th) item is: ";
		print(output, *it);
		cnt++;
	}
}
