// Access Control and Encapsulation
//access specifier
/*
1: Members defined after a public specifier are accessible to all
parts of the program. The public members define the interface to the
class.
2:Members defined after a private specifier are accessible to the 
funtions of the class but are not accessible to code that uses the class.
The private sections encapsulate(i.e., hide) the implementation.
*/
#include<iostream>
using std::string;
class Sales_data {

public://access specifier added
	Sales_data() = default;
	Sales_data(const std::string & s, unsigned n, double p):
		bookNo(s),units_sold(n),revenue(p*n){}
	Sales_data(const std::string &s):bookNo(s){}
	Sales_data(std::istream&);
	std::string isbn()const { return bookNo; }
private:
	string bookNo;
	double avg_price()const
	{
		return units_sold ? revenue / units_sold : 0; 
	}
	unsigned units_sold = 0;
	double revenue = 0.0;

};
//public: default setting->struct
//private: default setting->class