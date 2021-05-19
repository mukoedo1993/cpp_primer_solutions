#include<iostream>
#include<bitset>
#include<vector>
int main()
{
    long long unsigned llu1=1LLU<<1,llu2=1LLU<<2,llu3=1LLU<<3
    ,llu5=1LLU<<5,llu8=1LLU<<8,llu13=1LLU<<13,llu21=1LLU<<21;

      //part 1:
      std::bitset<32>ex1(llu1|llu2|llu3|llu5|llu8|llu13|llu21);
      std::cout<<ex1<<std::endl;


      //part 2:
      std::bitset<32>ex2;
      std::vector<int>v_i={1,2,3,5,8,13,21};
      for(auto i :v_i)
      {
          ex2[i]=1;
      }
      std::cout<<ex2<<std::endl;
}

//Result:
/*
00000000001000000010000100101110
00000000001000000010000100101110
*/