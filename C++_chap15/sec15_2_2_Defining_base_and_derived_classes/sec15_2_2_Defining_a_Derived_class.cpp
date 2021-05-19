/*Defining a derived class*/
//class derivation list:
//When the derivation is public, the public members of the base class become
//part of the interface of the derived class as well.

//Most classes inherit directly from only one base class. This form of inheritance, known
//as "single inheritance," forms the topic of this chapter.

//A derived object contains multiple parts:
//1: a subobject containing the (nonstatic) members defined in the derived class itself.
//2: subobjects corresponding to each base class from which the derived class inherits.

#include<iostream>

/*Declarations of Derived classes*/
//class Bulk_quote :public Quote;//error: derivation list can't appear here.
class Bulk_quote;//ok: right way to declare a derived class

/*classes used as a base class*/
//A class must be defined, not just declared, before we can use it as a base class.
/*
class Quote1;//declard but not defined
//error: Quote1 must be defined
class Bulk_quote1:public Quote1{}//vs code: incomplete type is not allowed.
*/

//A base class can itself be a derived class
class Base2{/*...*/};
class D1:public Base2{/*...*/};
class D2: public D1{/*...*/};
//Note: in this hierachy, Base2 is a direct base to D1 and an indirect base to D2. A direct base 
//class is named in the derivation list. An indirect base is one that a derived class inherits through
//its direct base class.
//...inheritance chain...
//Effectively, the most derived object contains a subobject for its direct base and for each of its
//indirect bases.

/*preventing inheritance*/
//using the word final:
class NoDerived final{/*...*/};
class Base3{/*...*/};
class Last final: Base3{/*...*/};
//Last is final, we cannot inherit from Last
//class Bad:NoDerived{/*...*/};//error: Noderived is final
//class Bad2:Last{/*...*/};//error: Last is final

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
/*Inheritance and static Members*/
//If a base class defines a static member, there is only one such member defined for the entire hiearchy.
//Regardless of the number of classes derived from a base class, there exists a single instance of each
//static member.
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
//Static members obey normal access control. If the member is private in the base class, 
//then derived classes have no access to it. Assuming the member is accessible, we can use a static member 
//through either the base or derived:
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
    Quote item;//object of base type
    Bulk_quote bulk;//object of derived type
    Quote *p=&item;// p points a Quote object
    p=&bulk;//p points to the Quote part of bulk
    Quote &r=bulk;//r bound to the Quote part of bulk

    //This conversion is often referred to as the derived-to-base conversion. As with any
    //other conversion, the compiler will apply the derived-to-base conversion implicitly.

    //The fact means that derived-to-base conversion is implicit means that we can use an object
    //of derived type or a reference to a derived type when a reference to the base type is required.

    //Similarly, we can use a pointer to a derived type where a pointer to the base type is required.
    Derived drv1,drv2;
    drv1.f_(drv2);//It prints We call Base::statmem() once! four times.

}