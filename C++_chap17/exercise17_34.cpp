#include<iostream>
using std::cout;
int main()
{
    double pi=3.1415926;
    cout<<std::hex<<"hex: "<<pi<<std::ends;//without change
    cout<<'\n';
    cout<<std::hexfloat<<"hexfloat: "<<pi<<std::defaultfloat<<std::endl;//change here
    /*
    hex: 3.14159
hexfloat: 0x1.921fb4d12d84ap+1
    */
   cout<<std::unitbuf;//flush buffers after every output operation
   cout<<std::nounitbuf;//restore normal buffer operations
}