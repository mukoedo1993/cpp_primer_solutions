#include"sales_data_sec18_2_1.h"
namespace cplusplus_primer{


 Sales_data& Sales_data::combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

   Sales_data Sales_data::add(const Sales_data& lhs, const Sales_data& rhs)
	{
      
		Sales_data sum = lhs;//copy data members from lhs into sum
        std::cout<<"first sum"<<sum<<std::endl;
		sum.combine(rhs);//add data members from rhs into sum
        std::cout<<"second sum"<<sum<<std::endl;
		return sum;
	}

   Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;//calls the string::operator=
	units_sold = rhs.units_sold;//uses the built-in int assignment
	revenue = rhs.revenue;//uses the built-in double assignment
	return *this;//return a reference to this object
}
}
//The overloads of operator>> and operator<< that take a std::istream& or std::ostream& 
//as the left hand argument are known as insertion and extraction operators. 
//Since they take the user-defined type as the right argument (b in a@b), 
//they must be implemented as non-members.
namespace cplusplus_primer{


bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

bool compareIsbn1(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

double Sales_data::ave_price()const
{
    return revenue/units_sold;
}

}

std::ostream& operator<<(std::ostream& os,const cplusplus_primer::Sales_data &Ob1){
    os<<"bookNo is:"<<Ob1.bookNo<<"\n units sold: "<<Ob1.units_sold<<"\nrevenue is: "<<Ob1.revenue
	<<std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, cplusplus_primer::Sales_data &Ob1)
{
	
	double price;//no need to initaialze; we'll read the price before we use it.
    is>>Ob1.bookNo>>Ob1.units_sold>>price;
	if(is)//check that the input succeed
	Ob1.revenue=Ob1.units_sold*price;
	else
	{
		std::cout<<"Failure!\n";
		Ob1=cplusplus_primer::Sales_data();//input failed: give the object the default state
	}
    return is;
}