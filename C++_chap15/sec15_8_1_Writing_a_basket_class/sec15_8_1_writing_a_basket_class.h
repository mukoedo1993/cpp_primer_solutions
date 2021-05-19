#pragma once
#ifndef BASKET_CLASS_H
#define BASKET_CLASS_H
#include<iostream>
#include<set>
#include<memory>

class Quote{
          
    public: Quote()=default;
    //virtual functions to return a dynamically allocated copy of itself
    //these members use reference qualifiers
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
    //depending on the type of the object bound to the item parameter
    //calls either Quote::net_price or Bulk_quote::net_price
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
    //We need to use reference and pointers rather than objects directly when we are dealing with
    //oject-oreinted programming.

    //basket uses synthesized defualt constructor and copy-control members
    void add_item(const std::shared_ptr<Quote>&sale)
    {items.insert(sale);}

    void add_item(const Quote&sale)
    {items.insert(std::shared_ptr<Quote>(sale.clone()));}

      void add_item(Quote&&sale)
    {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}
    //Our clone function is also virtual. Whether the Quote or Bulk_quote function is run,
    //depends (as usual)on the dynamic type of sale. Regardless of whethe rwe copy or move data,
    //clone returns a pointer to a newly allocated object, of its own type. We bind a shared_ptr
    // to that object and call insert toa dd these newly allocated object to items.

    //Note that because shared_ptr supports the derive-to-base conversion, we can bind a 
    //shared_ptr<Quote> to a Bulk_quote*
    
     void add_item(std::shared_ptr<Quote>&&sale)
    {items.insert(std::move(sale));}
    //prints the total price for each book and the overall total for all items in the blanket
    double total_receipt(std::ostream&)const;
    
    /*double print_all_prices(std::ostream&os)const{}*/
    private:
    //function to compare shared_ptrs needed by the multiset member
    static bool compare(const std::shared_ptr<Quote>&lhs,const std::shared_ptr<Quote>&rhs)
    {return lhs->isbn()<rhs->isbn();}
    //multiset to hold multiple quotes, ordered by the compare member
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*>items{compare};
};

/*Defining the Members of Basket*/
//The basket class defines only two operations. 1st:
double Basket::total_receipt(std::ostream&os)const
{
    double sum=0.0;//holding the running total
    //iter referes to the first element in a batch of elements with the same ISBN
    //upper_bound returns an iterator to the element just past the end of that batch
    for(auto iter=items.cbegin();
    iter!=items.cend();iter=items.upper_bound(*iter)){
    //We know there's at least one element with this key in the Basket
    //print the line item for this book
    sum+=print_total(os,**iter,items.count(*iter));
    //multiset::count
    //http://www.cplusplus.com/reference/set/multiset/count/
    }

    //**iter is a Quote object (or an object of a type derived from Quote).

    os<<"Total Sale: "<<sum<<std::endl;//print the final overall total
    return sum;
}



#endif