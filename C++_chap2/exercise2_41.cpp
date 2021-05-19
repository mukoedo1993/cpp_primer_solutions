#include<iostream>
#include<string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main()
{
	Sales_data data1, data2;
	double price;
	std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue>>price;
	std::cin >> data2.bookNo >> data2.units_sold >> data2.revenue;
	if (data1.bookNo == data2.bookNo)
	{
		double totalrev;
		totalrev = data1.revenue+data2.revenue+(data1.units_sold + data2.units_sold) * price;
		std::cout << totalrev << std::endl;
	}
	else
	{
		std::cerr << "Error! Two books don't share the same bookNO!" << std::endl;
		return -1;
	}
	return 0;
}