/*KEY CONCEPT: Name lookup and inheritance*/
//Understaning how function calls are resolved is crucial to understanding inheritance in C++.
//Given the call p->mem()(or obj.mem())the following four steps happen:

//1: Determine the static type of p(or obj). Because we're calling a member, that type must be a class type.

//2: Look for mem in the class that corresponds to the static type of p(or obj). If mem is not found, look
//in the direct base class and continue up the chain of classes until mem is found or the last class is 
//searched. If mem is not found in the class or its enclosing base classes, then the call will not compile.

//3: Once mem is found, do normal type checking to see if this call is legal given the definition that
//was found.

//4: Assuming the call is legal, the compiler generates code, which varies depending on whether the
//call is virtual or not:
//If mem is virtual and the call is made through a reference or pointer, then the compiler generates
//code to determine at run time which version to run based on the dynamic type of the object.
//Otherwise, if the function is nonvirtual, or if the call is on an object(not a reference or pointer),
//the compiler generates a normal function call.
#include<iostream>

/*Part 1:*/
struct Base{
    int memfcn(){std::cout<<"Base::memfcn();\n";return 1;}
     int memfcn1(){std::cout<<"Base::memfcn1();\n";return 1;}
    
};
struct Derived:Base{
    
    int memfcn(int){std::cout<<"Derived::memfcn(int)\n";return 2;}
    private:
    int memfcn1(int){std::cout<<"Derived::memfcn1();\n";return 1;}
    
};

/*Part 2*/
//Virtual functions and scope ... Call a hidden virtual through the Base class... 
//We can know understand why virtual functions must have the same parameters list in the base
//and derived classes. If the base and derived members took arguments that differed from one another,
//there would be no way to call the derived version through a reference or pointer to the base class.
//e.g.:

class Base1{
    public:
    virtual int fcn();   
};
int Base1::fcn()
{
    std::cout<<"Base1::fcn()\n";return 13;
}
class D1:public Base1{
    public:
    //hides fcn in the base; this fcn is not virtual
    //D1 inherites the definition of Base::fcn
    int fcn(int){std::cout<<"D1::fcn(int):\n";return 5;}
    virtual void f2(){std::cout<<"D1::f2()\n";}
    virtual int yaju(int){std::cout<<"D1::yaju(int):\n";return 6;}
};

class D2:public D1{
    public:
    int fcn(int){std::cout<<"D2::fcn(int)\n";return 4;}
    int fcn(){std::cout<<"D2::fcn()\n";return 3;}
    void f2()final{std::cout<<"D2::f2()\n";}
    virtual int yaju(int)final{std::cout<<"D2::yaju(int):\n";return 7;}
};

int main()
{
    /*Part 1:*/
    Derived d; Base b;
    b.memfcn();//static type is Base, dynamic type is also Base. First,search Base, find out memfcn(),
    //get it!

    d.memfcn(18);//static type is Derived, dynamic type is same. First, search Derived, find out memfcn,
    //use it, get it!

    //d.memfcn();//error: both static and dynamic type is Derived. First, search the class Derived,
    //stop. And, then, call the memfcn within the Derived class, memfcn(int) hides memfcn(). Error.

    d.Base::memfcn();//ok: force the compiler to call the Base version of memfcn()
     
    //d.memfcn1();//error: inaccessible. iT means that we are searching the name, the private name
    //is also considered, even inaccessible outside the class.
     d.Base::memfcn1();//Base::memfcn1()
    /*Part 2*/
    //We must keep in mind that the virtual doesn't need to be overwritten unless we use =0 keyword.
    Base1 bobj; D1 d1obj;D2 d2obj;
    Base1 *bp1=&bobj;//bp1: dynamic type: Base1 static type: Base1
    Base1 *bp2=&d1obj;//bp2: dynamic type: D1 static type: Base1
    Base1 *bp3=&d2obj;//bp3 dynamic type: D2,static type Base1

    bp1->fcn();//static type check: stop at the Base1 class.
    // As soon as fcn() is virtual, Called dynamic type ,i.e., Base1::fcn(). All well done.
    bp2->fcn();//static type check: stop at the Base1 class. 
    //As soon as fcn() is virtual, Called dynamic type ,i.e., D1::fcn(), which inherits from Base
    bp3->fcn();//static type check: stop at the Base1 class. So, actually, Base1::fcn() is called.
    //As soon as fcn() is virtual, called dynamic type, i.e., D2::fcn(). D2::fcn() which
    //overrides Base::fcn() is called.

    D1 *d1p=&d1obj;//static type of d1p is D1, dynamic type of d1p is D1.
    D2 *d2p=&d2obj;//static type of d1p is D1, dynamic type of d1p is D2.
    //bp2->f2();//error: bp2's static type is Base1 which doesn't have a f2(). Error occurs.
    d1p->f2();//First ,search D1, we find a f2(). And then, as soon as the dynamic type is also
    //D1, we can safely call D1::f2()
    d2p->f2();//First, search D1, we find a f2(). And then, as soon as D1::f2()is virtual and we
    //call f2() through a pointer, we need to call the f2 within the dynamic type.
    //In other words, we call D2::f2() which overrides D1.
   
   Base1 *p1=&d2obj;//static type Base1, dynamic type D2
   D1 *p2=&d2obj;
   D2 *p3=&d2obj;
   //p1->fcn(42);//error: first, check the static type Base1, there is one function named fcn.  
   // So, we stops. But, this function is fcn() rather than fcn(int), so we get an error.

   p2->fcn(42);
   //check the static type, there is a fcn in D1 class. But, D1::fcn(int)is non_virtual.
   //So, we stop at here and call D1::fcn(int).
   
   p3->fcn(42);//check te static type, there is a fcn named fcn in D2 class. But, D2::fcn(int) is
   //nonvirtual. So, we stop at here and call D2::fcn(int). 

   p2->yaju(42);//check the static type, there is a yaju in D1 class. Also, there is a correct type.
   //i.e., D1::yaju(int) here. But, D1::yaju(int) is virtual and we call it through a pointer.
   //We need to consider its dynamic type. Its dynamic type is D2, so we call the D2::yaju actually.
}


//extra note: once virtual, it is always virtual in the derived class. But keyword virtual could be omitted then.
//override is helpful when we're stuck in debugging... but it's not compulsory...