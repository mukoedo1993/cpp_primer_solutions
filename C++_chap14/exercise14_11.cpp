#include <iostream>
#include <string>
#include<fstream>
using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
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

    Sales_data operator+=(const Sales_data &Ob1)
{
    units_sold=units_sold+Ob1.units_sold;
    revenue=revenue+Ob1.revenue;
    if(bookNo!=Ob1.bookNo)
    bookNo=Ob1.bookNo;
    return *this;
    
}

	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}


	double ave_price()const;

	Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data sum = lhs;//copy data members from lhs into sum
		sum.combine(rhs);//add data members from rhs into sum
		return sum;
	}
};

//
//copy-assignment operator(=)
Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;//calls the string::operator=
	units_sold = rhs.units_sold;//uses the built-in int assignment
	revenue = rhs.revenue;//uses the built-in double assignment
	return *this;//return a reference to this object
}

//The overloads of operator>> and operator<< that take a std::istream& or std::ostream& 
//as the left hand argument are known as insertion and extraction operators. 
//Since they take the user-defined type as the right argument (b in a@b), 
//they must be implemented as non-members.
std::ostream& operator<<(std::ostream& os,const Sales_data &Ob1){
    os<<"bookNo is:"<<Ob1.bookNo<<"\n units sold: "<<Ob1.units_sold<<"\nrevenue is: "<<Ob1.revenue
	<<std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Sales_data &Ob1)
{
	
	double price;//no need to initaialze; we'll read the price before we use it.
    is>>Ob1.bookNo>>Ob1.units_sold>>price;
	//check that the input succeed
	Ob1.revenue=Ob1.units_sold*price;
	
    return is;
}


int main()
{
    std::ifstream input("ex14_10i.txt");
    while(true)
    {
        Sales_data item1;
        input>>item1;
        std::cout<<item1;
        if(!input)break;
    }

}