#include<iostream>
#include<functional>
#include<memory>
//A specialized hash class must have:
//1:An overloaded call operator that returns a size_t and takes an object of
//the container's key type.

//2:Two type parameters, result_type and agrument_type, which are the return and argument
//types, respectively, of the call operator.

//3:The default constructor and a copy-assignment operator
//(which can be impilcitly defined)




//open the std namespace so we can use specialize std::hash
#include"sales_data.h"
namespace std{

    template<>
    struct hash<Sales_data>
    {
       //the type used to hash an unordered container must define these types
       typedef size_t result_type;
       typedef Sales_data argument_type;//by default, this type needs ==
       size_t operator()(const Sales_data& s)const;
       //our class uses synthesized copy control and default constructor
    };
     size_t
     hash<Sales_data>::operator()(const Sales_data &s)const
     {
         return hash<string>()(s.bookNo)^
         hash<unsigned>()(s.units_sold)^
         hash<double>()(s.revenue);
     }
    //close the std namespace; note: no semicolon after the close curly
}
//Any definitions that appear between the open and close curlies will be part of the std
//namespace
struct B{
    void fcn(int &&)
    {std::cout<<"\nvoid fcn(int&&)\n";}
    void fcn(const int&)
    {}
};


template<class T>typename std::remove_reference<T>::type&& Move(T &&t)
{
       return static_cast<typename std::remove_reference<T>::type&&>(t);
}


struct B1{
    B1(){}
    B1(int i1,int j1,int k1):i(i1),j(j1),k(k1){}
    int i;
    int j;
    int k;
};

/*Class-Template partial specializations*/
template<typename T,class... Args>
auto Make_shared(Args... args)->std::shared_ptr<T>
{
   return std::shared_ptr<T>(new T((args)...));
}

int main()
{
    Sales_data ob1,ob2,ob3("str",13);
  std::hash<Sales_data>Ob1,Ob2;
 std::cout<<std::boolalpha;
 std::cout<<(Ob1(ob1)==Ob2(ob1))<<std::endl;//true
 std::cout<<(Ob1(ob1)==Ob1(ob2))<<std::endl;//true
  std::cout<<(Ob1(ob2)==Ob1(ob3))<<std::endl;//false
  int i=14;
  B bob1;
  bob1.fcn(Move(i));
  B1 tt1({3,4,5});
  int i1=13,i2=i1,i3=i2;
   
   auto it=Make_shared<B1>(13,1,45);
   std::cout<<(*it).i;
}

//Results:
/*

true
true
false

void fcn(int&&)
13
*/