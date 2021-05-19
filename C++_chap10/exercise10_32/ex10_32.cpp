#include<iostream>
#include"Sales_item.h"
#include<fstream>
#include<string>
#include<iterator>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
#include<sstream>
using std::string;
using std::vector;
using std::cin; using std::cout;
using std::endl;
using std::placeholders::_1;
using std::placeholders::_2;


int main()
{
	std::ifstream input1("ex10_32i.txt");
	std::ofstream output("ex10_32o.txt");
	
	vector < Sales_item >Sales_classes;
	string str1_;
	while (getline(input1, str1_))
	{
		
	
		std::istringstream Ob1(str1_);
		Sales_item mkft;
		Ob1 >> mkft;
		Sales_classes.push_back(mkft);
	}

	sort(Sales_classes.begin(), Sales_classes.end(), 
		[](Sales_item Ob1, Sales_item Ob2)->
		bool {if (Ob1.isbn() < Ob2.isbn())
		return true;
		else return false;
		});
	auto curr = Sales_classes.begin(), back = curr;
	while (curr != Sales_classes.end())
	{
		back = curr;
		Sales_item Original;
		
		
		auto it_ = find_if(curr, Sales_classes.end(), [=](Sales_item Ob1)
			->bool {
				if (Ob1.isbn() != curr->isbn())
					return true;
				else return false;
			});

		//curr->print(output);

		output <<"First sale for this kind of item: "<< *curr;
		output << endl;
		output  <<"In total: "<<accumulate(curr, it_, Original)<<"\n\n\n";
		curr = it_;
	}
}