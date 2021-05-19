//Virtual functions
//C++ dynamic binding happens when a virtual member function is called through
//a reference or pointer to a base-class type. Because we don't know which version of
//a function is called until run time, virtual function must always be defined.




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

class Bulk_quote :public Quote{
 public:
 Bulk_quote(const std::string &book,double p,std::size_t qty,double disc):Quote(book,p),min_qty(qty),
 discount(disc){}//it passes its first two parameters(representing the isbn and price)to the quote constructor.
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t n)const override;
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
    /*Calls to virtual function may be resolved at run time*/
    //As an example, consider print_total function. That function calls net_price on its parameter named item.
    //which has type Quote&. Because item is a reference, and because net_price is virtual, the version of
    //net_price that is called depends at run time on the actual(dynamic) type of the argument bound to item:

    Quote base("o-201-82470-1",50);//ISBN: o-201-82470-1# sold: 10 total due:500
    print_total(std::cout,base,10);//calls Quote::net_price//ISBN: 0-201-82470-1# sold: 10 total due:405
    Bulk_quote derived("0-201-82470-1",50,5,.19);
    print_total(std::cout,derived,10);//calls Bulk_quote::net_price

    //It is crucial to understand that dynamic binding happens only when a virtual function is called through a pointer
    //or a reference:
    
    base=derived;//copy the Quote part of derived into base
    base.net_price(20);//calls Quote::net_price
    //When we call a virtual function on an expression that has a plain--nonreference and nonpointer--
    //type, that call is bound at compile time. 
    //e.g.1: when we call net_price on base, it is obvious we are calling Quote::net_price



    /*Circumventing the Virtual Mechanism*/
//In some cases, we want to prevent dynamic binding of a call to a virtual function. We want to force
//the call to use a particular version of that virtual. We can use the scope operator to do so. For example,
//this code:
Quote base1("o-201-82470-1",20),*baseP1=&base1;
    Bulk_quote derived1("0-201-82470-1",20,30,.19),*derived2=&derived1;
    double undiscounted=baseP1->Quote::net_price(42);
    double undiscounted1=derived2->Quote::net_price(42);
    double undiscounted2=derived2->net_price(42);
    std::cout<<"undiscounted is: "<<undiscounted<<std::endl;//840//Quote::net_price
    std::cout<<"undiscounted1 is: "<<undiscounted1<<std::endl;//840//Quote::net_price
    std::cout<<"undiscounted2 is: "<<undiscounted2<<std::endl;//680.4 //we called the Bulk_quote::net_price here.

    //WHen we wish to circumvent the virtual mechanism?
    //The most common reason: a derived-class virtual function calls the version from the base class.
    //In such cases, the base-class version might do work common to all types common in the hirearchy.
    //The version defined-> in the derived class->do whatever additional work is particular to their own type.

}