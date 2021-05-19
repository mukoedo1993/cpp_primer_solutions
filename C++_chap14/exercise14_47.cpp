//Q: Explain the differnce between two conversion operator

#include<iostream>
struct INtegral{
    INtegral(int j):i(j=3){}
operator const int(){std::cout<<"const int()\n";}//a non const object would prefer this.
operator int()const{std::cout<<"int () const\n";}//a const object could only call this.
int i=43;
};

int main()
{
    INtegral int1(13);
    const INtegral int2(14);
    int i=int2;//int ()const
    int j=int1;//const int()
    int k=static_cast<int>(int1);//const int()
    int t=static_cast<int>(int2);//int ()const
}