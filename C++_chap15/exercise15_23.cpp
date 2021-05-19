/*Overriding Overloaded functions*/
//As with any other function, a member function (virtual or otherwise)can be overloaded.
//If a derived class wants to make all the overloaded versions available through its type,
//then it must override all of them or none of them.
//Insetad of overriding every base-class version that it inherits, a derived class can provide a
//using declaration for the overloaded member.
//It can use the inherited definitions for the others.
//The normal rules for a using declaration inside a class apply to names of overloaded functions;
//every overloaded instance of the function in the base class must be accessible to the derived class.
// The access to the overloaded versions that are not otherwise by the derived class will be the
//access in effect at the point of the using declaration.
#include<iostream>
class Base4{
    public: virtual int fcn();
};

int Base4::fcn()
{std::cout<<"We have called Base4::fcn()\n";return 1;}
class D10:public Base4{
    public:
    D10()=default;
    //hides fcn in the base; this fcn is not virtual
    //D1 inherits the definition of Base::fcn()
    using Base4::fcn;
    int fcn(int){std::cout<<"We have called D10::fcn(int)\n";return 2;}//parameter differs from fcn in Base4
    virtual void f2(){std::cout<<"We have called D10::f2()\n";}//new virtual function that does not exist in Base
};
class D11:public D10{
    public:
    D11()=default;
    int fcn(int){std::cout<<"We have called D11::fcn(int)\n";return 3;}//nonvirtual function hides D10::fcn(int)
    int fcn()override final{std::cout<<"We have called D11::fcn()\n";return 4;}//overrides virtual fcn from Base
    virtual void f2()override final{std::cout<<"We have called D11::f2()\n";}//overrides virtual f2 from D10
};
int main()
{
    D10 Ob1;
    Ob1.fcn();//Base4::fcn()//If we comment the line24, we will get an error.
    //Because,we cannot access
    D11 Ob2;
    Ob2.fcn();//D11::fcn()//Otherwise,


    Base4 bobj1_;
D10 d1obj_; D11 d2obj_;
Base4 *bp1=&bobj1_,*bp2_=&d1obj_,*bp3_=&d2obj_;
bp1->fcn();//Base4::fcn()//virtual call
bp2_->fcn();//Base4::fcn()//virtual call
bp3_->fcn();//D11::fcn()//virtual call
D10 *d1p_=&d1obj_;D11 *d2p_=&d2obj_;
//bp2_->f2();//error: Base4 has no member named f2()
d1p_->f2();//D10::f2()
d2p_->f2();//D11::f2()
d2p_->D10::f2();//D10::f2()
//For completeness, let's look at calls to the nonvirtual function fcn(int):
Base4 *p1_y=&d2obj_;D10 *p2_y=&d2obj_; D11 *p3_y=&d2obj_;
//p1_y->fcn(42);//error: Base has no version of fcn that takes an int
p2_y->fcn(42);//statistically bound, call D10::fcn(int)
p3_y->fcn(42);//D11::fcn(int)
}
