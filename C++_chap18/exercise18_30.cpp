#include<iostream>
class Class{
    public: Class(){
        std::cout<<"Class::Class()\n";
    }
};
class Base:public Class{
    public: Base(){
        std::cout<<"Base::Base()\n";
    }
    Base(int){
        std::cout<<"Base::Base(int)\n";
    }
    Base(const Base&)
    {
       std::cout<<"Base::Base(const Base&)\n";
    }
};
class D1:virtual public Base{
    public: D1(){
        std::cout<<"D1::D1()\n";
    }
    D1(const D1&){
        std::cout<<"D1::D1(const D1&)\n";
    }
    D1(int i):Base(i){
        std::cout<<"D1::D1(int)\n";
    }
};
class D2:virtual public Base{
    public: D2(){
        std::cout<<"D2::D2()\n";
    }
      D2(const D2&){
        std::cout<<"D2::D2(const D1&)\n";
    }
    D2(int i):Base(i){
        std::cout<<"D2::D2(int)\n";
    }

};
class MI:public D1,public D2{
      public: MI(){
        std::cout<<"MI::MI()\n";
    }
     MI(const D2&){
        std::cout<<"MI::MI(const D1&)\n";
    }
    MI(int i):D1(i),D2(i){
        std::cout<<"MI::MI(int)\n";
    }
};
    class Final:public MI,public Class{
        public:Final(){
            std::cout<<"Final::Final()\n";
        }
         Final(const Final&){
        std::cout<<"Final::Final(const D1&)\n";
    }
    Final(int i):MI(i){
        std::cout<<"Final::Final(int)\n";
    }
    };
int main()
{
   MI mi;
}
//Result:
/*

Class::Class()
Base::Base()
D1::D1()
D2::D2()
MI::MI()
*/