//Some design principles:
//1:If a class has an operation to determine whether two objects are equal, it should 
//define that function as operator== rather than as a named function: Users will expect to
//compare objects using ==; providing == means they won't need to learn and remember a new
//name for the operation; and it is easier to use the library containers and algorithms that
//define the == operator.
//2: == != one appears, so does the other.



#include <iostream>
#include <string>
#include<fstream>
#include<vector>
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

   Sales_data operator-=(const Sales_data &Ob1)
{
    units_sold=units_sold-Ob1.units_sold;
    revenue=revenue-Ob1.revenue;
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

Sales_data
operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum=lhs;//copy data members from lhs into sum
    sum+=rhs;//add rhs into sum
    return sum;
}

Sales_data
operator-(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum=lhs;//copy data members from lhs into sum
    sum-=rhs;//add rhs into sum
    return sum;
}

/*Sec 14.3.1 Equality Operators*/
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn()==rhs.isbn()&&
    lhs.units_sold==rhs.units_sold&&
    lhs.revenue==rhs.revenue;
}

bool operator!=(const Sales_data &lhs,const Sales_data &rhs)
{return !(lhs==rhs);}



int main()
{
    std::ifstream input("ex14_13i.txt");
    std::vector<Sales_data>vec;
    while(true)
    {
        Sales_data item1;
        input>>item1;
        std::cout<<item1;
        vec.push_back(item1);
        if(!input)break;
    }
Sales_data mkft;
mkft=vec[0]+vec[1];
vec.push_back(mkft);
mkft=vec[1]-vec[0];
vec.push_back(mkft);
for(auto item:vec)
std::cout<<item;
std::cout<<std::boolalpha;
std::cout<<(vec[0]==vec[0]);//true
std::cout<<std::endl<<(vec[0]!=vec[1]);//true
}