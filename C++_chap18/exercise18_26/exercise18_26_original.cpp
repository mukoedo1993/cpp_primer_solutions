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
 void print(std::vector<double>)const{
        std::cout<<"MI::print(std::string)\n";
    }
    protected:
    int *ival;
    std::vector<double>dvec;
};

int main()
{
    MI mi;
    mi.print(42);
    //cannot convert ‘int’ to ‘std::vector<double>’
    //no suitable constructor exists to convert 
    //from "int" to "std::vector<double, std::allocator<double>>"
}