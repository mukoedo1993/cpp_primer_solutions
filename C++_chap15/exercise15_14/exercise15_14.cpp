#include<iostream>
using std::string;
//exercise 15_13;
class base{
    public:
    base()=default;
    base(const string &str):basename(str){}
    string name(){std::cout<<"base::name(): ";return basename;}
    virtual void print(std::ostream&os){os<<basename;}
    private:string basename;
};

class derived:public base{
    public:
    derived()=default;
    derived(const string&str1,int i1=13):base(str1),i(i1){}
    void print(std::ostream&os)override{this->base::print(os);os<<" "<<i;}//I modified the code here.
    private:
    int i;
};

int main()
{
    base bobj("NMSL");base *bp1=&bobj; base &br1=bobj;
    derived dobj("NMSLAND",14);base *bp2=&dobj; base &br2=dobj;
    std::cout<<"\n\na:";
    bobj.print(std::cout);//ordinary, called base::print(ostream&)
    std::cout<<"\n\nb:";
    dobj.print(std::cout);//called derived::print(ostream&)override
        std::cout<<"\n\nc:";
    bp1->name();//called base::name()
    std::cout<<"\n\nd:";
      bp2->name();//called base::name()
        std::cout<<"\n\ne:";
    br1.print(std::cout);//br1 is bound to an base object. ordinary, called base::print(ostream&)
    std::cout<<"\n\nf:";
    br2.print(std::cout);//br2 is bound to a derived object. call derived::print(ostream&)
    std::cout<<"\nextra: ";
    br2.base::print(std::cout);//br2, anyway, circumvent the virtual mehcanism, called base::print(os&).

}