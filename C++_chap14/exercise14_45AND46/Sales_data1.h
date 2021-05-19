#pragma once
#ifndef SALES_DATA_CHAP13_VER4_H
#define SALES_DATA_CHAP13_VER4_H
//sec 14.45: 
#include <iostream>
#include <string>
#include<utility>
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
	explicit
	 operator string()const{return bookNo;}
	 explicit
	 operator double()const{return revenue;}
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

	Sales_data add1(const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data sum = lhs;//copy data members from lhs into sum
		sum.combine(rhs);//add data members from rhs into sum
		return sum;
	}
};

Sales_data operator+( const Sales_data &lhs, const Sales_data &rhs)
	{
		Sales_data item;
		item.units_sold=lhs.units_sold+rhs.units_sold;
		item.isbn()=lhs.isbn();
		item.revenue=lhs.revenue+rhs.revenue;
		return item;
	}


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
	if(is)//check that the input succeed
	Ob1.revenue=Ob1.units_sold*price;
	else
	{
		std::cout<<"Failure!\n";
		Ob1=Sales_data();//input failed: give the object the default state
	}
    return is;
}



//compound assignment

#endif