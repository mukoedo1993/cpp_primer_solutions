//We can bind a reference (or pointer) to a base-class type ti a derived object.
//When we use a reference(or pointer)to a base-class type, we don't know the actual type of the object
//to which the pointer or reference is bound. The object can be an obje t of the base class or it
//can be an object of a derived class.

/*Static Type and Dynamic Type*/
//When we use types related by inheritance, we often need to distinguish between the
//1: The static type of a variable is always known at compile time--it is the type with which
//a variable is declared or that an expression yields.
//2: The dynamic type is the type of the object in memory that the variable or expression represents.
//3:The dynamic type may not be known until run time.

//e.g: 
//double ret=item.net_price(n);
//The static type of item is Quote&. The dynamic type of item is Bulk_quote& or Quote&. 




#include<iostream>
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

class yaju{};
class toya:public yaju{};//The class Toya inherits from Yaju.


int main()
{
    /*There is no implicit conversion from base to derived*/
    //

    Quote base;
    Bulk_quote bulk1;
   
    //Bulk_quote *bulkp=&base;//error: can't convert base to derived
    //Bulk_quote &bulkRef=base;//error: can't convert base to derived
     Quote *itemP=&bulk1;//ok: dynamic type is Bulk_quote
     //Bulk_quote *bulkP=itemP;//error: can't convert base to derived

     //The compiler has no way to know(at compile time) that a specific conversion
     //will be safe at run time.
     
     //If the base class has one or more virtual functions, we can use a dynamic_cast to request a conversion 
     //that is checked at run time.

     //Otherwise, in those cases when we know that the conversion from base to derived is safe, we can
     //use static_cats to override the compiler.
     //For example:

     toya onnb;
       yaju onna=static_cast<yaju>(onnb);//a safe example

       Bulk_quote *bulk2=&bulk1;
       if(Quote *itemp2=dynamic_cast<Quote*>(bulk2))
       {std::cout<<"iine!\n";}//The dynamic_cast works smoothly.
       else
       {
          std::cout<<"kimoi!\n";
       }

       /*And no conversion between objects*/
       //The automatic derived-to-base conversion applies only for conversions to a reference
       //or pointer type. There is no such conversion from a derived-class type to the base-class
       //type. Nevertheless, it is often possible to convert an object of a derived class to its base-class
       //type.
       
       //When we initialize or assign an object of a class type, we are actually calling a function.
       //When we initialize, we're calling a constructor. When we assign, we are calling an assignment operator.
       
       //Becuase these members take references, the derived-to-base conversion lets us pass a derived object
       //to a base-class copy-move operation...

       Bulk_quote bulk10;//object of derived type
       Quote item10(bulk10);//uses the Quote::Quote(const Quote&)constructor
       item10=bulk10;//calls Quote::operator=(const Quote&)
       //When item10 is constructed, the Quote copy constructor is run. That constructor knows only
       //about the bookNo and price members.
       //It copies those members from the Quote part of bulk and ignores the members that are part of 
       //the Bulk_quote portion of bulk. Similary for the assignment of bulk to item; only the Quote part
       //of bulk is assigned to item.

       
       /*slice down*/
       //Because the Bulk_quote part is ignored, we say that the Bulk_quote portion of bulk is sliced down.

}