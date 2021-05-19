#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
int main()
{
    using namespace std::placeholders;
    std::vector<std::string>svec={"","","ssdh","ni","","ma","si",""};
     std::vector<std::string>svec1={"","","ssdh","","ni","","ma","si",""};
    auto fcn=&std::string::empty;
    size_t sz=
    count_if(svec.cbegin(),svec.cend(),mem_fn(fcn));//argument-dependent lookup
     
    std::cout<<sz<<std::endl;//4
    sz=
  count_if(svec1.cbegin(),svec1.cend(),bind(fcn,_1));//argument-dependent lookup
  std::cout<<sz<<std::endl;//5
}