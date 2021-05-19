#include<iostream>

class SmallInt{
    friend
    SmallInt operator+(const SmallInt&,const SmallInt&){SmallInt smlt;return smlt;}
    public:
    SmallInt(int i=0){val=i;}//conversion from int
    operator int()const{return val;}//conversion to int
    size_t print(){return val;}
    private: std::size_t val;
}
;

struct LongDouble{
LongDouble (double=0.0){}
operator double(){return 1.3;}
operator float(){std::cout<<"operator float()";return 1.2;}//operator float()
LongDouble operator+(const SmallInt& dd1){LongDouble mkft(dd1); return mkft;}
};

LongDouble operator+(LongDouble& d,double){return d;}

int main()
{
  SmallInt si(4);
  LongDouble ld(8.3);
  //ld=si+id;//either one requires a user-defined conversion.
  ld=ld+si;//one matches exactly, while the other one requires a conversion.
   float mkft1=ld;
   std::cout<<mkft1<<std::endl;//operator float()1.2
}