#include<iostream>
#include<vector>
#include<type_traits>
using std::vector;
using std::string;
template<typename It>
//exercise 16_40:
auto fcn3(It beg,It end)->decltype(*beg+0)
{
    return *beg;//return a copy of an element from the range
}

//exercise 16_41 part:sum_yaju template function:
template<class It>auto sum_yaju(It beg,It end)->typename std::remove_reference<It*>::type
{
   typename std::remove_reference<It*>::type sum=0;
   for(auto it=beg;it!=end;it++)
   sum=sum+(*it);
   std::cout<<"\nYaju no chikara da ne!\n";
   return sum;

}

int main()
{
    int i[10]={1,2,3,4,5,6,7,8,9};
    std::cout<<fcn3<int*>(std::begin(i),std::end(i));//1 //OK
    std::cout<<fcn3(std::begin(i),std::end(i));//1 //OK
    
    double d[10]={1.,2.,3.,4.,5.,6.,7.,8.,9.,10.};
    std::cout<<fcn3(std::begin(d),std::end(d));//1 //OK
    vector<string>vs={"ni","ma","sile","land","gulag"};
   // std::cout<<fcn3(vs.begin(),vs.end());//error //string+0 cannot hold

    vector<char>vc={'i','o','l','i','a'};
    //std::cout<<fcn3(vc.begin(),vc.end());//error: promotion not allowed
    //std::cout<<fcn3<vector<char>::iterator>(vc.begin(),vc.end());//error
    //char + int not allowed
    vector<int>vi={7,2,3,4,5};
    std::cout<<fcn3(vi.cbegin(),vi.cend());//7

    //only when *T+0 is convergible.
    auto a=sum_yaju(vi.begin(),vi.end());
    vector<long long>vll={12237464728,328247237,384842823994242};
    std::cout<<std::endl<<sum_yaju(vll.cbegin(),vll.cend());
}


/*
1117
Yaju no chikara da ne!


Yaju no chikara da ne!
0xaf0310658bef8

*/