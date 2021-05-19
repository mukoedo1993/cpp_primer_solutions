#include<iostream>
class Base1{
    public: 
    Base1()=default;
    Base1(int i,char c){prot_mem=i;priv_mem=c;}

    void memfcn(Base1 &b){b=*this;}

    void pub_mem(){std::cout<<"Base1 is called!\n";}//public member
    
    protected:
    int prot_mem;//protected member
    private:
    char priv_mem;//private member
};

struct Pub_Derv: public Base1{
     void memfcn(Base1 &b){b=*this;}
    Pub_Derv(int i,char c):Base1(i,c){}
    Pub_Derv()=default;
    //ok: derived classes can access protected members
    int f(){return prot_mem;}
    //error:private members are inaccessible to derived class
    //char g(){return priv_mem;}
};
struct Protected_Derv: protected Base1{
     void memfcn(Base1 &b){b=*this;}
     Protected_Derv(int i,char c):Base1(i,c){}
    Protected_Derv()=default;
    //ok: derived classes can access protected members
    int f(){return prot_mem;}
};
struct Priv_Derv:private Base1{
    //private derivation doesn't affect access in the derived class
     void memfcn(Base1 &b){b=*this;}
     Priv_Derv(int i,char c):Base1(i,c){}
    Priv_Derv()=default;
    int f1()const {return prot_mem;}
};

struct Derived_from_public:public Pub_Derv{
     void memfcn(Base1 &b){b=*this;}
    int use_base(){return prot_mem;}
};

struct Derived_from_private:public Priv_Derv{
     //void memfcn(Base1 &b){b=*this;}//error:Base1::Base1 is inaccessible
     //Base1 is inacceesible base of "Derived_from_private"
};
struct Derived_from_protected:public Protected_Derv{
     void memfcn(Base1 &b){b=*this;}
};

int main(){
    Pub_Derv d1;Priv_Derv d2;Protected_Derv d3;Derived_from_public dd1;
    Derived_from_protected dd2;Derived_from_private dd3;
    Base1 *p1=dynamic_cast<Base1*>(&d1);Base1 *p=&d1;
    p=&dd1; p1=dynamic_cast<Base1*>(&dd1);
}