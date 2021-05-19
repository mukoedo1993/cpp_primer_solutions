#include<iostream>
class ex14_34{
    public:
    ex14_34(int a=0):a1(a){}
    int operator()(int a2,int b2,int c2)
    {
      if(a2>a1)return a2;
      else if (b2>a1)return b2;
      else return c2;
     
    }
    int a1;
};

int main()
{
    ex14_34 fcn1,fcn2(12);
    std::cout<<fcn1(13,2,6);//11
    std::cout<<std::endl<<fcn2(10,53,19)<<std::endl;//53
    std::cout<<fcn2(-5,-12,-449)<<std::endl;//-449

}