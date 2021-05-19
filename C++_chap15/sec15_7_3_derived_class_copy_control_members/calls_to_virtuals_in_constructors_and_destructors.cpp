/*calls to virtuals in constructors and destructors*/
//As we've seen, the base-class part of a derived object is constructed first. While the base-class
//constructor is executing, the derived part of the object is uninitialized. Similarly, derived
//objects are destroyed in reverse order, so that when a base class destructor runs, the derived part has
//already been destroyed.
#include<iostream>
class base{
    public:
    base(){fcn();std::cout<<"base::base()\n";}
    virtual void fcn(){std::cout<<"base::fcn()\n";}
    virtual ~base(){fcn();std::cout<<"base::~base()\n";}
};
class D1:public base{
public:
      D1(){fcn();std::cout<<"D1::D1()\n";}
     virtual void fcn()override final{std::cout<<"D1::fcn()\n";}
     virtual ~D1(){fcn();std::cout<<"D1::~D1()\n";}
};
int main()
{
    D1 d;
    /*
    base::fcn()
base::base()
D1::fcn()
D1::D1()
    */
   std::cout<<"\n ....\n";
   base *b1=&d;b1->fcn();//D1::fcn()
    std::cout<<"\n ....\n";
    /*
    D1::fcn()
D1::~D1()
base::fcn()
base::~base()
    */
}
//caveat: If a constructor or destructor calls a virtual, the version that is run is the
//one corresponding to the type of the constructor or destructor itself.