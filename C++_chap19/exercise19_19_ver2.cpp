#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<functional>
using std::string;
using std::istream;
using std::ostream;
struct Sales_data;
//template<class T>class std::hash;
Sales_data operator+(Sales_data lhs, const Sales_data &rhs);
struct Sales_data {
	friend class std::hash<Sales_data>;
    friend std::ostream& operator<<(std::ostream& ,const Sales_data &);
    friend std::istream& operator>>(std::istream &, Sales_data &);
	~Sales_data() = default;
	//copy control: use defaults
	Sales_data(const Sales_data&) = default;

    //exercise19_13:
   static const std::string Sales_data::* ex19_13(){
          return &Sales_data::bookNo;
    }
    private:
	std::string bookNo;
    public:
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {} //case a
     
	Sales_data(const std::string& s, unsigned n, double p = 81.0) :
		bookNo(s), units_sold(n), revenue(p* n) {}//case b
   Sales_data operator+=(const Sales_data &Ob1)
{
    *this=*this+Ob1;
    return (*this); 
}

Sales_data& operator=(const std::string& str)
{
    this->bookNo=str;
    return *this;
}

	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}


	double ave_price()const{
        return static_cast<double>(revenue)/static_cast<double>(units_sold);
    }

	Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data sum = lhs;//copy data members from lhs into sum
		sum.combine(rhs);//add data members from rhs into sum
		return sum;
	}
    
};

Sales_data operator+(Sales_data lhs, const Sales_data &rhs)
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
    os<<"bookNo is:"<<Ob1.bookNo<<"\n units sold: "<<Ob1.units_sold<<"\nave is: "<<Ob1.ave_price()
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

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

bool compareIsbn1(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}
/*
    bool ex19_19_help(size_t ave,size_t threshold){
        if(ave>threshold)return true;
         return false;
    }*/

	
  const Sales_data& ex19_19(std::vector<Sales_data>vctr,int threshold){
	std::function<bool(size_t,size_t)>ex19_19_help=
	[](size_t ave,size_t threshold){if(ave>threshold)return true;
	else return false;};
       double(Sales_data::*it)()const;
       it=&Sales_data::ave_price;
          auto iter=find_if(vctr.cbegin(),vctr.cend(),[=](const Sales_data& item)
          {return ex19_19_help(std::mem_fn(it)(item),threshold);});
          return *iter;
   }
int main(){
 Sales_data item1("ichi",10,100);//ave 100
 Sales_data item2("ni",20,130);//ave 130
 Sales_data item3("san",10,200);//ave 200
 std::vector<Sales_data>items={item1,item2,item3};
 std::cout<<ex19_19(items,120);
}
//Result:Correct!!
/*

bookNo is:ni
 units sold: 20
ave is: 130
*/