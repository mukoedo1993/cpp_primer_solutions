#include<iostream>

class SmallInt{
    friend
    SmallInt operator+(const SmallInt&,const SmallInt&){SmallInt smlt;return smlt;}
    public:
    SmallInt(int i=0){val=i;}//conversion from int
    operator int()const{return val;}//conversion to int
    size_t print(){return val;}
    private: std::size_t val;
};

int main()
{
  SmallInt s1;
  //double d1=s1+3.14;//ambuguity double(s1) or SmallInt(3.14)

  //EIther way is OK: d and d2:
  double d=static_cast<double>(s1)+3.14;
  std::cout<<d<<std::endl;//3.14
  double d2=s1+SmallInt(3.14);
  std::cout<<d2<<std::endl;//0
}