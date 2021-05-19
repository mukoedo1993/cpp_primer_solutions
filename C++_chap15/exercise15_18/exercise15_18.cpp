#include<iostream>
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
struct Protected_Derv: protected Base1{
     Protected_Derv(int i,char c):Base1(i,c){}
    Protected_Derv()=default;
    //ok: derived classes can access protected members
    int f(){return prot_mem;}
};
struct Priv_Derv:private Base1{
    //private derivation doesn't affect access in the derived class
     Priv_Derv(int i,char c):Base1(i,c){}
    Priv_Derv()=default;
    int f1()const {return prot_mem;}
};

struct Derived_from_public:public Pub_Derv{
    int use_base(){return prot_mem;}
};

struct Derived_from_private:public Priv_Derv{
};
struct Derived_from_protected:public Protected_Derv{
};

int main(){
    Pub_Derv d1;Priv_Derv d2;Protected_Derv d3;Derived_from_public dd1;
    Derived_from_protected dd2;Derived_from_private dd3;
    //(a):
    Base1 *p1=dynamic_cast<Base1*>(&d1);
    Base1 *p=&d1;
    //(b):
     //p=&d2;//conversion to inaccessible base class "Base1" is not allowed
     //(c):
    //p=&d3;//conversion to inaccessible base class "Base1" is not allowed
    //(d):
    p=&dd1;//ok:
    p1=dynamic_cast<Base1*>(&dd1);

    //(e):
    //p=&dd2;//conversion to inaccessible base class "Base1" is not allowed
    //p1=dynamic_cast<Base1*>(&dd2);//conversion to inaccessible base class "Base1" is not allowed

    //(f):
    //p=&dd3;
    //p1=dynamic_cast<Base1*>(&dd3);

}