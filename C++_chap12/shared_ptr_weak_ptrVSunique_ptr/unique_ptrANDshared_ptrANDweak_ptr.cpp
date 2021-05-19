//The library smart pointer types offer a good illustration of design choices faced by
//designers of templates.


//The obvious differ in how they let users override 
#include<memory>
#include<iostream>
#include<vector>
#include<functional>
using std::function;
using std::vector;
void deleter(int *i)
{delete []i;}
struct callit{
    void operator()(int *i){delete []i;}
};
int main()
{
    std::shared_ptr<int> dflt;//default constructor
    std::shared_ptr<int>dflt2ksdk(new int[10],[](int *i){delete []i;});//deleter added
    std::unique_ptr<int>ptr133_(new int(15));
    std::shared_ptr<int>ptri1(new int(13));//constructor takes a new pointer
    std::shared_ptr<int>ptri1_=std::make_shared<int>(14);//make_shared constructor
    std::shared_ptr<int>ptri11_(ptri1_);//copy constructor

    //std::shared_ptr<int>ptri22_(ptri1_.get());
    //We cannot take a pointer from which a shared_ptr holds.
    std::shared_ptr<int>ptri23_(ptr133_.release());//ok:
    std::cout<<std::boolalpha;
    std::cout<<ptri23_.use_count()<<" "<<ptri23_.unique()<<std::endl;//1 true
    ptri23_.reset();
   std::cout<<ptri23_.use_count()<<" "<<ptri23_.unique()<<std::endl;//0 false(use count is 0 rather than 1)
   int *nima=new int(18);
   ptri23_.reset(nima);

   //overload *operator
   std::cout<<*ptri23_<<" "<<ptri23_.unique()<<" "<<ptri23_.use_count()<<" ";//18 true 1
     //overload ->operator
     vector<int>vi={1,2,4,5,6};
     std::shared_ptr<vector<int>>sptrv=std::make_shared<vector<int>>(vi);
    sptrv->push_back(13);
    std::cout<<(sptrv->back());//13


   std::weak_ptr<int>wptr1;//default constructor
   std::weak_ptr<int>wptr2(wptr1);//copy constructor
   std::weak_ptr<int>wptr4(dflt2ksdk);//takes a shared_ptr
    
   wptr2=wptr1;//assignment(a weak_ptr)
   wptr2=ptri1;//assignment (a shared_ptr)(*ptri1==13)
   wptr1=wptr2;
   std::cout<<wptr2.expired()<<" "<<wptr2.use_count()<<std::endl;//use_count is 1 one rather than 0, false.
   wptr2.reset();
    std::cout<<wptr2.expired()<<" "<<wptr2.use_count()<<std::endl;//true 0
     std::cout<<wptr1.expired()<<" "<<wptr1.use_count()<<std::endl;//false 1
    std::cout<<*(wptr1.lock())<<std::endl;//13

  
  std::unique_ptr<int>u1;
  int *u1_=new int(18902);
  std::unique_ptr<int>u2(u1_);//constructor that takes a built-in pointer
  std::unique_ptr<int,void(*)(int*)>u22(new int[10],deleter);//The function type itself is a pointer here
  std::unique_ptr<int,decltype(deleter)*>u2sdfg(new int[10],deleter);
  //is a parameter here.
    // std::unique_ptr<int,void(int*)>u22_(new int[10],deleter);//error: the deleter is a pointer to void(int*)
    
    std::unique_ptr<int,function<void(int*)>>u33_(new int[10],deleter);//ok
    std::unique_ptr<int,function<decltype(deleter)>>u44_(new int[13],[](int *i){delete []i;});//ok
     std::unique_ptr<int,function<void(int*)>>u55_(new int[13],callit());//ok
     //function<...>could take a pointer to a function, or a lambda expression or a callable operator.
     std::greater<int> gtr_q;
     function<bool(int,int)>ob1(gtr_q);
     auto it22ms=u33_.release();//pass by return value: ok
     u55_.reset(u44_.release());//
     u55_.reset();//
}
