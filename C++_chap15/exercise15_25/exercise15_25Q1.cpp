#include<iostream>

class B{
    public:
    B()=default;
    B(const B&)=delete;
};

class D:public B{
    //no constructors
};

class Quote{//Now, this class, Quote objects will be memberwise copied, moved, assigned, and destroyed.
          
    public: Quote()=default;//memberwise default initialize
    Quote(const Quote&)=default;//memberwise copy
    Quote(Quote&&)=default;//memberwise copy
    Quote&operator=(const Quote&)=default;//copy design
    Quote&operator=(Quote&&)=default;//move design
    Quote(const std::string&book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn()const{return bookNo;}
    virtual double net_price(std::size_t n)const
    {return n*price;}
      virtual ~Quote()=default;
    private:
    std::string bookNo;
    protected:
    double price=0.0;
};
class Disc_quote:public Quote{
    public:
    //Disc_quote()=default;
    Disc_quote(const std::string&book,double Sales_price):Quote(book,Sales_price){}
    double net_price(std::size_t n)const=0;
    ~Disc_quote()=default;
};

class Bulk_quote :public Disc_quote{
 public:
 Bulk_quote(const std::string &book,double p,std::size_t qty,double disc)
 :Disc_quote(book,p),min_qty(qty),discount(disc){}
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t n)const override;
 
 void make_more_discnt(){discount=0.5*discount;}
  void make_more_discnt(double discnt){discount=discnt*discount;}
 private: std::size_t min_qty =0;
 double discount=0.0;
}; 

double Bulk_quote::net_price(std::size_t cnt)const 
{
    if(cnt>=min_qty)
    return cnt*(1-discount)*price;
    else
    {
        return cnt*price;
    }
    
}
auto print_total(std::ostream &os,const Quote &item,size_t n)->double
{
    double ret=item.net_price(n);
    os<<"ISBN: "<<item.isbn()//calls Quote::isbn
    <<"# sold: "<<n<<" total due:"<<ret<<std::endl;
    return ret;
}

int main()
{
    
}