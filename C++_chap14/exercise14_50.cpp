#include<iostream>
struct LongDouble{
LongDouble (double=0.0){}
operator double(){return 1.3;}
operator float(){std::cout<<"operator float()";return 1.2;}//operator float()
};

int main()
{
    LongDouble ldObj;
    //int ex1=ldObj;//int ambiguous conversion. Both double and float are ok.
    float ex2=ldObj;//ok: float and float are exactly match.
}