#include<iostream>
#include<random>
#include <cmath>
#include<ctime>
#include <string>
#include<vector>

std::vector< unsigned int> fcn(unsigned i=0)
{
    std::vector<unsigned>v_UI;
    static std::default_random_engine e(i);
    static std::uniform_int_distribution<unsigned> ud(1,10);
    for(int i=1;i<100;i++)
    v_UI.push_back(ud(e));
    return v_UI;
}

int main()
{
    std::cout<<"test 1: \n";
    int i=0;
    for(int UI:fcn())
    {
    std::cout<<UI<<" ";
    if(i%10==0)
    std::cout<<"\n";
    i++;
    }
    i=0;
    std::cout<<"\ntest 2: \n";
        for(int UI:fcn(1))
    {
    std::cout<<UI<<" ";
    if(i%10==0)
    std::cout<<"\n";
    i++;
    }
}

/*

test 1: 
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
test 2: 
5 
6 5 3 2 2 6 9 1 6 5 
10 8 6 9 7 9 2 3 8 2 
1 3 1 5 1 8 10 3 2 4 
9 7 2 7 4 4 5 2 6 9 
6 10 6 2 10 5 2 6 3 5 
5 10 2 2 4 7 2 7 7 9 
3 5 4 3 1 10 5 2 10 5 
2 9 1 2 1 4 3 2 8 5 
4 5 9 10 7 3 7 10 3 9 
5 6 7 9 8 5 10 7


*/