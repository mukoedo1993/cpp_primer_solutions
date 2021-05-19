/*Abstract Base Class*/
//Each of these discount strategies is the same in that it
//requires a quantity and a discount amount.
//Defining a new class named Disc_quote to:
//1: store the quantity 2: disocunt amount
#include<iostream>
using std::string;

class Quote{
          
    public: Quote()=default;
    Quote(const std::string&book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn()const{return bookNo;}
    virtual double net_price(std::size_t n)const
    {return n*price;}
      ~Quote()=default;
    private:
    std::string bookNo;
    protected:
    double price=0.0;
};

//Before we can define our Disc_Quote class, we have to decide what to do about net_price.
//Our Disc_quote class doesn't correspond to any particular discount strategy; there is no meaning
//to ascribe to net_price for that class.

//However, this design would make it possible for our users to write nonsensical code. A user could
//create an object of type Disc_quote by supplying a quantity and a discount rate. Passing that Disc_quote
//to a function such as print_total would use the Quote version of the net_price. The calculated price
//would not include the discount that was supplied when the object was created. That state of affairs makes no
//sense.


//We don't want to define Disc_quote::net_price(), actually, we don't want the user to call a Disc_quote
//object at all!!!! 

//class to hold the discount rate and quantity
//derived classes will implement pricing strategies using these data
//We don't know how to define Disc_quote::net_price(std::size_t){}
//We can enforce this design intent--and make it clear that there is no meaning for
//net_price-- by defining net_price as a pure virtual function. Unlike
class Disc_quote :public Quote {
    public:
    Disc_quote()=default; //The default constructor initializes those members.
    Disc_quote(const std::string& book,double price,
    std::size_t qty,double disc):
    Quote(book,price),quantity(qty),discount(disc){}
    double net_price(std::size_t)const =0;
    //here, we cannot provide a definition for the function net_price inside the class.

    protected:
    std::size_t quantity=0;//purchase size for the discount to apply
    double discount=0.0;//fractional discount to apply
};
//It is worth noting that we can provide a definition for a pure virtual. 
//However, the function body must be defined outside the class. That is, we cannot provide
//a function body inside the class for a function that is=0. 


//the discount kicks in when a specified number of copies of the same book are sold
//the discount is expressed as a fraction to use to reduce the normal price
class Bulk_quote: public Disc_quote{
    public:
    Bulk_quote()=default;
    Bulk_quote(const std::string&book,double price,
    std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
    // overrides the base version to implement the bulk purchase discount policy
    double net_price(std::size_t)const override;
};

double Bulk_quote::net_price(std::size_t sz1)const
{
    if(sz1>1000){std::cout<<"Oversized!\n";return sz1*price;}
    if(sz1>quantity)return quantity*(1-discount)*price+(sz1-quantity)*price;
    else return quantity*price;
}
//This version of Bulk_quote has a direct base class. Disc_quote, and an indirect base class,
//Quote. Each Bulk_quote object has three subobjects: an (empty)Bulk_quote part, a Disc_quote part,
// and a Quote subobject.


int main()
{
 /*Classes with pure virtuals are abstract base classes*/
//abstract base class
//A class containing (or inheriting without overriding) a pure virtual function is an abstract class.

//Disc_quote declares pure virtual functions, which Bulk_quote will override
//Disc_quote discounted;//error: can't define a Disc_quote object.
Bulk_quote bulk;//ok: Bulk_quote has no pure virtual functions
Bulk_quote bulk1("The_pricncess",10.0,100,0.8);
std::cout<<std::endl<<bulk1.net_price(200);
std::cout<<std::endl<<bulk1.net_price(1001);
}