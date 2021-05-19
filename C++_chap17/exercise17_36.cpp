#include<iostream>
#include<cmath>
#include<iomanip>
using std::cout;
int main()
{
    std::cout<<std::setw(40)
    <<std::left<<std::uppercase<<std::hexfloat<<"hexidecimal format: "
    <<sqrt(2.0)<<'\n'//141
<<std::setw(40)<<"scientific "<<std::scientific<<sqrt(2.0)<<'\n'
<<std::setw(40)<<"fixed decimal"<<std::fixed<<sqrt(2.0)<<'\n';
cout<<std::setfill('$')
<<std::setw(40)<<"use defaults: "<<std::defaultfloat<<sqrt(2.0)
<<"\n\n";
}

/*
hexidecimal format:                     0X1.6A09E667F3BCDP+0
scientific                              1.414214E+00
fixed decimal                           1.414214
use defaults: $$$$$$$$$$$$$$$$$$$$$$$$$$1.41421
*/