#include<vector>
#include<memory>
#include<iostream>
#include<stdexcept>
#include<utility>
using std::string;

 template<class>class BlobPtr;
 template<typename>class Blob;//needed for operator ==

template<typename T>class Blob{
    //each instantiation of Blob grant access to the version of
    //BlobPtr and the equality operator instantiated with the same type
    friend class BlobPtr<T>;
 
    public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //constructors
    Blob();
    Blob(std::initializer_list<T>i1);
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
    const T& back()const;
    T& operator[](size_type );
    const T& operator[](size_type)const;
    private:
    std::shared_ptr<std::vector<T>>data;
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
       return data->back();
   }
   template<typename T>
   T& Blob<T>::operator[](size_type i)
   {
       //if i is too big, check will throw, presenting access to a nonexistent element
       check(i,"subscript out of range");
       return (*data)[i];
   }

      template<typename T>
   const T& Blob<T>::operator[](size_type i)const
   {
       //if i is too big, check will throw, presenting access to a nonexistent element
       check(i,"subscript out of range");
       return (*data)[i];
   }


   template<class T>
   const T& Blob<T>::back()const{
       check(0,"back on empty Blob");
       return data->back();
   }

/*Blob Constructors*/
template<typename T>
Blob<T>::Blob()try:data(std::make_shared<std::vector<T>>()){/*empty body*/}
catch(const std::bad_alloc &e){abort();}
//Like our StrBlob default constructor, this constructor allocates an empty vector
//and stores the pointer to that vector in data. As we've seen, we use the class' own
//type parameter as the template argument of the vector we allocate.

template<typename T>
Blob<T>::Blob(std::initializer_list<T>i1)try:
data(std::make_shared<std::vector<T>>(i1)){}
catch(const std::bad_alloc &e){abort();}


/*Simplifying use of a template class name inside class code*/
template<typename T>class BlobPtr{
    public: 
    friend bool operator==(const BlobPtr &lhs,const BlobPtr &rhs)
    {
       if(lhs.wptr.lock()!=rhs.wptr.lock())return false;
        return lhs.curr==rhs.curr;
    }
     friend bool operator!=(const BlobPtr &lhs,const BlobPtr &rhs)
     {
         return !(lhs.curr==rhs.curr);
     }

     
   /* friend bool operator ==<T>
    (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator != <T>
    (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
*/


    BlobPtr()try:curr(0){}catch(const std::bad_alloc &e){std::cerr<<e.what()<<"; ";}
    BlobPtr(Blob<T>&a,size_t sz=0)try:
    wptr(a.data),curr(sz)
    {}catch(const std::bad_alloc &e){std::cerr<<e.what()<<"; ";}
    T& operator*()const
    {auto p=check(curr,"dereference past end");
    return (*p)[curr];//(*p)is the vector to which this object points
    }
     //increment and decrement
     BlobPtr& operator++();//prefix operators
     BlobPtr& operator--();
     BlobPtr operator++(int);//postfix operators
     BlobPtr operator--(int);
      T& let_print()
     {return (wptr.lock())->at(curr);}
     const T& let_print()const
     {return (wptr.lock())->at(curr);}
    private:
    //check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
    check(std::size_t,const std::string&msg)const{if((wptr.lock())->size()<=curr)
    throw std::out_of_range(msg);}
    //store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>>wptr;
    std::size_t curr;//current position within the array
    };

    /*Using a class template name outside the class template body*/
    //postfix: increment/decrement the object but return the unchanged value
    template<typename T>
    BlobPtr<T> BlobPtr<T>::operator++(int)
    {
        check(curr+1,"out_of_range on ++");
       //no check needed here; the call to prefix increment will do the check
       BlobPtr ret=*this;//save the current value
       this->operator++();//advance one element; prefix ++ checks the increment
       return ret;//return the saved state
    }

     template<typename T>
    BlobPtr<T> BlobPtr<T>::operator--(int)
    {
         check(curr,"out_of_range on --");
       //no check needed here; the call to prefix increment will do the check
       BlobPtr ret=*this;//save the current value
       this->operator--();//advance one element; prefix ++ checks the increment
       return ret;//return the saved state
    }
     template<typename T>
    BlobPtr<T>& BlobPtr<T>::operator--()
    { check(curr,"out_of_range on --");
       //no check needed here; the call to prefix increment will do the check
     
       (this->curr)--;//advance one element; prefix ++ checks the increment
       return *this;//return the saved state
    }
   template<typename T>
    BlobPtr<T>& BlobPtr<T>::operator++()
    { check(curr+1,"out_of_range on ++");
       //no check needed here; the call to prefix increment will do the check
     
      (this->curr)++;//advance one element; prefix ++ checks the increment
       return *this;//return the saved state
    }
   

    

    int main(){
        Blob<int> Biden1={1,2,3,4,5,6};
        const Blob<std::string>Biden2({"ko","cafe","mobile"});
        std::cout<<Biden1.back();
        std::cout<<std::endl<<Biden2.back();
        std::cout<<Biden1[2]<<std::endl;
        std::cout<<Biden2[1]<<std::endl;
        BlobPtr<int> Bla(Biden1);
       std::cout<<Bla.let_print()<<std::endl;//1
        auto Bla1=Bla.operator++(1);
       std::cout<<Bla.let_print()<<std::endl;//2
       std::cout<<Bla1.let_print()<<std::endl;//1
       Bla.operator++(2);Bla.operator++();
       std::cout<<Bla.let_print()<<std::endl;//4
        auto Bla2=Bla.operator--();
        auto Bla3=Bla2.operator--(1);
       std::cout<<Bla.let_print()<<std::endl;//3
       std::cout<<Bla2.let_print()<<std::endl;//2
        std::cout<<Bla3.let_print()<<std::endl;//3
        std::cout<<std::boolalpha;
        std::cout<<(Bla==Bla);//true
        std::cout<<(Bla!=Bla3);//false
        std::cout<<(Bla!=Bla2);//true
    }

    