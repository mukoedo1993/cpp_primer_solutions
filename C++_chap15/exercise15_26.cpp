#include<iostream>
//https://stackoverflow.com/questions/12189259/confusion-with-copy-constructor-and-private-member

class Quote{//Now, this class, Quote objects will be memberwise copied, moved, assigned, and destroyed.
          
    public: Quote(){ std::cout<<"Quote()\n";}//memberwise default initialize
    Quote(const Quote& orig){
        std::cout<<"Quote(const Quote& orig)\n";
        bookNo=orig.bookNo; price=orig.price;
    }//memberwise copy
    Quote(Quote&& moved_from){std::cout<<"Quote(Quote&& moved_from)\n";
        bookNo=std::move(moved_from).bookNo;
    price=std::move(moved_from).price;}//memberwise copy
    Quote&operator=(const Quote&orig){std::cout<<"Quote&operator=(const Quote&orig)\n";
        bookNo=orig.bookNo; price=orig.price;return *this;};//copy design
    Quote&operator=(Quote&&moved_from){std::cout<<"Quote&operator=(Quote&&moved_from)\n";
        if(this!=&moved_from){bookNo=std::move(moved_from).bookNo;
    price=std::move(moved_from).price; }else{std::cerr<<"Same object! No operation.\n";}
    }//move design
    Quote(const std::string&book,double sales_price):bookNo(book),price(sales_price){
        std::cout<<"Quote(const std::string&book,double sales_price)\n";
    }
    std::string isbn()const{return bookNo;}
    virtual double net_price(std::size_t n)const
    {return n*price;}
      virtual ~Quote(){std::cout<<"~Quote()\n";}
    private:
    std::string bookNo;
    protected:
    double price=0.0;
};
class Disc_quote:public Quote{
    public:
    Disc_quote():Quote(){std::cout<<"Disc_quote()\n";}
    Disc_quote(const std::string&book,double Sales_price):Quote(book,Sales_price)
    {std::cout<<"Disc_quote(const std::string&,double)\n";}
    Disc_quote(const Disc_quote&orig):Quote(orig.isbn(),orig.price)
    {std::cout<<"Disc_quote(const Disc_quote&)\n";}
    Disc_quote(Disc_quote&&moved_from):Quote(std::move(moved_from).isbn(),std::move(moved_from).price)
    {std::cout<<"Disc_quote(Disc_quote&&)\n";}
    Disc_quote& operator=(Disc_quote&& d)
    {
    std::cout<<"Disc_quote& operator=(Disc_quote&& d)\n";
    Quote::operator=(std::move(d));return *this;
    }
    Disc_quote& operator=(const Disc_quote&d)
    {
        std::cout<<"Disc_quote& operator=(const Disc_quote&d)\n";
        Quote::operator=(d);return *this;
    }

    double net_price(std::size_t n)const=0;
    ~Disc_quote(){std::cout<<"~Disc_quote()\n";}
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

int main()
{
    std::cout<<"line: "<<__LINE__<<std::endl;
    Quote *q;
      std::cout<<"line: "<<__LINE__<<std::endl;
    Bulk_quote ob1("yaju_senpai",114.514,13,0.8);
      std::cout<<"line: "<<__LINE__<<std::endl;
      Bulk_quote ob2;const Bulk_quote ob3("yaju_senpai",114.514,13,0.8);
        std::cout<<"line: "<<__LINE__<<std::endl;
        ob2=std::move(ob1);
          std::cout<<"line: "<<__LINE__<<std::endl;
          ob2=std::move(ob3);
            std::cout<<"line: "<<__LINE__<<std::endl;
    q=&ob1;
      std::cout<<"line: "<<__LINE__<<std::endl;
      ob2=ob3;
        std::cout<<"line: "<<__LINE__<<std::endl;
        ob2=ob1;
        std::cout<<"line: "<<__LINE__<<std::endl;
      
}

//result: 
/*
line: 83
line: 85
Quote(const std::string&book,double sales_price)
Disc_quote(const std::string&,double)
line: 87
Quote()
Disc_quote()
Quote(const std::string&book,double sales_price)
Disc_quote(const std::string&,double)
line: 89
Disc_quote& operator=(Disc_quote&& d)
Quote&operator=(Quote&&moved_from)
line: 91
Disc_quote& operator=(const Disc_quote&d)
Quote&operator=(const Quote&orig)
line: 93
line: 95
Disc_quote& operator=(const Disc_quote&d)
Quote&operator=(const Quote&orig)
line: 97
Disc_quote& operator=(const Disc_quote&d)
Quote&operator=(const Quote&orig)
line: 99
~Disc_quote()
~Quote()
~Disc_quote()
~Quote()
~Disc_quote()
~Quote()
*/