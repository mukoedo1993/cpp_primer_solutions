#include<memory>
#include<iostream>
using std::string;
//exercise 16_61: code itself is the explanation.
template<class T,typename... Args> 
auto 
Make_shared( Args&&... args)->std::shared_ptr<T>
{
     return  std::shared_ptr<T> (new T(args...));
}

struct I//built-in type
{
    I(int,int,int){}
};

struct kichiku//user-defined type
{
   kichiku(string,string,string){

   }
};


int main()
{
    int i=13;
    auto rslt1=Make_shared<I>(i,i,i);//OK
    auto rslt2=std::make_shared<I>(i,i,i);//OK

    auto rslt3=Make_shared<kichiku>("ni","ma","si");
}

//std::shared_ptr<T>