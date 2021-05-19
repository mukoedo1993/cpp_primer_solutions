#include<iostream>
#include<bitset>
//exericse 17_12:
template<class T>
bool is_n_passed(const T&t,size_t i)
{
       return t[i];
}
int main()
{
    //exercise 17_11:
    //part 1:
    std::bitset<10>ten_Q;
    ten_Q.flip(3);
    ten_Q.set(7);
    std::cout<<ten_Q<<std::endl;


//part 2:from <10> to<100>
    std::bitset<100>hyaku_Q;
    std::cout<<hyaku_Q;
    hyaku_Q[23]=1;
    
    //exercise 17_12:
    std::cout<<std::endl<<ten_Q[7]<<std::endl;
    std::cout<<hyaku_Q[23]<<std::endl;
}

/*
0010001000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
1
1
*/