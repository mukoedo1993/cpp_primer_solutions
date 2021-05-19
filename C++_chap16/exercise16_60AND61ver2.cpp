#include<iostream>
#include<memory>
#include<cstring>
template<typename T,typename... Ts>
std::unique_ptr<T> Make_unique(Ts&&... params)//
{
    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}
template<class T, class... Ts>
std::shared_ptr<T> Make_shared(Ts&&... params)
{
    return std::shared_ptr<T>(new T(std::forward<Ts>(params)...));
}
struct I//built-in type
{
    I(int,int,int){}
};

struct kichiku//user-defined type
{
   kichiku(std::string a,std::string b,std::string c):a_(a){
             
            

   }
   void print()const
   {
       (std::cout)<<(*this);
       }

   friend
   std::ostream& operator<<(std::ostream&os,const kichiku&orig)
{
    os<<orig.a_<<" ";
    return os;
}
   private:
   std::string a_;
   
   
};




int main(){

    int i=13;
    auto rslt1=Make_shared<I>(i,i,i);//OK
    auto rslt2=std::make_shared<I>(i,i,i);//OK

    auto rslt3=Make_shared<kichiku>("ni","ma","si");
    rslt3->print();//ni
    std::cout<<'\n'<<rslt3.use_count()<<" ";
}
/*
ni 
1 
*/