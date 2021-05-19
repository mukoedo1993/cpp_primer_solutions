#include<iostream>
#include<cmath>
#include<iomanip>
using std::cout;
int main()
{
    std::cout<<std::uppercase<<std::hexfloat<<"hexidecimal format: "
    <<sqrt(2.0)<<'\n'//141
<<"scientific "<<std::scientific<<sqrt(2.0)<<'\n'
<<"fixed decimal"<<std::fixed<<sqrt(2.0)<<'\n'
<<"use defaults: "<<std::defaultfloat<<sqrt(2.0)
<<"\n\n";
double i=3.12;
std::cout<<std::hexfloat<<i;
}

/*
hexidecimal format: 0X1.1AD7BC01366B8P+7
scientific 1.414214E+02
fixed decimal141.421356
use defaults: 141.421

*/