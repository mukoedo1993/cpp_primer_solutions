#include<iostream>
template<class T1,class T2>class Screen{
   public:
   Screen(T1 t1,T2 t2):width(t1),length(t2){}
   friend std::ostream& operator<<(std::ostream&os,const Screen&scr)
   {
       os<<scr.width<<" "<<scr.length;
       return os;
   }
    friend std::istream& operator>>(std::istream&is,Screen&scr)
   {
       is>>scr.width>>scr.length;
       return is;
   }
    private:
    T1 width;
     T2 length;
};

int main()
{
    Screen<int,double>screen1(13,4.6);
    std::cout<<screen1;
    std::cin>>screen1;
    std::cout<<screen1;
}