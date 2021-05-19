#include<iostream>
//That is, when a call is made through a reference or pointer to base, the default arguments will
//be those defined in the base class.
//sec15_3: virtual functions page 607
struct base{
    base()=default;
    virtual int fcn(int i,int j=7){std::cout<<i<<"!"<<j<<std::endl;return i+j;}
   
};

struct D1:base{
   D1()=default;
   virtual int fcn(int i,int j=13){std::cout<<i<<"?"<<j<<std::endl;return i+j;}
};

int main()
{
     D1 dobj1;
    base bs1,*bs2=&bs1,*bs3=&dobj1;
    dobj1.fcn(3);//only static type is considered as soon as we call it directly through an object. Trivial case.

    bs3->fcn(4);//static type: base. We search the base, find the fcn, and the callable fcn(int). 
    //We find that it is virtual and we call it through a pointer, so we need to consider its
    //dynamic type. Its dynamic type is D1. We find that in D1 fcn(int) is overriden, so we call the overriden
    //version.
    //But, subtly, we need to notice that the default argument uses the one in the base class.
    //so, we print 4?7 rather than 4?13
 
  
  

}