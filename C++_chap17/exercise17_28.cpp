#include<iostream>
#include<random>
#include <cmath>
#include<ctime>
#include <string>
#include<vector>

std::vector< unsigned int> fcn()
{
    std::vector<unsigned>v_UI;
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ud(1,10);
    for(int i=1;i<100;i++)
    v_UI.push_back(ud(e));
    return v_UI;
}

int main()
{
    int i=0;
    for(int UI:fcn())
    {
    std::cout<<UI<<" ";
    if(i%10==0)
    std::cout<<"\n";
    i++;
    }
}
//Result:
/*

1 
2 8 5 6 3 1 7 7 10 4 
6 9 1 1 6 7 1 4 1 5 
7 6 10 9 6 1 7 5 8 10 
8 3 1 8 4 7 8 10 4 3 
10 8 8 7 1 7 9 3 5 8 
5 3 3 4 2 5 9 10 1 10 
6 6 4 10 5 3 1 10 1 6 
4 3 10 6 5 10 1 8 8 9 
2 1 7 9 7 8 8 10 9 3 
4 4 6 6 9 5 9 3

*/