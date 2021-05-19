#include<iostream>
#include<stdexcept>
#include"sales_data_sec18_1_5.h"
//exception: has a copy constructor, copy-assignment operator and a virtual
//destructor, and a virtual member named what. The what function returns a const char*
//that points to a null-terminated character array, and is guaranteed not to throw
//any exceptions.
//Because what is virtual, if we catch a reference to the base-type, a call to the what
//function will execute the version appropriate to the dynamic type of the exception object.


//hypothetical exception classes for a bookstore application
class out_of_stock:public std::runtime_error{
    public:
    explicit out_of_stock(const std::string &s):
    std::runtime_error(s){}
};

class isbn_mismatch:public std::logic_error{
    public:
    explicit isbn_mismatch(const std::string &s):
    std::logic_error(s){}
    isbn_mismatch(const std::string &s,
    const std::string&lhs,
    const std::string&rhs):
    std::logic_error(s),left(lhs),right(rhs){}
    std::string left,right;
};
 Sales_data& Sales_data::operator+=(const Sales_data &rhs)
 {
     if(isbn()!=rhs.isbn())
     throw isbn_mismatch("wrong isbns,\n",isbn(),rhs.isbn());
     units_sold+=rhs.units_sold;
     revenue+=rhs.revenue;
     return *this;
 }
 Sales_data operator+( Sales_data lhs, const Sales_data &rhs)
	{
        if(lhs.isbn()!=rhs.isbn())throw isbn_mismatch("!",lhs.isbn(),rhs.isbn());
		Sales_data item;
		item.units_sold=lhs.units_sold+rhs.units_sold;
		item.bookNo=lhs.isbn();
        std::cout<<"item.isbn()"<<lhs.isbn()<<std::endl;
		item.revenue=lhs.revenue+rhs.revenue;
		return item;
	}

int main()
{
   Sales_data item1("kimura"),item2("kimura");
   Sales_data item3("yaju");
   try{item1+=item3;}catch(const isbn_mismatch& err){std::cerr<<err.what();}


   Sales_data itema,itemb,sum;
   while(std::cin>>itema>>itemb&&itema.isbn()!="q"){//read two transactions
   
       sum=itema+itemb;//calculate their sum
       std::cout<<itema<<std::endl;
       std::cout<<itemb<<std::endl;
       std::cout<<sum<<std::endl;
   }
}

//Result:
/*

wrong isbns,
cia 12 3.4
cia 13 4.5
item.isbn()cia
bookNo is:cia
 units sold: 12
revenue is: 40.8

bookNo is:cia
 units sold: 13
revenue is: 58.5

bookNo is:cia
 units sold: 25
revenue is: 99.3

cia1 13 4.2
cia2 15 4.3
terminate called after throwing an instance of 'isbn_mismatch'
  what():  !
*/