/*Access COntrol and Inheritance*/
//protected members

//protected members:
//1: like private, protected members are inaccessible  to users of the class.
//2: Like public, protected members are accessible to members and friends of
//classes derived from this class.

//In addition, protected has another important property:
// A derived class member or friend may access the protected members of the base class
//only through a derived object. The derived class has no special access to the protected 
//members of base-class objects.
#include<iostream>
class Base{
    protected:
    int prot_mem;//protected member
};
class Sneaky:public Base{
friend void clobber(Sneaky&);//can't access Sneaky::prot_mem
//friend void clobber(Base&);//can't access Base::prot_mem
int j;//j is private by default
};
//ok: clobber can access the private and protected members in Sneaky objects
void clobber(Sneaky&s){s.j=s.prot_mem;}
//error: cloober can't access the protected members in Base
//void clobber(Base&b){b.prot_mem=0;}

/*public, private, and protected inheritance*/
class Base1{
    public: 
    Base1()=default;
    Base1(int i,char c){prot_mem=i;priv_mem=c;}
    void pub_mem(){std::cout<<"Base1 is called!\n";}//public member
    protected:
    int prot_mem;//protected member
    private:
    char priv_mem;//private member
};

struct Pub_Derv: public Base1{
    Pub_Derv(int i,char c):Base1(i,c){}
    Pub_Derv()=default;
    //ok: derived classes can access protected members
    int f(){return prot_mem;}
    //error:private members are inaccessible to derived class
    //char g(){return priv_mem;}
};
struct Priv_Derv:private Base1{
    //private derivation doesn't affect access in the derived class
     Priv_Derv(int i,char c):Base1(i,c){}
    Priv_Derv()=default;
    int f1()const {return prot_mem;}
};
//The purpose of the derivation access specifier is to control the access that
//users of the derived class-- including other classes derived from the derived class--
//have to the members inherited from Base1:

//The derivation access specifier used by a derived class also controls access from classes
//that inherit from that derived class:
struct Derived_from_public:public Pub_Derv{
    //ok: Base::prot_mem remains protected in Pub_Derv
    int use_base(){return prot_mem;}
};

struct Derived_from_private:public Priv_Derv{
    //error: Base::prot_mem is private in Priv_Derv
    //int use_base(){return prot_mem;}
};

//User code may use the derived_to_base conversion only if D inherits publicly from B.
//User code may not use the conversion if D inherits from B using either protected or private.
//Member functions and friends of D can use conversion to B regardless of how D inherits from B. The
//derived-to-base conversion to a direct base class is always accessible to members and friends of a derived
//class.
//Member functions and friends of classes derived from D may use the derived-to-base conversion if D
//inherits from B using either public or protected. Such code may not use the converison if D inherits privately
//from B.


/*Friendship and inheritance*/
//JUst as friendship is not trnasitive, friendship is not transitive, friendship is also not inherited.

class Base2{
    //added friend declaration; other members as before
        public: 
    Base2()=default;
    Base2(int i,char c){prot_mem=i;priv_mem=c;}
    void pub_mem(){std::cout<<"Base1 is called!\n";}//public member
    protected:
    int prot_mem;//protected member
    private:
    char priv_mem;//private member
    friend class Pal;//Pal has no access to classes derived from  Base2
};

class Sneaky2:public Base2{
friend void clobber(Sneaky2&);//can't access Sneaky::prot_mem
//friend void clobber(Base&);//can't access Base::prot_mem
int j;//j is private by default
};

class Pal{
    public:
    int f(Base2 b){return b.prot_mem;}//ok: Pal is a friend of Base
    //int f2(Sneaky s){return s.j;}//error: Pal is not friend of Sneaky
    //access to base class is controlled by the base class, even inside a derived object
    int f3(Sneaky2 s){return s.prot_mem;}//ok: Pal is a friend
    //The fact that f3 is legal may seem surprising, but it follows directly from the notion
    //that each class controls access to its own members.
    //Pal is a friend of Base2, so Pal can access the members of Base objects.
};

class D2:public Pal{
    public:
    //int mem(Base b){return b.prot_mem;}//error: friendship doesn't inherit
};





/*Exempting Individual Members*/
class Base_yaju{
    public: 
    Base_yaju()=default;
    Base_yaju(std::size_t sz):n(sz){}
    std::size_t size()const {return n;}
    protected:
    std::size_t n;
};

//Because Derived_kimura uses private inheritance, the inherited members, size and n, are (by default)
//private members of Derived_kimura. The using declarations adjust the accessibility of these members.
//User of Derived can access the size member, and classes subsequently derived from Derived can access n.

class Derived_kimura: private Base_yaju{
    public:
    Derived_kimura()=default;
    Derived_kimura(std::size_t sz):Base_yaju(sz){}
    //maintain access levels for members related to the size of the object
    using Base_yaju::size;
    protected:
    using Base_yaju::n;
};
//extra note:
// A using declaration inside a class can name any accessible member of a direct or indirect base class.
//Access to a name specified in a using declaration depends on the 
//access specifier preceding the using declaration.
// In general, it means that the members we inherited are set in default given in the derived class type,
//and reallocate them using the name: using Base::member under the specified authority control keyword.



/*Default Inheritance Protection Levels*/
class Base_mikasa{/*...*/};
struct D1_:Base_mikasa{/*...*/};//public inheritance by default
class D2_:Base_mikasa{/*...*/};//private inheritance by default
//extra note:
//There only differences between the struct keyword and those defined using class:
//The only difference are the default access specifier for members and the default derivation
//access specifier. There are no other distinctions.
int main()
{
    Pub_Derv d1;//members inherited from Base are public
    Priv_Derv d2;//members ingerited from Base are private
    d1.pub_mem();//ok: pub_mem is public in the derived class
    //d2.pub_mem();//error: pub_mem is private in the derived class
   Derived_kimura Ob1(13);
   std::cout<<std::endl<<Ob1.size()<<std::endl;//Derived_kimura::size() is public, as we can see.
}