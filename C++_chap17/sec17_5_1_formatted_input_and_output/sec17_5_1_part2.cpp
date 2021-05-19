#include<iostream>
#include<iomanip>
using std::cout;
int main()
{
    int i=-16;
    double d=3.1459;
    //pad the first column to use a minimum of 12 positions in the putput
    cout<<"i: "<<std::setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<std::setw(12)<<d<<"next col"<<'\n';
    //pad the 1st column and left-justify all columns
    std::cout<<std::left
    <<"i: "<<std::setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<std::setw(12)<<d<<"next col"<<'\n'
    <<std::right;//restore column justification
    //pad the first column and right-justify all columns
    std::cout<<std::right
      <<"i: "<<std::setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<std::setw(12)<<d<<"next col"<<'\n';
   //pad the first column but put the padding internal to the field
    cout<<std::internal
     <<"i: "<<std::setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<std::setw(12)<<d<<"next col"<<'\n';
   //past the 1st column, using # as the pad character
    cout<<std::setfill('#')
     <<"i: "<<std::setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<std::setw(12)<<d<<"next col"<<'\n'
    <<std::setfill(' ');
    /*controlling input formatting*/
    char ch;
    std::cin>>std::noskipws;
    while(std::cin>>ch&&ch!='q')
    std::cout<<ch;
    std::cin>>std::skipws;
}
/*

i:          -16next col
d:       3.1459next col
i: -16         next col
d: 3.1459      next col
i:          -16next col
d:       3.1459next col
i: -         16next col
d:       3.1459next col
i: -#########16next col
d: ######3.1459next col
12 e rdf fd q
12 e rdf fd 

*/