#include<algorithm>
#include<iostream>
//Q: The library max function has two function parameters and returns the larger of
//its arguments. THis function has one parameter type parameter. Could you call max
//passing it an int and a double? If so, how? If not, why not?

int main()
{
   int i=13;double d=14.3;
    
    //std::max(i,d);//error: max(int,double)isn't support

    std::cout<<std::max<int>(i,d)<<std::endl;//14

    std::cout<<std::max<double>(i,d);//14.3
}