#include<vector>
using std::vector;
#include<iostream>
#include<memory>

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

class Disc_quote :public Quote {
    public:
    Disc_quote()=default; //The default constructor initializes those members.
    Disc_quote(const std::string& book,double price,
    std::size_t qty,double disc):
    Quote(book,price),quantity(qty),discount(disc){}
    double net_price(std::size_t)const =0;
    protected:
    std::size_t quantity=0;//purchase size for the discount to apply
    double discount=0.0;//fractional discount to apply
};
class Bulk_quote: public Disc_quote{
    public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t)const override;
    int tst;
    bool tst1;
    bool tst2;
};

double Bulk_quote::net_price(std::size_t sz1)const
{
    if(sz1>1000){std::cout<<"Oversized!\n";return sz1*price;}
    if(sz1>quantity)return quantity*(1-discount)*price+(sz1-quantity)*price;
    else return quantity*price;
}

int main()
{
   vector<Quote>basket;
   
   //we cannot convert Quote to Bulk_quote. But we can, on the other hand, 
   //convert Bulk_quote to quote(sliced down)
   basket.push_back(Quote("o-201-82470-1",50));
   //basket.push_back("o-201-82470-1",50);//error:
   basket.emplace_back("o-201-82470-1",50);

//ok but copies only the Quote part of an object into basket
   basket.push_back(Bulk_quote("0-201-54848-8",50,10,.25));

//calls version defined by Quote, prints 750, i.e., 15*$50
   std::cout<<basket.back().net_price(15)<<std::endl;//750


   /*Put (smart)pointers, not objects, in containers*/
   vector<std::shared_ptr<Quote>>basket1;
   
   basket1.push_back(std::make_shared<Quote>("0-201-82470-1",50));
   
   basket1.push_back(std::make_shared<Bulk_quote>("0-201-54848-8",50,10,.25));
   //calls the version defined by Quote; prints
   std::cout<<basket1.back()->net_price(15)<<std::endl;//625
   //625 here, we called Balk_quote::net_price(size_t)here.
   //basket1.back(): static type: std::shared_ptr<Quote>, dynamic type std::shared_ptr<Bulk_quote>
   //Just as we can convert an ordinary pointer to a derived type to a pointer to an base-class type.
   //We can also convert a smart pointer to a derived type to a smart pointer to an base-class type. 
   //Thus, make_shared<Bulk_quote>returns a shared_ptr<Bulk_quote> object, which is converted to shared_ptr<Quote>
   //when we call push_back.

}