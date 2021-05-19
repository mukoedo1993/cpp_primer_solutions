//A dynamic_cast has the following form:
//dynamic_cast<type*>(e);
//dynamic_cast<type&>(e);
//dynamic_cast<type&&>(e);

/*
The cast succeeds if the target type is a public base class of the type of the object 
denoted by e or if the target type is the same as or the const version of that type.

Otherwise, the static type of e must have at least one virtual function and that type is
the same as the target type, or contains a subobject of the target type, the cast succeeds.

a dynamic_cast fails by returning 0; a dynamic_cast to a reference_type fails by throwing
an exception of type bad_cast.
*/
#include<iostream>
struct Base{
    Base(){}
    virtual void fcn(){}
   virtual ~Base(){}
};
struct Derived:Base{
    Derived(){}
    void fcn()override final{}
};
   /*Reference-type dynamic_casts*/
   void f(const Base&b)
   {
      try{const Derived&d=dynamic_cast<const Derived&>(b);}
      catch(const std::bad_cast&err){
          std::cerr<<err.what()<<'\n';
      }
   }
int main()
{
       Derived d1;
       Base b1,b2;
       const Base b3;const Base& b4=d1;
       Base *bp=&d1;
       if(Derived *dp=dynamic_cast<Derived*>(bp)){
             //use the Derived object to which dp points.
       }
       else
       {//bp points at a Base object
          std::cerr<<"Bad cast!\n";
       }//use the Base object to which bp points
     std::cout<<__LINE__<<std::endl;
    f(b1);//std::bad_cast
    std::cout<<__LINE__<<std::endl;
    f(b2);//std::bad_cast
    std::cout<<__LINE__<<std::endl;
    f(b3);//std::bad_cast
    std::cout<<__LINE__<<std::endl;
    f(b4);//OK

       
}