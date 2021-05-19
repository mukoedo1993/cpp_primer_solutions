#include<iostream>
using std::string;
//exercise 15_13;
class base{
    public:
    base(const string &str):basename(str){}
    string name(){return basename;}
    virtual void print(std::ostream&os){os<<basename;}
    private:string basename;
};

class derived:public base{
    public:
    derived(const string&str1,int i1=13):base(str1),i(i1){}
    void print(std::ostream&os)override{this->base::print(os);os<<" "<<i;}//I modified the code here.
    private:
    int i;
};

int main()
{
     base Ob1("Oct_4th.");
     derived Ob2("Oct_5th.");
     std::cout<<std::endl;
     Ob1.print(std::cout);
     std::cout<<std::endl;
     Ob2.print(std::cout);
}