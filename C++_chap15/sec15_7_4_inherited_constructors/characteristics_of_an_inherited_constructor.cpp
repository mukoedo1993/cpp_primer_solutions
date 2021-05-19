/*characteristics of an inherited constructor*/
//1: a constructor using declaration does not change the  access level of the inherited constructors.
//e.g a private constructor in the base is still private in the derived.
//2:A using delcaraton can't specify explicit or constexpr. 
//These characteristics are completely inherited.
//3: A derived class can inherit several constructors from the base class.
//4: If the derived class defines a constructor with the same parameters as a constructor in the base,
//then that constructor is not inherited. The one defined in the derived class is used in place of the inherited constructor.

//5:from page 627: it is worth noting that a derived constructor or assignment operator can use its
//corresponding base class operation regardless of whether the bas eefined its own version of that operator or
//uses the synthesized version.

//6: A class that contains only inherited constructors will have a synthesized default constructor.
#include<iostream>
using std::string;
class B{
    public: B(){std::cout<<"B::B()\n";}
           B(const string&str,double d=1.78,int i=14):bookNo(str),price(d),qnty(i){}
          // explicit B(double d,int i=17):price(d),qnty(i){bookNo="default!";std::cout<<"\nexplicit B()\n";}
           explicit B(double ,int);
             void print(){std::cout<<"\n price is: "<<price<<"qnty is: "<<qnty
               <<". booknois "<<bookNo<<"\n";}
               B(B&&orig){std::cout<<"B(B&&):\n";
                   if(this!=&orig)
               {
                   bookNo=std::move(orig).bookNo;qnty=std::move(orig).qnty;
               price=std::move(orig).price;
               }
               }
               B(const B&orig){std::cout<<"B(const B&)\n";
               bookNo=orig.bookNo;qnty=orig.qnty;
               price=orig.price;}
    protected:
    string bookNo;
    double price;
    int qnty;
    B(unsigned int){}
    private:
    B(unsigned,unsigned){}
};
//we cannot repeat explicit outside the class:
 B::B(double d,int i=17):price(d),qnty(i){bookNo="default!";std::cout<<"\nexplicit B()\n";}


class D1:public B{
               using B::B;
               public:
               
               void print(){std::cout<<"\n price is: "<<price<<"qnty is: "<<qnty
               <<". booknois "<<bookNo<<"\n";
           }
           int t;
};

class D2:public B{
             using B::B;
             public:
             explicit D2(double d,int i=15):B(d,i){bookNo="defaultD2!";std::cout<<"D2::D2(double,int)\n";}
              void print(){std::cout<<"\n price is: "<<price<<"qnty is: "<<qnty
               <<". booknois "<<bookNo<<"\n";}
};

class B1{
    public: 
           constexpr B1(double d,int i):price(d),qnty(i){}//constexpr: only statement is the return
           //constructor: no return //so, no statement at all.
           void print(){std::cout<<"\nB1::print(): price is: "<<price<<"\n"<<"qnty is: "<<qnty;
           }
    private:
    protected:
    double price;
    int qnty;
};

class D1_:public B1
{
public:
    void print(){std::cout<<"\nD1_::print(): price is: "<<price<<"\n"<<"qnty is: "<<qnty;
           }
    using B1::B1;//equivalent to constexpr B1(double d,int i):B1(d,i){}

};

class D2_:public B1{
    using B1::B1;
    public:
    constexpr D2_(double d,int i):B1(d,i){}
};

class B3{};
class D3:public B3{
    using B3::B3;//ok: it synthesized a default constructor even if B3::B3() is inherited. 
};
int main()
{
    B b12;//B::B()
    std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
//D1 ob0={13.2,15};//error: explicit constructor inherited.
D1 b13;//B::B()
 unsigned int k=13;
 //D1 ob1239(k);//error: inaccessible. An private constructor is still private inherited.
std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
B b14(std::move(b12));
std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
D1 kimura("yaju",1.3);kimura.print();
std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
D1 kimura1("yaju1");kimura1.print();
std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
kimura1.t=139;
D1 ddt(kimura1),ddt1(std::move(kimura1));
std::cout<<ddt.t<<std::endl;//139
std::cout<<ddt1.t<<std::endl;//139
std::cout<<kimura1.t;//139 //So we could see that the move and copy 
//constructor is synthesized rather than inherited.
//The synthesized move and call constructor, first, call the user-defined base-class corresponding 
//constructors respectively, and then use their own synthesized statements. Here, t is copied.
//The default constructor, similarly...

std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
D2 kimura3(13.4,5);
std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
    D1_ ob1(13.2,15),ob3={13.2,15};
    std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
    ob1.print();
    std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
   D2_ ob2(13.2,15);
   std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
   ob2.print();
   std::cout<<std::endl<<"line: "<<__LINE__<<std::endl;
   D3 ddtlejd;//OK! :)

}

//Results: 
/*
B::B()

line: 98
B::B()

line: 103
B(B&&):

line: 105

 price is: 1.3qnty is: 14. booknois yaju

line: 107

 price is: 1.78qnty is: 14. booknois yaju1

line: 109
B(const B&)
B(B&&):
139
139
139
line: 120

explicit B()
D2::D2(double,int)

line: 122

line: 124

D1_::print(): price is: 13.2
qnty is: 15
line: 126

line: 128

B1::print(): price is: 13.2
qnty is: 15
line: 130

*
*/