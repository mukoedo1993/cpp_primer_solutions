#include<iostream>
#include<stdexcept>
#include<cstdlib>
class exceptionType{
    public: exceptionType(const std::string&str){messge=str;}
    std::string messge;
};

int main()
{
   try{
       exceptionType ext(std::string("nmsl"));
       auto *ext2=&ext;
       throw ext2;
   }
   catch(exceptionType *pet)
   {
       pet->messge="hehe";
       std::cerr<<pet->messge;
   }

    try{
       exceptionType ext(std::string("nmsl"));
       auto *ext2=&ext;
       throw ext2;
   }
   catch(...)
   {
       
       std::cerr<<"error detected!\n";
   }
   typedef int EXCPTYPE;
   try{
       int i=13;
       throw i;
   }
   catch(EXCPTYPE l2)
   {
       
      std::cerr<<l2<<std::endl;
   }
}

/*

heheerror detected!
13
*/