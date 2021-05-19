#include<iostream>
#include<bitset>
int main()
{
    //part 1:
    std::bitset<10>ten_Q;
    ten_Q.flip(3);
    ten_Q.set(7);
    std::cout<<ten_Q<<std::endl;


//part 2:
    std::bitset<100>hyaku_Q;
    std::cout<<hyaku_Q;
}

/*
0010001000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*/