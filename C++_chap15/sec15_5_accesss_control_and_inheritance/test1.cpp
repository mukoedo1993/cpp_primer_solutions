#include<iostream>
class cls1{
       friend class cls3;
    public:
    cls1()=default;
    protected:
    cls1(int j):i(j){}
 
    int i;
};

class cls2:private cls1{
    public:
    using cls1::i;
    cls2()=default;
    cls2(int j):cls1(j){}
};
class cls4: public cls1{
    private:
    using cls1::i;
    public:
    cls4()=default;
    cls4(int j):cls1(j){}
};

class cls3{
    public:
    void print(){cls2 Ob1(13);std::cout<<Ob1.i;//13
    cls1 Ob2(12);std::cout<<std::endl<<Ob2.i;//12
    cls4 Ob3(14);
    //std::cout<<Ob3.i;//error: Ob3.i is private as soon as in the form of cls4::i.
    }
};

int main()
{cls3 Ob1_;Ob1_.print();}