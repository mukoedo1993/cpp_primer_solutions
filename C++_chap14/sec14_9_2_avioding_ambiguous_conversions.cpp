//If a class has one or more conversions, it is important to ensure that there
//is only one way to convert form the class type to the traget type.
#include<iostream>
struct B;
struct A{
    A()=default;
    A(const B&){}//converts a B to an A
};
struct B{
  B()=default;
operator A() const{A a1;return a1;}
};
  A f(const A&){A a1;return a1;}

  //Ambiguities and Multiple conversions to built-in types
  struct A1{
A1(int =0){}
A1(double){}
operator int()const;//usually a bad idea to have two
operator double()const;//conversions to arithmetic types
//other members
  };

  void f2(long double){}
  
//overloaded functions and converting constructors
//Chossing among multiple conversions 
//is further complicated when we call an overloaded function.
//If two or more conversions provide a viable match, then the conversions are considered
//equally good.
struct C{
  C(int){}
  //other members
};
struct D{
D(int);
};//other members

void manip(const C&){}
void manip(const D&){}

/*Overloaded Functions and user-defined conversion*/
//In a call to an overloaded function, if two (or more)user-defined conversions provide
//a viable match, the conversions are considered equally good.

struct E{
  E(double){}

};

void manip2(const C&){}
void manip2(const E&){}
int main()
{
 
   B b;
  // A a=f(b);//error ambiguous: f(B::operator A())
     // or f(A::A(const B&))

     //If we want to make this call, we have to explicitly call the conversion operator or the 
     //constructor:
     A a1=f(b.operator A());//ok: use B's conversion operator
     A a2=f(A(b));//ok: use A's constructor

     A1 a3;
     //f2(A1);//error: ambiguous f(A::operator int())
     //           or f(A::operator double())
     long lg;
     //A1 a4(lg);//error: ambiguous A::A(int) or A::A(double)
     short s=42;
     //promoting short to int is better than converting short to double
     A1 a4(s);//use A1::A1(int)

     //manip(10);//error:ambiguous manip(C(10))or manip (D(10))
     manip(C(10));//ok: call manio(const C&)
     
     //manip2(10);//error ambiguous: manip2(C(10))or manip2(E(double(10)))
     //Because calls to the oberloaded functions require different user-defined conversions
     //from one another, this call is ambiguous.

     //The ranking matter only if viable functions require the same user-defined conversion,
     //Otherwise, then the call can be ambiguous.

}