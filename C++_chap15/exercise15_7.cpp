#include<iostream>
//exericse 15_7: implements a limited discount strategy:
class Bulk_quote;
class Base2{/*...*/};
class D1:public Base2{/*...*/};
class D2: public D1{/*...*/};
class NoDerived final{/*...*/};
class Base3{/*...*/};
class Last final: Base3{/*...*/};
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

class Bulk_quote :public Quote{
 public:
 Bulk_quote(const std::string &book,double p,std::size_t qty1,std::size_t qty2,double disc)
 :Quote(book,p),min_qty(qty1),max_qty(qty2),
 discount(disc){}
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t)const override;
 private: std::size_t min_qty =0;
 std::size_t max_qty=130;
 double discount=0.0;
}; 

double Bulk_quote::net_price(std::size_t cnt)const 
{
    if(cnt>=min_qty&&cnt<=max_qty)
    return cnt*(1-discount)*price;
    else if(cnt>max_qty)
    return (max_qty*(1-discount)*price+(cnt-max_qty)*price);
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
class Base{
    public:
    static void statmem();
};
class Derived:public Base{
    public:
    void f_(const Derived&);
};
void Base::statmem()
{
    std::cout<<"We call Base::statmem() once!\n";
}
void Derived::f_(const Derived &derived_obj)
{
    Base::statmem();//ok: Base defines statmem
    Derived::statmem();//ok: Derived inherits statmem
    //ok: derived objects can be used to access static from base
    derived_obj.statmem();//accessed through a Derived object
    statmem();//accessed through this object
}
int main()
{
    Bulk_quote item("nineteen_eighty_four",20.0,100,200,0.8);
    std::cout<<item.net_price(18)<<std::endl;//360 Original price. correct.
    std::cout<<item.net_price(150)<<std::endl;//150*(1-0.8)==600. correct.
    std::cout<<item.net_price(300)<<std::endl;//200*(1-0.8)*20+(300-200)*20==2800. correct.
}