#include<bitset>
#include<iostream>

using std::bitset;

int main()
{
    bitset<32>bitvec(1U);
    std::cout<<bitvec;//00000000000000000000000000000001

    //When we use an integral value as an initializer for a bitset, that value is converted
    //to unsigned long long and is treated as a bit pattern. THe bit in the bitset 
    //are a copy of that pattern.
    

    //bitvec1 is smaller than the initializer; high-order bits from the initializer are
    //discarded
    bitset<13>bitvec1(0xbeef);
    std::cout<<"\n"<<bitvec1<<std::endl;//1111011101111

    //bitvec2 is larger than the initializer; higher-order bits in bitvec2 are set to zero.
    bitset<20>bitvec2(0xbeef);
    std::cout<<bitvec2<<std::endl;//00001011111011101111

    //on machines with 64-bit long long 0ULL is 64 bits of 0, so ~0ULL is 64 ones
    bitset<128>bitvec3(~0ULL);
    std::cout<<bitvec3<<std::endl;//bits 


    /*Initializing a bitset from a string*/
    //We can initialize a bitset from either a string or a pointer to an element in a 
    //character array. In either case, the characters represent the bit pattern directly. As
    //usual, when we use strings to represent numbers, the characters with the lowest
    //indices in the string correspond to the high-order bits, and vice versa:
    bitset<32>bitvec4("1100");//bits 2 and 3 are 1, all others are 0
    std::cout<<bitvec4<<std::endl;

    std::string str("1111111000000011001101");
    bitset<32>bitset5(str,5,4);//four bits starting at str[5], 1100
    bitset<32>bitset6(str,str.size()-4);//use last four characters.

    std::cout<<bitset5<<std::endl;//00000000000000000000000000001100

    std::cout<<bitset6<<std::endl;//00000000000000000000000000001101

}