#include<iostream>
#include<vector>
struct Base1{
void print(int)const{
    std::cout<<"Base1::print(int)const";
}
protected:
int ival;
double dval;
char cval;
private:
int *id;
};


struct Base2{
    void print(double)const{
        std::cout<<"Base2::print(double)const\n";
    }
    protected:
    double fval;
    private:
    double dval;
};

struct Derived:Base1{
    void print(std::string)const{
        std::cout<<"Derived::print(std::string)\n";
    }
    protected:
    std::string sval;
    double dval;
};

struct MI:Derived,Base2{
    MI(){
      
    }
 void print(double d)const{

   std::vector<double>v_d(size_t(d),d);
      
      
       
        Derived::print(std::string(v_d.size(),'h'));
        std::cout<<'\n';
        Base2::print(d);
    }
     void foo(double);
    int ival;
double dval;

protected:
    std::vector<double>dvec;
    public:
    void check()
{
    /*MI::...*/ival;dval;dvec;
    Derived::dval=3.14; Derived::sval;
    Base1::ival;Base1::dval=5.13;Base1::cval;
    Base2::fval;
    //(c):
    dval=Derived::dval+Base1::dval;
    std::cout<<"local dval is: "<<dval<<std::endl;

//(d):
     std::cout<<dvec.size()<<std::endl;//we need to insert value
    dvec.push_back(13.4);
     Base2::fval=dvec.back();
     std::cout<<"now Base2::fval is:"<<fval<<'\n';

     //(e):
     cval='C';
     sval[0]=cval;
     std::cout<<"now sval[0]is"<<*(sval.begin())<<'\n';//C
}
};
    
   

void MI::foo(double cval)
{
    int ival;
    //exercise questions occur here.
    //(a): List all the names visible from more than one base class.
   /*
   MI::ival,MI::dval and MI::dvec.
   Derived::dval Derived::sval
  Base1::ival Base1::dval Base1::cval
  Base2::fval
   */
    //(b): Are any names visible from more than one class?
    //(b soln.)Yes. e.g. Derived::dval, Base2::dval;

    //(c): Assign to the local instance of dval the sum of the dval member of Base1 and
    //the dval member of Derived/
    //(c_soln):see the check() function.

    //(d):(d_soln):see the check()function.
    //(e):(e_soln):see the check()function.
}
int main()
{
  MI mi;
 mi.check();
 
}
/*

local dval is: 8.27
0
now Base2::fval is:13.4
now sval[0]isC
*/