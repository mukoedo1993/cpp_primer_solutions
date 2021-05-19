#include<bitset>
#include<iostream>
//As soon as we know the correct answers, it's convenient to assume that we know
//the size of the test.
template<class T>
size_t generate_grade(const T&bN,const T&corrt)
{
    size_t sz=0;
   for(size_t i=0;i<bN.size();i++)
   {
     if(bN[i]==corrt[i])
      sz++;
   }
   return sz;
}
int main()
{
   std::bitset<10>corr("1100101010") ;//correct solution
   std::bitset<10>yaju("0011010011");//student's answers
   std::cout<<generate_grade(corr,yaju);//2

}