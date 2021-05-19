#include<typeinfo>
#include<iostream>
class Base{
    public:
    Base():j(0){}
    Base(int j1):j(j1){}
    private:
    friend bool operator==(const Base&,const Base&);
    public:
    //interface members for Base

   virtual int print()const&
    {return j;}
    protected:
    virtual bool equal(const Base&)const;
    //data and other implementation members of Base
    int j;
};
class Derived: public Base{
    public:
    Derived():Base(),k(3){}
    Derived(int j1,int k1):Base(j1),k(k1){}
     int print()const& override final
     {return j;}
    //other interface members for Derived
    protected:
    bool equal(const Base&)const;
    //data an dother implemenation members of Derived
    int k;
};
//A type sensitive Equality Operator
//Next let's look at how we might define the overall equality operator:
bool operator==(const Base&lhs, const Base&rhs)
{
    //return false if typeids are different, otherwise makes a virtual call to equal
    return (typeid(lhs)==typeid(rhs)&&lhs.equal(rhs));
}

/*The virtual equal functions*/
bool Derived::equal(const Base&rhs)const
{
    std::cout<<"Derived::equal(const Base&rhs)const\n";
    try{
    //we know the types are equal, so the cast won't throw
     Derived r1=dynamic_cast<const Derived&>(rhs);
    }catch(const std::bad_cast& bd){return false;}
    if(this->j==rhs.print())
    return true;

    
}

bool Base::equal(const Base&rhs)const
{
    std::cout<<"Base::equal(const Base&rhs)const\n";
    if(this->j==rhs.j)
    return true;
    return false;
}

int main()
{
   Derived d1,d2(3,15),d3;
   Base b1,b2(6),b1_;
   Base &b3=d1,&b4=b2,&b5=d2,&b6=d3,&b7=b1_,&b8=b1;
   std::cout<<
   std::boolalpha<<(b3==b4)<<" "<<(b3==b6)<<" "<<(b3==b5)<<" "<<(b4==b6)
   <<" "<<(b4==b5)<<" "<<(b5==b6)<<" "<<(b8==b7);
}


/*
false Derived::equal(const Base&rhs)const
true Derived::equal(const Base&rhs)const
false false false Derived::equal(const Base&rhs)const
false Base::equal(const Base&rhs)const
true
*/