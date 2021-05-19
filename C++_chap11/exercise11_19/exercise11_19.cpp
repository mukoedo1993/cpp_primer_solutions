#include<iostream>
#include"Strong_sales_data.h"
#include<set>
#include<vector>
#include<iterator>
using std::vector;
using std::multiset;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	vector<Sales_data>V;
	V.emplace_back("ekek");
	V.emplace_back("dldl");
	multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>
		bookstore(compareIsbn);//Supply a pointer to the bookstore.
	copy(V.begin(), V.end(), inserter(bookstore, bookstore.begin()));
	print(std::cout, *(bookstore.begin()));

}