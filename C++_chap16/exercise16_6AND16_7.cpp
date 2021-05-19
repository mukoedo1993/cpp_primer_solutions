#include<iostream>
#include<cstring>
//Basically, I managed to circumvent the std::begin(),std::end(), and strlen().
//I only used const_cast to get the beginning iterator of a c_str, 
//and advance it iteratively, until its value is a null char('\0')
template<unsigned M>char* begin1(const char(&p1)[M])
{
    char* p2=const_cast<char*>(p1);
    return p2;
}

template<unsigned M>char* end1(const char(&p1)[M])
{
    //char* p2=const_cast<char*>(p1);
    char *p2=begin1(p1);//call the begin1 function. Equivalent to the code of the line above.
    while(*p2!='\0')//null char
   {p2++;}
    
    return ++p2;
}

template<unsigned M>constexpr size_t size1(const char(&p1)[M])
{
    return end1(p1)-begin1(p1)-1;
}
int main()
{
    char c[]="kjj d";

   std::cout<<*begin1(c);//k
   auto it=end1(c);//it now points to the iterator past-the-end.
   it--;it--;
   std::cout<<std::endl<<*it;//d
   std::cout<<std::endl<<size1(c);//5
}