#include<iostream>
#include<string>
using std::string;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs,double price)
	{
		units_sold += rhs.units_sold;
		
		revenue =units_sold*price;
		return *this;
	}
};

int main()
{
	double price;
	Sales_data total;
	if (std::cin >> total.bookNo >> total.units_sold >> price)
	{
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold)
		{

			if (total.bookNo == trans.bookNo)
			{
				total.combine(trans,price);

				std::cout <<"The isbn is: "<<total.isbn()<< ". The total revenue now is:" << total.revenue << std::endl;
			}
			else
			{
				std::cout << "Are you sure?Two books have different book No.!\n";
				return -1;
			}
		}
	}
	else {
		std::cout << "Attention. Please follow the format as required!\n" << std::endl;
		return -1;
	}
	return 0;
}