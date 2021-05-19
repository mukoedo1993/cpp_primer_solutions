#include<iostream>
#include<utility>
#include<stdexcept>
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
 std::pair<std::size_t,double>discount_policy()const
 {auto quantity=min_qty;
     return std::make_pair(quantity,discount);}
 Bulk_quote(const std::string &book,double p,std::size_t qty,double disc):Quote(book,p),min_qty(qty),
 discount(disc){}//it passes its first two parameters(representing the isbn and price)to the quote constructor.
 Bulk_quote()=default;
  Bulk_quote(double sales_price){price=sales_price;}
 double net_price(std::size_t n)const override;
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

/*Name Collisions and Inheritance*/
//Like any other scope, a derived class can reuse a name defined in one of its direct
//or indirect base classes. As usual, names defined in an inner scope(e.g. a derived class)hides
//use of that name in the outer scope(e.g. a base class)
struct Base{
    Base():mem(0){}
    protected:
    int mem;
};

struct Derived:Base{
    int get_base_mem(){return Base::mem;}//The scope operator overrides the normal lookup
    //and directs the compiler to look for mem starting in the scope of class Base. If we
    //ran the code above with this version of Derived, the result of d.get_mem() would be 0.
   //Caveat: As a user of Derived, we cannot access Base::mem directly, as soon as Base::mem is
   //a protected member of the Base class.

    Derived(int i):mem(i){}//initializes Derived::mem to i
                           //Base::mem is default initialized
                           int get_mem(){return mem;}//return Derived::mem
    protected:
    int mem;//hides mem in the base
};

struct Base1{
    
    int memfcn(){return 13;}
    protected:
    int memfcn1(){return 189;}
};

struct Derived1:public Base1{
    using Base1::memfcn1;//But, the user needs to access Derived1 object at first, then access
    //the Base1::memfcn1 which is a protected member and so that it remains inaccessible.
    int memfcn(int){return 17;}//hides memfcn in the Base1
};

struct Derived2:private Base1{
    //We cannot access Base1 through Derived2 at first, as soon as Base1 is inherited in private.
};

struct Base3{void fcn(){std::cout<<"\nheheda!\n";}};
struct Derive4:protected Base3{};
struct Derive5: public Derive4{void fcn1(){fcn();}};
struct Derive6: public Derive4{void fcn1(){fcn();}};






/*Virtual functions and scope*/

//If the base and derived members took arguments that differed from one another, there
//would be no way to call the derived version through a reference or pointer to the base class. e.g.:
class Base4{
    public: virtual int fcn();
};
int Base4::fcn()
{std::cout<<"We have called Base4:fcn()\n";return 1;}
class D10:public Base4{
    public:
    D10()=default;
    //hides fcn in the base; this fcn is not virtual
    //D1 inherits the definition of Base::fcn()
    int fcn(int){std::cout<<"We have called D10:fcn(int)\n";return 2;}//parameter differs from fcn in Base4
    virtual void f2(){std::cout<<"We have called D10::f2()\n";}//new virtual function that does not exist in Base
};
class D11:public D10{
    public:
    D11()=default;
    int fcn(int){std::cout<<"We have called D11:fcn(int)\n";return 3;}//nonvirtual function hides D10::fcn(int)
    int fcn(){std::cout<<"We have called D11:fcn()\n";return 4;}//overrides virtual fcn from Base
    virtual void f2()override{std::cout<<"We have called D11::f2()\n";}//overrides virtual f2 from D10
};
int main()
{
    //We can use discount_policy only through an object, pointer, or reference of type Disc_quote
    //or of a class derived from Disc_quote:
    Bulk_quote bulk;
    std::cout<<bulk.isbn();
/*Name lookup happens at compile time*/
//We can use dicount_policy only through a project, pointer, or reference of type Disc_quote or of
//a class derived from Disc_quote:
Bulk_quote *bulkP=&bulk;//static and dynamic types are the same
Quote *itemP=&bulk;//static and dynamic types differ
bulkP->discount_policy();//ok: bulkP has type Bulk_quote*
//itemP->discount_policy();//error: itemP has type Quote*
//Even though bulk has a member named discount_policy, that member is not visible through itemP.
//The type of itemP is a pointer to QUote, which means that the search for discount_policy starts
//in class Quote. The QUote class member named discount_policy, so we cannot call that member on
//an object, reference or pointer of type Quote.

Derived d(42);
std::cout<<d.get_mem()<<std::endl;//42
//std::cout<<d.Base::mem<<std::endl;//error: Because Base::mem is protected, user of d cannot use this mem.
std::cout<<d.get_base_mem()<<std::endl;//0


Derived1 d1;Base1 b1;
std::cout<<b1.memfcn()<<std::endl;//13//calls Base1::memfcn
std::cout<<d1.memfcn(10)<<std::endl;//17//calls Derived1::memfcn(int)
//std::cout<<d1.memfcn()<<std::endl;//error: memfcn with no arguments is hidden

std::cout<<d1.Base1::memfcn()<<std::endl;//13//ok: calls Base1::memfcn()
//First, d1 access the subobject Base1. It is OK as soon as it inherits in a public way. 
//Then, we need to access Base1 through the subobject. Also OK.
std::cout<<d1.memfcn1()<<std::endl;//189
Derived2 Dd2;
//std::cout<<Dd2.memfcn()<<std::endl;//error: inaccessible

Derive5 d5;Derive6 d6;
//d5.fcn();
d5.fcn1();//heheda!
d6.fcn1();//heheda!

/*Calling a Hidden Virtual through the Base Class*/
//The firest three call are all made through pointers to the base class. Because fcn
//is virtual, the compiler generates code to decide at run time which version to call.

Base4 bobj1_;
D10 d1obj_; D11 d2obj_;
Base4 *bp1=&bobj1_,*bp2_=&d1obj_,*bp3_=&d2obj_;
bp1->fcn();//Base4::fcn()//virtual call
bp2_->fcn();//Base4::fcn()//virtual call
bp3_->fcn();//D11::fcn()//virtual call
D10 *d1p_=&d1obj_;D11 *d2p_=&d2obj_;
//bp2_->f2();//error: Base4 has no member named f2
d1p_->f2();//D10::f2()
d2p_->f2();//D11::f2()
d2p_->D10::f2();//D10::f2()
//For completeness, let's look at calls to the nonvirtual function fcn(int):
Base4 *p1_y=&d2obj_;D10 *p2_y=&d2obj_; D11 *p3_y=&d2obj_;
//p1_y->fcn(42);//error: Base has no version of fcn that takes an int
p2_y->fcn(42);//statistically bound, call D10::fcn(int)
p3_y->fcn(42);//statistically bound, call D11::fcn(int)
//In each call the pointer happens to point to an object of type D2.
//However, the dynamic type doesn't matter when we call a nonvirtual function.
//The version that is called depends only on the static type of the pointer.


}