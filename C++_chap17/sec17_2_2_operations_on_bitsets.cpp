#include<iostream>
#include<bitset>
int main()
{
    std::bitset<32>bitvec(1U);//32 bits, low-order bit is 1., remaining bits are 0
    bool is_set=bitvec.any();//true, one bit is set
    bool is_not_set=bitvec.none();//false, one bit is set
    bool all_set=bitvec.all();//false, only one bit is set
    size_t onBits=bitvec.count();//returns 1
    size_t sz=bitvec.size();//returns 32
    
    bitvec.flip();//reverses the value of all the bits in bitvec
    bitvec.set();// sets all bits to 1

    bitvec.flip(0);//reverses the value of first bit
    bitvec.set(bitvec.size()-1);//turns on the last bit
    bitvec.set(0,0);//turns off the first bit
    int i=16;
    bitvec.reset(i);//turns off the ith bit
    std::cout<<std::boolalpha<<bitvec.test(0);//false
    //Because the first bit is off

    //The subscript operator is overloaded on const. The const version returns a 
    //bool value true if the bit at the given index is on, false otherwise.
    bitvec[0]=0;//turns off the bit at position 0
    bitvec[31]=bitvec[0];//set the last bit to the same value as the first bit
    bitvec[0].flip();//flip the value of bit at position 0
    ~bitvec[0];//equivalent to the line above
    bool b=bitvec[0];
    std::cout<<b<<std::endl;//false

    std::bitset<4>sbbit(std::string("sbbs"),0,5,'s','b');//sbbs->0110->0110
    sbbit.set(3,'s');//0110->1110
    std::cout<<sbbit;//1110
    std::cout<<std::endl<<sbbit[3];//true


    bool status;
    //version using bitwise operators
    unsigned long quizA=0;//this value is used as a collection of bits
    quizA|=1UL<<27;//indicate student number 27 passed
    status=quizA&(1UL<<27);//check how student number 27 did
    quizA&= ~(1UL<<27);//student number 27 failed

    //equivalent actions using the bitset library
    std::bitset<30>quizB;//allocate one bit per student;all bits initialized to 0
    quizB.set(27);//indicate that student 27 passed
    status =quizB[27];//check how student 27 did
    std::cout<<std::endl<<quizB;
    quizB.reset(27);//student number 27 failed
    std::cout<<std::endl<<quizB;
    
}

/*
falsetrue
1110
true
001000000000000000000000000000
000000000000000000000000000000
*/