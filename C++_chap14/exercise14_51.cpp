#include<iostream>
struct LongDouble{
LongDouble (double=0.0){}
operator double(){return 1.3;}
operator float(){std::cout<<"operator float()";return 1.2;}//operator float()
};
void calc(int)
{
    std::cout<<"calc(int)\n";
}
void calc(LongDouble)
{
    std::cout<<"calc(LongDouble)\n";
}
int main()
{
    double dval=1.31;
    calc(dval);//calc(int)
    //it si legal, because calc(int) only needs built-in conversions.
}