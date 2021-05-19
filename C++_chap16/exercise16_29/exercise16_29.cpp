
#include<iostream>
#include<functional>
#include<vector>
using std::vector;
using std::function;

template<typename T>
void deleter1(T *t)
{delete t;}
template<class T>
void deleter2(T *t1)
{delete t1;}




template<class T>class Shared_ptr
{
    public:
    Shared_ptr(T *t1=nullptr,std::function<void(T*)> d=deleter1<T>):del(d){
        t=t1;//t1 is type T*, t is also type T*
        }
    Shared_ptr(Shared_ptr<T> &orig):t(orig.t){
    }
  
    /*
    {
        if(this!=&orig)
    {
        t=orig.t;*(orig.cnt)=*(orig.cnt)+1;cnt=orig.cnt;//cnt=cnt+1;
        }
        return *this;
    }
    */
     
     


    void reset(std::function<void(T*)>del_=deleter1<T>)
    {
      
       del=del_;
     
       
    }
   
   
    
     T& operator*()const
    {
        return *t;
    }
    T* operator->()const
    {
        return &this->operator*();
    }
      ~Shared_ptr()
    {
        delete t;
    }
   
    private:
    T *t;
    std::function<void(T*)>del;
  
 
    
};
 template<typename T>using partNo=std::pair<T,unsigned>;
 #include"aru.h"
int main()
{
       Blob<int>ia;//empty Blob<int>
       Blob<int>ib(ia);
       std::vector<int>*vi=new std::vector<int>({1,2,3,4,56,7});
       Blob<int>ic(vi);
       std::cout<<ic.size()<<" ";//6

}