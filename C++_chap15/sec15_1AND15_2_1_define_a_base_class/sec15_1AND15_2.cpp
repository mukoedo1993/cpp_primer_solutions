//OOP: an overview
//The key ideas in object-oriented programming are data abstraction
//, inheritance, and dynamic programming.

/*Inheritance*/
//CLasses related by inheritance form a hierarchy.
//A base class: as the root of the hierachy
//a derived class: inherit directly or indirectly 
//from a base class.
//The base class defines as virtual those functions it expects
//its derived classes to define for themselves.

#include<iostream>
class Quote{
          
    public: Quote()=default;
    Quote(const std::string&book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn()const{return bookNo;}
    //returns the total sales price for the specified number of items
    //derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n)const
    {return n*price;}
     //virtual
      ~Quote()=default;//dynamic binding for the destructor
    private:
    std::string bookNo;//ISBN number of this item
    protected:
    double price=0.0;//normal, undiscounted price
};


//Because Bulk_quote use public in its derivation list, we 
//can use objects of type Bulk_quote as if they were Quote objects.
class Bulk_quote :public Quote{//Bulk_quote inherits from Quote
 public:
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t n)const override{return double(0.01*(100.0-n))*price;}
}; 
//A derived class may include the vritual keyword on these functions
//but is not required to do so. 
//The new standard lets a derived class explicitly note that it
//intends a member function to override a virtual that it inherits.
//It does so by specifying override after its parameter list.


/*Dynamic Binding*/
//Through dynamic binding, we can use the same code to process objects of either type
//Quote or bulk_quote interchangably. For example, the following function prints the 
//total price for purchasing the given number of copies of a given book:

//calculate and print the price for the given number of copies, applying any discounts.
auto print_total(std::ostream &os,const Quote &item,size_t n)->double
{
    //depending on the type of the object bound to the item parameter
    //calls either Quote::net_price or Bulk_quote::net_price
    double ret=item.net_price(n);
    os<<"ISBN: "<<item.isbn()//calls Quote::isbn
    <<"# sold: "<<n<<" total due:"<<ret<<std::endl;
    return ret;
}
//Its functions are simple: it prints the results of calling isbn and net_price on its
//parameter and returns calculated by the call to net_price.

//Because item parameter is a reference to Quote, we can call this function on either 
//a Quote object or a Bulk_price object.

//Because net_price is a virtual function, and because print_total calls net_price through
//a reference, the version of net_price that is run will depende on the type of the object that
//we pass to print_total:


//The base class specifies that a member function should be dynamically bound by preceding
//its declaration with the keyword virtual.
//When we call a virtual function through a pointer or reference, the call will be dynamically
//bound. 
//Depending on the type of the object to which the reference or pointer is bound, either the version
//of the base class or in one of its derived classes will be executed.

//Any nonstatic member function, other than a constructor, may be virtual.
//The virtual keyword appears only on the declaration inside the class and may not be used
//on a function definition that appears outside the class body.

//Member functions that are not declared as virtual are resolved at compile time, not run time.
//e.g.1: isbn member

//A derived class may access the public members of its base class but may not access
//to those same members by other users. We specify such members after a protected
//class specifier.
int main()
{
    //basic has type Quote; bulk has type Bulk_quote.
    Quote basic("str1",13.4); Bulk_quote bulk,bulk1(13.4);
    print_total(std::cout, basic, 20);//calls Quote version of net_price
    print_total(std::cout,bulk,20);//calls Bulk_quote version of net_price
    print_total(std::cout,bulk1,20);
}