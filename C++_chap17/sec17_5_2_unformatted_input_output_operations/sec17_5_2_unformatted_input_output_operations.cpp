//The library also provides a set of low-level operations that support
//unformated IO. These operations let us deal with a stream as a sequence
//of uninterpreted bytes.
#include<iostream>
int main()
{
    /*single-byte operations*/
    char ch;
    while(std::cin.get(ch)&&ch!='q')
    std::cout.put(ch);
   //This program preserves the whitespace in the input. Its output is identical
   //to the input. It executes the same way as the previous program that used
   //noskipsws.

   /*Putting back onto an input stream*/
}

