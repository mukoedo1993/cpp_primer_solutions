#include<iostream>
#include<fstream>
int main()
{
    //The reason that these functions return an int is to allow them to return an
    //end-of-file marker.
    //positive: normal char
    //negative: EOF 
    std::ifstream if1("part1.txt");
    int ch;
    while((ch=if1.get())!=EOF)
    {
        std::cout<<static_cast<char>(ch)<<std::endl;
    }
}
/*

s


d


c


 


f


g


g


3


2


 


&


$


#


@
*/