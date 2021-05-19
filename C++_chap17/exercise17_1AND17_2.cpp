#include<tuple>
#include<iostream>
#include<utility>
#include<vector>
int main()
{
    //exercise 17_1:
    std::tuple<int,int,int>ti3={1,2,3};
    auto[i1,i2,i3]=ti3;

    int i4=std::get<0>(ti3);
     int i5=std::get<1>(ti3);
      int i6=std::get<2>(ti3);
      std::cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6;

      //exercise 17_2:
      std::tuple<std::string,std::vector<std::string>,std::pair<std::string,int>>t17_2;
      t17_2={"nima",{"djs","sj"},std::make_pair("str",15)};

}
//1 2 3 1 2 3