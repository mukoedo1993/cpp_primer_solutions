#include<iostream>
#include<random>
#include <cmath>
#include<ctime>
#include<vector>

std::vector< unsigned int> fcn(unsigned i=0,unsigned min=0,unsigned max=10)
{
    std::vector<unsigned>v_UI;
    static std::default_random_engine e(i);
    std::uniform_int_distribution<unsigned> ud(min,max);
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
    std::cout<<"\ntest 3: \n";
        for(int UI:fcn(1,3,7))
    {
    std::cout<<UI<<" ";
    if(i%10==0)
    std::cout<<"\n";
    i++;
    }
}

/*

test 1: 
0 
1 8 5 5 2 0 7 7 10 4 
5 9 0 0 5 7 0 4 0 4 
7 6 10 9 5 1 7 4 7 10 
8 2 0 8 3 6 8 10 4 2 
10 7 8 7 0 6 9 2 4 8 
5 2 3 3 1 5 9 10 0 9 
5 5 3 10 5 2 0 10 0 5 
4 3 10 5 5 10 0 8 8 9 
1 0 7 9 6 8 7 10 9 2 
3 3 5 6 9 4 9 2 
test 2: 
4 
5 5 3 1 1 6 8 0 5 5 
10 8 6 9 6 9 1 2 7 1 
1 3 0 4 0 7 10 2 1 3 
9 7 1 7 4 4 5 1 6 9 
6 10 6 1 10 4 1 6 2 5 
5 10 1 2 3 6 1 7 6 8 
2 5 4 2 0 9 4 1 10 4 
1 9 1 1 0 4 2 1 8 5 
3 4 8 10 7 2 7 9 2 9 
5 5 6 8 8 5 10 6 
test 3: 
5 7 
6 6 7 7 7 4 5 5 3 5 
5 7 5 6 7 6 7 6 6 3 
7 5 5 3 6 5 6 6 3 7 
7 7 5 3 5 7 4 5 4 5 
7 5 5 7 4 4 7 3 6 6 
3 3 6 6 4 5 6 6 4 7 
6 7 3 3 6 6 4 4 3 4 
7 7 4 4 6 4 6 6 5 4 
3 3 3 7 4 7 3 4 6 3 
7 3 7 4 4 3 4

*/