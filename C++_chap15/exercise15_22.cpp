//I choose the Geometric primitives. I will name the base class Geometrice primitive shape.
#include<iostream>
class shape{
    public:
    shape(double up,bool is_it):upper_bnd(up),is_it_line(is_it){}
    shape()=default;
    protected:
    double upper_bnd;
    bool is_it_line;
    virtual double m_3()const=0;
    private:
    
};

class box:public shape{
    public:
    box()=default;
    box(double up,bool is_it=true):shape(up,is_it){if(is_it==false)exit(-1);}
     double m_3()const override{return upper_bnd*upper_bnd*upper_bnd;}
};

class circle:public shape{
    public:
    circle()=default;
    circle(double up,bool is_it=false):shape(up,is_it){if(is_it==true)exit(-1);}
     double m_3()const override{return 4.0/3.0*upper_bnd*upper_bnd*upper_bnd;}
};
class circle1:circle{//default: private inheritance
    public:
    circle1()=default;
    //Notice that indirect nonvirtual base class is not allowed.
    //We have no direct access to shape, so we cannot list initialize shape.
    circle1(double up,bool is_it=false):circle(up,is_it){if(is_it==true)exit(-1);}
     double m_3()const override{return 4.0/3.0*upper_bnd*upper_bnd*upper_bnd;}
     void print_all(){std::cout<<std::boolalpha;
         std::cout<<upper_bnd<<" "<<is_it_line<<"\n";}
};


int main(){circle crl(20.0);box bx(10.0);
std::cout<<crl.m_3()<<std::endl;//10666.7
std::cout<<bx.m_3()<<std::endl;//1000
//box bx2(10.3,false);
circle1 crl1(28.0);
crl1.print_all();//28 false
}
