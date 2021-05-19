#include<vector>
#include<memory>
#include<iostream>
#include<stdexcept>
#include<utility>
using std::string;
//template<class T>class Shared_ptr;

 template<typename>class Blob;//needed for operator ==
 template<typename T>
 bool operator==(const Blob<T>&,const Blob<T>&);
 
template<typename T>class Blob{
   
    
    friend bool operator==<T>(const Blob<T>&,const Blob<T>&);
    public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //constructors
    Blob();
    Blob(std::vector<T>*i1);
    //number of elements in the Blob
    size_type size()const{return data->size();}
    bool empty()const {return data->empty();}
    //add and remove elements
    void push_back(const T&t){data->push_back(t);}
    //move version; see &15.6.3(p.548)
    void push_back(T &&t);//{data->push_back(std::move(t));}
    void pop_back();
    //element access
    T& back();
    T& operator[](size_type );
    private:
    Shared_ptr<std::vector<T>> data;
    //throws msg if data[i] isn't valid
    void check(size_type i,const std::string&msg)const;
    
    
};
template<typename T>
void Blob<T>::push_back(T &&t){data->push_back(std::move(t));}


   template<typename T>
   void Blob<T>::check(size_type i,const std::string&msg)const{
       if(i>=data->size())
       throw std::out_of_range(msg);
   }

   template<class T>
   T& Blob<T>::back()
   {
       check(0,"back on empty Blob");
   }
   template<typename T>
   T& Blob<T>::operator[](size_type i)
   {
       //if i is too big, check will throw, presenting access to a nonexistent element
       check(i,"subscript out of range");
       return (*data)[i];
   }

/*Blob Constructors*/
template<typename T>
Blob<T>::Blob():data(){

}

template<typename T>
Blob<T>::Blob(std::vector<T>*i1):data(i1){
}

