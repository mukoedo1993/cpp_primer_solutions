#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<cmath>

const double pi_=3.1415926535879323846;
bool tst1(double i,double j)
{
    if(sin(i)>=sin(j))
    return true;
    return false;
}


int main()
{
    using dft=bool(double,double);
      std::set<double,dft(*)>s(tst1);
      std::vector<double>v={0.5*pi_,0.25*pi_,0.333*pi_,1.2*pi_,0.};
      s.insert(v.begin(),v.end());
      for_each(s.cbegin(),s.cend(),[](double i){std::cout<<i<<" ";
      std::cout<<sin(i)<<std::endl;});
}