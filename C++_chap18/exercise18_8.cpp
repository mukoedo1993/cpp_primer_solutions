#include<memory>
#include<functional>
#include<vector>
#include<fstream>
#include<iostream>
#include<array>
//cls1 is the soln. to the exercise18_8:
struct cls1{
    
    cls1(size_t sz=0)noexcept{ int_ptr=new int[sz]();}
    ~cls1()noexcept{delete []int_ptr;}
    int* int_ptr;
};
struct cls2{
    
    cls2(size_t sz=0){ int_ptr=new int[sz]();}
    ~cls2(){delete []int_ptr;}
    int* int_ptr;
};

void exercise(int *b,int *e)
{
    std::vector<int>v(b,e);
     cls1 p(v.size());
    std::ifstream in("ints");//this object will be destroyed properly
    
    throw std::invalid_argument("Motherf**ker!");

    //exception occurs here
}

int main()
{
    //If we don't comment the line below:
   //try{cls1(-4);}catch(...){/*...*/}
   /*
   terminate called after throwing an instance of 'std::bad_array_new_length'
  what():  std::bad_array_new_length
   */

   try{cls2(-5);}catch(std::bad_alloc&err){std::cerr<<err.what()<<"\n"
  <<"\n";}//std::bad_array_new_length
}