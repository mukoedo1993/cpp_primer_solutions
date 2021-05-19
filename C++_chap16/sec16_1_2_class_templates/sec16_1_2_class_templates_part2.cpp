#include<vector>
#include<memory>
#include<iostream>
#include<stdexcept>
#include<utility>
#include<cstring>
using std::string;



template<class yaju>using pr=std::pair<yaju,unsigned>;
pr<int> rd;


template <class a>class a1;
template<typename T>class a2{
    template<typename a>friend class a2;
    friend class a1<unsigned>;
};
template <class a>class a1{};

/*static members of class templates*/
//Like any other class, a class template can declare static members:
template<typename T>class Foo{
    public:
    static std::size_t count(){return ctr;}
    //other interface members
    private:
    static std::size_t ctr;
    //other implementation members
    public:
    void print();
};

template<typename T>std::size_t Foo<T>::ctr=0;//define andinitialize ctr
template<typename T>void Foo<T>::print()
{{std::cout<<"Test!\n";}}

template<unsigned us1,unsigned us2>int print1(const char(&p)[us1],const char(&q)[us2])
{
  return std::strcmp(p,q);
}
int main(){
    rd=std::make_pair(11,23);
    std::cout<<rd.first<<std::endl;//11
    std::cout<<rd.second;//23
      Foo<int>().print();//Test! //a temporary object 

    //instantiates static members Foo<string>::ctr and Foo<string>::count
    Foo<std::string>fs;
    Foo<int>fi,fi2,fi3;

    //As with static members of nontemplate classes, we can access a static 
    //member of a class template through an object of the class type by using the 
    //scope operator to access the member directly. Of course, to use a static
    //member through the class, we must refer to a specific instantiation:
    auto ct=Foo<int>::count();
    std::cout<<std::endl<<ct;//0
    auto ct1=fs.count(),ct2=fi.count();
    std::cout<<std::endl<<ct1<<" "<<ct2;//0 0
    std::cout<<print1("dj","dk");
}