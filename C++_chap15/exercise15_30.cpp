#include<iostream>
#include<set>
#include<memory>

class Quote{
          
    public: Quote()=default;
    virtual Quote* clone()const&{return new Quote(*this);}
    virtual Quote* clone()&&{return new Quote(std::move(*this));}
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

auto print_total(std::ostream &os,const Quote &item,size_t n)->double
{
    double ret=item.net_price(n);
    os<<"ISBN: "<<item.isbn()//calls Quote::isbn
    <<"# sold: "<<n<<" total due:"<<ret<<std::endl;
    return ret;
}

class Disc_quote:public Quote{
    public:
    Disc_quote():Quote(){}

    Disc_quote(const std::string&book,double Sales_price):Quote(book,Sales_price)
    {}
    Disc_quote(const Disc_quote&orig):Quote(orig.isbn(),orig.price)
    {}
    Disc_quote(Disc_quote&&moved_from):Quote(std::move(moved_from).isbn(),std::move(moved_from).price)
    {}
    Disc_quote& operator=(Disc_quote&& d)
    {
    
    Quote::operator=(std::move(d));return *this;
    }
    Disc_quote& operator=(const Disc_quote&d)
    {
        Quote::operator=(d);return *this;
    }

    double net_price(std::size_t n)const=0;
    ~Disc_quote(){}
};

class Bulk_quote :public Disc_quote{
 public:
virtual Bulk_quote* clone()const&{return new Bulk_quote(*this);}
virtual Bulk_quote* clone()&&{return new Bulk_quote(std::move(*this));}

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

class Basket{
    public:
    void add_item(const std::shared_ptr<Quote>&sale)
    {items.insert(sale);}

    void add_item(const Quote&sale)
    {items.insert(std::shared_ptr<Quote>(sale.clone()));}

      void add_item(Quote&&sale)
    {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}
    
     void add_item(std::shared_ptr<Quote>&&sale)
    {items.insert(std::move(sale));}
    double total_receipt(std::ostream&)const;
    
    void print_all_prices(std::ostream&os,size_t n)const{
            double sum=0.0;
    for(auto iter=items.cbegin();
    iter!=items.cend();iter=items.upper_bound(*iter)){
    os<<"Price for this item: "<<(*iter)->net_price(n)<<"\n";
    }
    }
    private:
    static bool compare(const std::shared_ptr<Quote>&lhs,const std::shared_ptr<Quote>&rhs)
    {return lhs->isbn()<rhs->isbn();}
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*>items{compare};
};

double Basket::total_receipt(std::ostream&os)const
{
    double sum=0.0;
    for(auto iter=items.cbegin();
    iter!=items.cend();iter=items.upper_bound(*iter)){
    sum+=print_total(os,**iter,items.count(*iter));
    }

    os<<"Total Sale: "<<sum<<std::endl;
    return sum;
}

int main(){
       Basket bsk;
    bsk.add_item(std::make_shared<Quote>("123",45));
    bsk.add_item(std::make_shared<Bulk_quote>("345",45,3,.15));
    bsk.add_item(std::make_shared<Quote>("346",93));
   bsk.print_all_prices(std::cout,13);
}
/*


Price for this item: 585
Price for this item: 497.25
Price for this item: 1209

*/