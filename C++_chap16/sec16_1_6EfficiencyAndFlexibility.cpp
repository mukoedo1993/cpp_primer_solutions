#include<iostream>
#include<functional>
#include<vector>
using std::vector;
using std::function;
//Shared_ptr: I didn't implement the shared_ptr's parameter to take another 
//built-in pointer. I couldn't use it without advanced knowledge.
template<typename T>
void deleter1(T *t)
{delete t;}
template<class T>
void deleter2(T *t1)
{delete t1;}


class cn
{
    template<class T>  friend class Shared_ptr;
    cn(int i1):i(i1){}
    cn():i(0){}
    operator int()const{return i;}
    int i=0;
    
};

template<class T,class D=function<void(T*)>>class Unique_ptr
{

    public:
    Unique_ptr(T *t1=nullptr,D d1=deleter1<T>):del(d1),t(t1){    
    }
    Unique_ptr(const T&)=delete;
    ~Unique_ptr()
    {
        delete t;
    }
    private:
    D del;
    T *t;

};
template<class T>class Shared_ptr
{
    public:
    Shared_ptr(T *t1=nullptr,std::function<void(T*)> d=deleter1<T>):del(d){
        t=t1;//t1 is type T*, t is also type T*
        if(t1==nullptr)cnt->i=0;else cnt->i=1;
        }
    Shared_ptr(Shared_ptr<T> &orig):t(orig.t){
    if(this!=&orig&&(orig.cnt)->i!=0){orig.cnt->i=orig.cnt->i+1;}
    if(this!=&orig)cnt=orig.cnt;
    }
    Shared_ptr& operator=( Shared_ptr&orig)=delete;
    /*
    {
        if(this!=&orig)
    {
        t=orig.t;*(orig.cnt)=*(orig.cnt)+1;cnt=orig.cnt;//cnt=cnt+1;
        }
        return *this;
    }
    */
    T* get()
    {return t;}
    bool unique()
    {
       return(use_count()==1);
    }
    int use_count()
    {
        return *cnt;
    }

    void reset(std::function<void(T*)>del_=deleter1<T>)
    {
      
       del=del_;
     
       
    }
   
   
    
     T& operator*()
    {
        return *t;
    }
      ~Shared_ptr()
    {
        if(cnt==nullptr)return;
        if((cnt->i)!=0)
         {cnt->i=cnt->i-1;std::cout<<cnt->i<<std::endl;}
        if(cnt->i==0)
        {delete t;
        std::cout<<"Coup de gracia!\n"<<cnt->i<<std::endl;
        }
    }
   
    private:
    cn *cnt;
    T *t;
    std::function<void(T*)>del;
  
 
    
};
int main()
{
    int *ip1=new int(10);
    Shared_ptr<int>sptr;
    std::cout<<sptr.use_count()<<" ";//0
   Shared_ptr<int>sptr1(ip1);//sptr1.use_count()==1
   Shared_ptr<int>sptr2(sptr1);//sptr2.use_count()==2
   std::cout<<sptr2.use_count()<<" "<<__LINE__<<std::endl;//2 113
   Shared_ptr<int>sptr3;
   Shared_ptr<int>sptr114(sptr3);
   std::cout<<sptr114.use_count()<<" ";//0
   sptr3.reset(deleter2<int>);
   std::cout<<*sptr1;//10
   *sptr2=13;sptr1.reset();
  std::cout<<" "<<sptr2.use_count()<<std::endl;//2
  sptr2.reset();
  std::cout<<" "<<sptr2.use_count();//0
  Unique_ptr<int>uptr1;
  Unique_ptr<int>uptr2;
  int *up_tst1=new int(-19);
  int *up_tst2=new int[10];
  delete up_tst2;up_tst2=nullptr;
  int *up_tst3=new int(-2394);
  Unique_ptr<int>uptr3(up_tst1);
  Unique_ptr<int,function<void(int*)>>uptr4(up_tst3,deleter2<int>);
}

/*

0 2 114
0 10 2
 2Coup de gracia!
0
Coup de gracia!
0
1
0
Coup de gracia!
0
Coup de gracia!
0

*/