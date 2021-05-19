
//A tuple is a template that is similar to pair.
//Each pair type has differnt types for its members.

//quick and dirty data structure
#include<tuple>//tuple
#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<type_traits>
using std::pair;
using std::string;
template<class N,class M>
auto Make_pair(const N&n,const M&m)->std::pair<N,M>
{
    return pair<N,M>(n,m);
}
template<class N>
auto Make_pair(const N&n,const char* m)->std::pair<N,std::string>
{
    return pair<N,std::string>(n,std::string(m));
}
template<class N>
auto Make_pair(const N&n, char* m)->std::pair<N,std::string>
{
    return pair<N,std::string>(n,std::string(m));
}
template<class N>
auto Make_pair(const char* m,const N&n)->std::pair<std::string,N>
{
    return pair<std::string,N>(std::string(m),n);
}
template<class N>
auto Make_pair( char* m,const N&n)->std::pair<std::string,N>
{
    return pair<std::string,N>(std::string(m),n);
}
template<class B,class... Args>
B fcn(B b,const Args&... args)
{       B b1(args...);
    return b1;
}
struct B{
    B(int,int,int){}
};
template<class... Args>
 auto Make_tuple(Args... args)->std::tuple<Args... >
{
   return std::tuple<Args...>(args...);
}


int main()
{
  
    std::tuple<size_t,size_t,size_t>threeD;//all three members set to 0
     std::tuple<std::string,std::vector<double>,int,std::list<int>>
     someVal("constants",{3.14,2.718},42,{0,1,2,3,4,5});

     //The tuple constructor is explicit:
     std::tuple<size_t,size_t,size_t>threeD1={1,2,3};
     auto [it,it1,it2]=threeD1;
     std::cout<<it<<std::endl;
     auto it3=Make_pair(13,"str");
     std::cout<<it3.second;
     B b(1,3,4);
     fcn(b,1,3,4);
    
     auto book=std::get<0>(someVal);
      //......

      typedef decltype(someVal) trans;

      //returns the number of members in object's of type trans
      size_t sz=std::tuple_size<trans>::value;

      //cnt has the same type as the second memebr in item
      std::tuple_element<1,trans>::type cnt=std::get<1>(someVal);
    //tuple_size has a public static data memebr named value that is the number
    //of members in the specified type. The tuple_element template takes an index as
    //well as a tuple type. tuple_element has a public type member named type that is
    //the type of the specified member of the specified tuple type. 

    /*Relational and Equality Operators*/
    std::tuple<string,string>duo("1","2");
    std::tuple<size_t,size_t>twoD(1,2);
    //bool b=(duo==twoD);//error: can't compare a size_t and a string
    //std::cout<<std::boolalpha<<b;
    std::tuple<size_t,size_t,size_t>threeD2(1,2,3);
     //bool bnimasi=(twoD<threeD2);//error: size is different

     std::tuple<size_t,size_t>origin(0,0);
     bool b114514=(origin<twoD);
     std::cout<<std::boolalpha<<b114514;
}
/*
1
strtrue
*/