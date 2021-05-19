#ifndef BLOB_CHAP16_2_3_H
#define BLOB_CHAP16_2_3_H
#include<iostream>
#include<memory>
#include<vector>
#include<stdexcept>
using std::vector;

template<class T>class Blob{
    //...
    public:
    
    template<typename It>Blob(It b,It e);
    Blob(std::initializer_list<T> i):data(std::make_shared<vector<T>>(i.begin(),i.end())){}
    Blob(const Blob&orig){data=orig.data;}
    T operator[](size_t sz)const
    {
        return (*(data.get()))[sz];
    }
    void print_all()
    {
        for(auto it=data->cbegin();it!=data->cend();it++)
        std::cout<<*it<<" ";
        std::cout<<std::endl;
    }
     template<typename T1>
  T1 begin()const
   {   T1 mkft=(data->begin());
       return mkft;
   }
   template<typename T1>
     T1 end()const
   {   T1 mkft=(data->end());
   }



    private:
     std::shared_ptr<vector<T>>data;
};

template<typename T>
template<typename It>Blob<T>::Blob(It b,It e):data(std::make_shared <vector<T>>(b,e) )
{
}

template<typename T>
bool compare(const T&lhs,const T&rhs)
{
    std::cout<<"compare!!!\n";return lhs<rhs;
}

#endif