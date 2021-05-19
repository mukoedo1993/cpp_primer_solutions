#include<iostream>
//sec 15.7.2: 
//The synthesized copy-control members in a base or a derived class execute like any
//other synthesized constructor, assignment operator, or destructor: They memberwise
//initialize, assign, or destroy the members of the class itself. In addition, these synthesized
//members initialize, assign, or destroy the direct base part of an object by using the corresponding
//operation from the base class.

//The synthesized Bulk_quote default constructor runs the Disc_Quote default constructor runs the 
//Disc_quote default destructor, which in turn runs the Quote default constructor.
//The Quote default constructor initializes the bookNo member to the empty string and uses
//the in-class initializer to initialize price to zero.
//When the Quote constructor finishes, the Disc_quote constructor continues, which uses the in-class
//initializers to initialize qty and discount.
//Similarly, the synthesized Bulk_quote copy constructor uses the (synthesized) Disc_quote copy
//constructor, which uses (synthesized)Quote copy constructor. The Quote copy constructor copies the 
//bookNo and price members; and the Disc_quote copy constructor copies the qty and discount members.
//It is worth noting that it doesn't matter whether the base-class member is itself synthesized (as 
//in the case in our Quote hierarchy) or has a user-provided definition. All that matters is that the
//corresponding member is accessible and that it is not a deleted function.

//Each of our Quote classes use the synthesized destructor. The derived classes do so implicitly, whereas
//the Quote classes use the synthesized destructor. The derived classes does so explicitly by defining
//its virtual destructor as default. The synthesized destructor is empty and its implicit destruction parts
//destroys the members of the class. In addition to destroying its own members, the destruction phase of a
//destructor in a derived class also destroys its direct base. That destructor in turn invokes the destructor
//from its own direct base, if any. And, so on up to the root of the hierachy.

//As we've seen, Quote does not have synthesized move operations because it defines a destructor. The syntheszied
//copy operations will be used whenever we move a Quote object. As we're about to see, the fact that Quote
//does not have move operations means that its derived classes don't either.

/*Base classes and deleted copy control in the derived*/
//If the default constructor, copy constructor, copy-assignment operator, or destructor in the base class
//is deleted or inaccessible, then the corresponding member in the derived class is defined as deleted, becaause
//the compiler can't use the base-class member to construct, assign, or destroy the base-class part of the object.
//If the base class has an inacessible or deleted destructor, then the synthesized default and copy constructors 
//in the derived classes are defined as deleted, because there is no way to destroy the base part of the derived
//object. 
//As usual, the compiler will not synthesize a deleted move operation. If we use =default to request a move 
//operation, it will be a deleted function in the derived if the corresponding operation in the base is deleted
//or inaccessible, because the base class part cannot be moved. The move constructor will also be deleted
//if the base class destructor is deleted or inaccessible.

class B{
    public:
    B()=default;
    /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    //Attention! There is a bug on B::B(). We must explicitly requires a default constructor, by
    //using the keyword default. Otherwise, it will be treated as delete.





    B(const B&)=delete;
    //other members, not including a move constructor
    //virtual ~B()=default;
};

class D:public B{
    //no constructors
};



/*Move Operations and Inheritance*/
//Because lack of a move operation in a base class suppresses synthesized move for its derived classes,
//base classes ordinarily should define the move operations if it is sensible to do so. Our Quote class can
//use the synthesized versions. However, Quote must define these members explicitly. Once it defines its
//move operations, it must also explicitly define the copy versions as well.

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
    Disc_quote()=default;
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
    B b;
    //D d;//ok: D's synthesized default constructor uses B's default constructor
    //D d2(d);//error: D's synthesized copy constructor is deleted
    //D d3(std::move(d));//error: implicitly uses D's deleted copy constructor
}