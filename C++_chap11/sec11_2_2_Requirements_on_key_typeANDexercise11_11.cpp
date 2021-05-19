//For the ordered containers-- map, multimap, setm and multiset-the key type must define a 
//way to compare the elements. (Default: <)


//Either less than, not less than OR equal.

//Build a function to compare two classes:
#include"Strong_sales_data.h"
#include<iostream>
#include<set>
using std::multiset;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

bool compareIsbn1(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}


int main()
{
	/*
	*To use our own operation,we must define the muliset with two types:
	*the key type,Sales_data, and the comparsion type, which is a function pointer,
	*that can point to compareIsbn.
	* When we define objects of this type, we supply a pointer to the operation we intend to
	*use. In this case, we supply a pointer to compareIsbn:
	*/

	//bookStore can have several transactions with the same ISBN
	//elements in bookstore will be in ISBN order
	multiset<Sales_data, decltype(compareIsbn)*>bookstore(compareIsbn);
	//compareIsbn<-equal->&compareIsbn
	//Because they have the same effect.
	//exercise 11_11:
	using PF = bool(*)(const Sales_data&, const Sales_data&);
	multiset<Sales_data, PF>bookstore1(compareIsbn);
	bookstore = { Sales_data(std::string("dishi")),Sales_data(std::string("cik")) };
	bookstore1 = { Sales_data(std::string("dishi1")),Sales_data(std::string("cik1")) };
	std::cout << bookstore.begin()->isbn()<<std::endl;
	std::cout << bookstore1.begin()->isbn() << std::endl;

}