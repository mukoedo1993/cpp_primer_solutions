#include<iostream>
#include<vector>
#include<type_traits>
#include<cstring>

template<class T>
auto cnt(const T& t,std::vector<T>vt)->size_t
{
    size_t cnnt=0;
   for(auto it=vt.cbegin();it!=vt.cend();it++)
   {
      if(*it==t)cnnt++;
   }
   return cnnt;
}
template<>
size_t cnt<const char*>(const char* const &cc ,std::vector<const char*>v)
{
    size_t cnnt=0;
     for(auto it=v.begin();it!=v.end();it++)
     {
         if(strcmp(cc,*it)==0)cnnt++;
     }
     return cnnt;
}

int main()
{
      std::vector<int>vi={1,-3,2,3,12,-87};
      std::vector<double>vd={1.3,2.7,-3.4,1.3,2.3,1.3};
      std::vector<std::string>vs={"uber","us","uber"};
      std::string str("uber");
      std::cout<<cnt(1,vi)<<" "<<cnt(1.3,vd)<<" "<<cnt(std::string("uber"),vs)<<" "
      <<cnt(str,vs);
      std::vector<const char*>vc={"ber","li","li"};
      std::cout<<" "<<cnt(static_cast<const char*>("li"),vc);
}

//Result:
//1 3 2 2 2