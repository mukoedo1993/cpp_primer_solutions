
#include<iostream>
class Quote{
          
    public: Quote()=default;
    Quote(const std::string&book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn()const{return bookNo;}
    virtual double net_price(std::size_t n)const
    {return n*price;}
      ~Quote()=default;
      virtual void debug()
      {
          std::cout<<"bookNo: "<<bookNo<<"\nprice: "<<price<<std::endl;
      }
    private:
    std::string bookNo;
    protected:
    double price=0.0;
};

class Bulk_quote :public Quote{
 public:
 Bulk_quote(const std::string &book,double p,std::size_t qty,double disc):Quote(book,p),min_qty(qty),
 discount(disc){}//it passes its first two parameters(representing the isbn and price)to the quote constructor.
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t n)const override;
 auto debug()->void override{std::cout<<"min_qty: "<<min_qty<<"\ndiscount: "<<discount<<"\nprice: "<<price;}
 private: std::size_t min_qty =0;
 double discount=0.0;
}; 

/*Using members of the base class from the derived class*/
//A derived class may access the public and protected members of its base class
//if the specified number of items are purchased, use the discount price.
auto Bulk_quote::net_price(std::size_t cnt)const ->double
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

//virtual function in a derived class:
//A derived-class function that overrides an inherited virtual function must have exactly the same
//parameter type(s) as the base-class function that it overrides.
//One exception: if D derives from B, then return type B* for B is OK for D* for D.
struct B{
    virtual auto f1(int)const->void
    {std::cout<<"B::f1(int)\n";}
    virtual auto f2()->void
    {std::cout<<"B::f2()\n";}
    auto f3()->void
    {std::cout<<"B::f3()\n";}
};

struct D1:B{
    void f1(int)const override{std::cout<<"D1::f1(int)\n";}//only a virtual function can be overriden.
    //void f2(int)override{}//error: B has no f2(int) function
    //void f3() override{}//error: f3 not virtual
    //void f4()override{}//error: B doesn't have a function named f4
};

struct D2:B{
    //inherits f2() and f3() from B and overrides f1(int)
     void f1(int)const final{}//subsequent classes cannot override f1(int)
};
struct D3:D2{
    void f2(){std::cout<<"D3::f2()\n";}//ok: overrides f2 inherited from the indirect base, B
    //void f1(int)const{std::cout<<"f1(int):\n";}//eroror: De declared f2 as final
};

//virtual functions and default arguments
//always use the default arguments in the base class, even if actually the derived-class version is 
//running.


int main()
{
    Quote base("o-201-82470-1",50);
    std::cout<<"\n\n";
    Bulk_quote derived("0-201-82470-1",50,5,.19);
      std::cout<<"\n\n";
    base.debug();
      std::cout<<"\n\n";
    derived.debug();
}