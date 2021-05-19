//Under the new standard, a derived class can reuse the constructors defined by its direct base class.
//Although, as we'll see, such constructors are not inherited in the normal sense of that term, it is
//nonetheless common to refer to such constructors as "inherited."

#include<iostream>
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
    //here, we cannot provide a definition for the function net_price inside the class.

    protected:
    std::size_t quantity=0;//purchase size for the discount to apply
    double discount=0.0;//fractional discount to apply
};
class Bulk_quote: public Disc_quote{
    public:

    //sec15_7_4, page 628 update:
    using Disc_quote::Disc_quote;//inherit Disc_quote's constructors
    //It is equivalent to:
     /*
       Bulk_quote(const std::string&book,double price,
    std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
     */
    //Note: these compiler generated constructors have the form:
    //derived(params):base(args){}

    double net_price(std::size_t)const override;


    //If the derived class has any data members of its own, those members are
    //default initialized.
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
    Bulk_quote ob1("kimura",11.4,514,0.8);
    std::cout<<ob1.net_price(1000);//6712.32
    std::cout<<std::endl<<ob1.tst;//0
    std::cout<<std::boolalpha;
    std::cout<<std::endl<<ob1.tst1;//false
    std::cout<<std::endl<<ob1.tst2;//false
}