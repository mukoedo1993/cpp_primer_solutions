#include<iostream>
#include<string>
/*
In addition, we'll give Sales_data another member function to return
the average price at which the books were sold. This function, which we'll 
name avg_price, isn't intended for general use. 
1:Member functions must be declared inside the class.
2:Member functions may be defined inside the class itself or outside the class body.
3:Non-member functions that are part of the interface, such as add, read, and print, are declared and defined outside 
the class.
*/

struct Sales_data {
	//new members:operations on Sales_data objects
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double ave_price()const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};
//nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

//this:
/*
!!!!!!!!
Member functions access the object on which they were
called through an extra, implicit parameter named this.
!!!!!!!!

When we call a member function, this is initialized with the address of the object on 
which the function was invoked. For example, when we call
total.isbn()
, the compiler passes the address of total to the implicit this parameter in isbn.
Like the code below:
Sales_data::isbn(&total)//pseudocode
std::string isbn()const {return this->bookNo;}//a alternative but unnecessary way to define


*/

// const Member Functions:
/*
About the isbn function:
The keyword const that follows the parameter list. The purpose of that const is to modify
the type of the type of the implicit this pointer.

By  default, the type of this is a const poiter to the nonconst version of the class type.
For example, by default, the type of this in a Sales_data member function is Sales_data *const.
Although this is implicit, it follows the normal initialization rules, which means that (by default)
we cannot bind this to a const member function on a const object.

If isbn were an ordinary function and if thid were an ordinary pointer parameter, we would declare this
as const Sales_data *const. After all, the body of isbn doesn't change the object in which this points, so
our function would be more flexible if this were a pointer to const.

However, this is implicit and does not appear in the parameter list. There is no place to indicate 
that this should be a pointer to const. The language resloves this problem by letting us put const after 
the parameter list of a member function. A const following the parameter list indicates that this is a pointer to const.
Member functions that use const in this way are const member functions.
*/
double Sales_data::ave_price()const
{//The scope means that the function ave_price is in the scope of Sales_data.
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

/*
The combine function is intended to act like the compound assignment operator,+=. 
The object on which this function is called represents the left-hand operand of this assignment. The right-hand operand 
is passed as an explicit argument.
*/
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;//add the members of rhs into the member of "this" object.
	revenue  += rhs.revenue;
	return *this;// return the object
}
int main()
{
	Sales_data OB1, OB2;
	OB1.bookNo = "sjjhdg"; OB2.bookNo = "sjjhdg";
	OB1.combine(OB2);
    
}