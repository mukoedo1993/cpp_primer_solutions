#include<bitset>
#include<iostream>
using std::bitset;
int main()
{
   bitset<64>bitvec(32);
   bitset<32>bv(1010101);
   
   std::cout<<bitvec<<std::endl;
   std::cout<<bv<<std::endl;
   //0000000000000000000000000000000000000000000000000000000000100000
//00000000000011110110100110110101

   std::string bstr;
   std::cin>>bstr;
   bitset<8>bv1(bstr);
   std::cout<<bv1;
   std::cout<<std::endl<<"bv1 start is: "<<bv1[0];
}

//test 1: "str"
/*
str
terminate called after throwing an instance of 'std::invalid_argument'
  what():  bitset::_M_copy_from_ptr
*/

//test2: "10101"
//result: 00010101

//test3:"110010100011"
//result: 11001010
//comment: here, bitset<8> only takes first 8 chars from the cin. str[7]->bv1[0],
//str[6]->bv1[1],str[5]->bv1[2],...,str[0]->bv1[7].

//test4:"101010102"
//result:10101010
//It ends normally without the throwing of 'std::invalid_argument'.