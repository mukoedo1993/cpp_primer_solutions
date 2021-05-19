/*
There is no type_info default constructor, and the copy and move constructors and
the assignment operators are all defined as deleted. Therefore, we cannot define, 
copy or assign objects of type type_info. The only way to create a type_info object
is through the typeid operator. 
The name member function returns a C-style character string for the name of the type
represented by the type_info object. The value used for a given type depends on 
the compiler and in particular is not required to match the type names as used in a program.
The only guarantee we have about the return from name is that it returns a unique string
for each type. e.g.:
*/

#include<typeinfo>
#include<iostream>
class Sales_data{};
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
int main()
{
    int arr[10];
    Derived d;
    Base *p=&d;
    std::cout<<typeid(42).name()<<", "<<
    typeid(arr).name()<<","
    <<typeid(Sales_data).name()<<","
    <<typeid(std::string).name()<<", "
    <<typeid(p).name()<<", "
    <<typeid(*p).name()<<", "
    ;

}
//Result:
//i, A10_i,10Sales_data,NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, P4Base, 7Derived,


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
