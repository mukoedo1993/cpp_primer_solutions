//The noexcept specifier must appear on all of the delcarations and the corresponding
//definition of a function or on none of them.

/*violating the excpetion specifictation*/
/*
It is important to understand that the compiler does not check the noexcept
specification at compile time. In fact, the compiler is not permitted to 
reject a function with a noexcept specifier merely
*/
#include<stdexcept>
#include<iostream>
void recoup(int)noexcept
{
    std::cout<<"recoup()"<<std::endl;
}
void alloc(int)
{
  std::cout<<"alloc()"<<std::endl;
}

void f()
noexcept
{
throw std::exception();
}
void f1()
noexcept(false)
{
throw std::exception();
}

void f2()noexcept(noexcept(f1()))
{
    /*f2()has same noexcept specifier as f1()*/
}

class Base{
    public:
    virtual double f1(double)noexcept=0;//don't throw
    virtual int f2()noexcept(false)=0;//can throw
    virtual void f3()=0;//can throw
};
class D final:public Base{
    public:
     double f1(double)
    noexcept//If we comment this line, a looser throw will be detected and an error will be reported.
    override//error: Base::f1() promise not to throw
    {
        std::cout<<" virtual double f1(double) noexcept override;\n";
        return 3.4;
    }//don't throw
  int f2()noexcept(false)override//can throw
    {
        std::cout<<"  virtual int f2()noexcept(false)\n";
        return 3;
    }
   void f3()noexcept//ok: Derived f3 is more restrictive
    {
        std::cout<<" virtual void f3()noexcept\n";

    }
};


int main()
{
   //f();
   /*
terminate called after throwing an instance of 'std::exception'
  what():  std::exception
   */
  //The compiler in general cannot, and does not, verify exception specifications
  //at compile time. 



  //try{f();}catch(...){}
   /*
terminate called after throwing an instance of 'std::exception'
  what():  std::exception
   */
//Specifying that a function won't throw effectively promises the callers of the
//nonthrowing function that they will 

  try{f1();}catch(...){}//ok. 
   try{f2();}catch(...){}//ok. 

/*Exception specification and pointers, virtuals, and copy control*/
//Although the noexcept specifier is not part of a function's type, whether 
//a function has an exception specification afects the use of that function.

//both recoup and pf1 promise not to throw
void(*pf1)(int)noexcept=recoup;

//ok: recoup won't throw; it doesn't matter that pf2 might
void(*pf2)(int)=recoup;

pf1=alloc;//error: alloc might throw but pf1 said it wouldn't
pf2=alloc;//ok: both pf2 and alloc might throw

D d;
d.f3();//ok
//d.f1(3.);//error: looser throw specifier for ‘virtual double D::f1(double)’
}

/*
When the compiler synthesizes the copy-control members, it generates an exception
specification for the synthesized member. If all the corresponding operation for all
the members and base classes promise not to throw, then the synthesized member is noexcept.
If any function invoked by the synthesized member can throw, then the synthesized member
is noexcept(false). Moreover, if we do not provide an exception specification for a
destructor that we do define, the compiler synthesizes one for us. The compiler generates
the same specification as it would have generated had it synthesized the destructor for that class.
*/