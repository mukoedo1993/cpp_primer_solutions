#ifndef SALES_DATA_CHAP18_1_5_H
#define SALES_DATA_CHAP18_1_5_H
//sec 16.5: Using default
#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
struct Sales_data;
//template<class T>class std::hash;
class isbn_mismatch;
namespace cplusplus_primer{
Sales_data operator+(Sales_data lhs, const Sales_data &rhs);
struct Sales_data {
	friend class std::hash<Sales_data>;
	~Sales_data() = default;
	//copy control: use defaults
	Sales_data(const Sales_data&) = default;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {} //case a
     
	Sales_data(const std::string& s, unsigned n, double p = 81.0) :
		bookNo(s), units_sold(n), revenue(p* n) {}//case b
   Sales_data& operator+=(const Sales_data &Ob1);
Sales_data& operator=(const std::string& str)
{
    this->bookNo=str;
    return *this;
}

	std::string isbn()const { return bookNo; }

 Sales_data& combine(const Sales_data& rhs);
	double ave_price()const;

        Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
};
}

std::ostream& operator<<(std::ostream& os,const cplusplus_primer::Sales_data &Ob1);
std::istream& operator>>(std::istream &is, cplusplus_primer::Sales_data &Ob1);
#endif