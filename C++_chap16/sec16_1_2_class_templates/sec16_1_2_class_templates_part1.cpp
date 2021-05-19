/*class template*/
//A class template is a blueprint for generating class.
//Class templates differ from function templates in that the compiler cannot deduce the 
//template parameter type(s) for a class template


/*Defining a class template*/
//As an example, we'll implement a template version of StrBlob. We'll name our template
//Blob to indicate that it is no longer specific to strings.
#include<vector>
#include<memory>
#include<iostream>
#include<stdexcept>
#include<utility>
using std::string;

 /*class templates and friends*/
 //When a class contains a friend declaration, the class and the friend can independently
 //be templates or not. A class template that has a nontemplate friend grants that friend 
 //access to all the instantiations of the template. WHen the friend is itself a template,
 // the class granting friendship controls whether friendship includes all instantiations
 //of the template or only specific instantiation(s).

 /*ONE TO one firendship*/
 template<class>class BlobPtr;
 template<typename>class Blob;//needed for operator ==
 template<typename T>
 bool operator==(const Blob<T>&,const Blob<T>&);
 
template<typename T>class Blob{
    //each instantiation of Blob grant access to the version of
    //BlobPtr and the equality operator instantiated with the same type
    friend class BlobPtr<T>;
    
    friend bool operator==<T>(const Blob<T>&,const Blob<T>&);
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
    T& operator[](size_type );
    private:
    std::shared_ptr<std::vector<T>>data;
    //throws msg if data[i] isn't valid
    void check(size_type i,const std::string&msg)const;
    
    //error: nonmember operator requires a parameter with class or enum type
    //friend constexpr bool operator==<T>(T ob1,T ob2);
    
};
template<typename T>
void Blob<T>::push_back(T &&t){data->push_back(std::move(t));}

//Our Blob template has one template type parameter, named T. We use the type
//parameter anywhere we refer to the element type that the Blob holds. For example,
//we define the return type of the operations that provide access to the elements in
//the Blob as T&. When a user instantiates a Blob, these uses of T will be replaced
//by the specified template argument type.
//With the exception of the template parameter list, and the use of T instead of string,
//this class is the same as the version in 12.1.1 and updated in 12.1.6 and in Chap. 13 and 14.

/*Instatntiating a Class Template*/
//We can now see that extra information is a list of explicit template arguments that
//are bound to the template's parameters. The compiler uses these template arguments to
//instantiate a specific class from the template.

/*example*/
/*
template <typename T>
void Blob<T>::check(size_type i,const std::string &msg)const
{
    if(i>=data->size())
    throw std::out_of_range(msg);
}
*/
//Aside from the differnces in the class name and the use of the template parameter list,
//this function is identical to the original StrBlob member.
/*The check and ELement access members*/
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
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()){}
//Like our StrBlob default constructor, this constructor allocates an empty vector
//and stores the pointer to that vector in data. As we've seen, we use the class' own
//type parameter as the template argument of the vector we allocate.

template<typename T>
Blob<T>::Blob(std::initializer_list<T>i1):
data(std::make_shared<std::vector<T>>(i1)){}


/*Simplifying use of a template class name inside class code*/
template<typename T>class BlobPtr{
    public: 
    BlobPtr():curr(0){}
    BlobPtr(Blob<T>&a,size_t sz=0):
    wptr(a.data),curr(sz){}
    T& operator*()const
    {auto p=check(curr,"dereference past end");
    return (*p)[curr];//(*p)is the vector to which this object points
    }
     //increment and decrement
     BlobPtr& operator++();//prefix operators
     BlobPtr& operator--();
     BlobPtr operator++(int);//postfix operators
     BlobPtr operator--(int);
    private:
    //check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
    check(std::size_t,const std::string&)const;
    //store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>>wptr;
    std::size_t curr;//current position within the array
    };

    /*Using a class template name outside the class template body*/
    //postfix: increment/decrement the object but return the unchanged value
    template<typename T>
    BlobPtr<T> BlobPtr<T>::operator++(int)
    {
       //no check needed here; the call to prefix increment will do the check
       BlobPtr ret=*this;//save the current value
       ++*this;//advance one element; prefix ++ checks the increment
       return ret;//return the saved state
    }



    /*General and specific template friendship*/
    //A class can also make instantiation of another template its friend, or it
    //may limit friendship to a specific instantiation:
    //forward declaration necessary to befriend a specific instantiation of a template
    template<typename T>class Pal;
    class C{
        friend class Pal<C>;//Pal instantiated with class C is a friend to C
       //all instances of Pal2 are friends to C
       //no forward declaration required when we befriend all instantiations
       //one more example: 
       friend class Pal<unsigned>;

       template <typename T>friend class Pal2;
       //Pal3 is a nontemplate class that is a friend of every instance of C2
       friend class Pal3;//prior declaration for Pal3 not needed
    };
      
      /*Befriendsing the Template's own type parameter:*/
      template<class Type>class Bar{
          friend Type;//grants access to the type used to instantiate Bar
          //...
      };
    //Under the new standard, we can make a template type parameter a friend:





  template<typename T>using twin=std::pair<T,T>;
twin<int>win_loss;//win_loss is a pair<int,int>
twin<double>area;//area is a pair<double,double>
 template<typename T>using partNo=std::pair<T,unsigned>;
//partNo<Vehicle>cars;//cars is a pair<Vehicle,unsigned>
//partNo<Student>kids;//kids is a pair<Student, unsigned>


/*static members of class templates*/

int main()
{
   Blob<int>ia;//empty Blob<int>
   Blob<int>ia2={0,1,2,3,4};//Blob<int> with five elements
   
   //these definitions instantiate two distinct Blob types
   Blob<string>names;//Blob that holds strings
   Blob<double>prices;//differnt element type
   //Blob<T->string>names is triggered
   //Blob<T->double>prices is triggered.
   //As with any other class, members defined inside the class body are implicitly
   //inline.
   Blob<string>articles={"a","an","the"};
   std::cout<<articles[1];//an
   
   /*Instatination of Class-Template Member functions*/
   Blob<int>squares{0,1,2,3,4,5,6,7,8,9};
   for(size_t i=0;i!=squares.size();++i)
   squares[i]=i*i;//instantiate Blob<int>::operator[](size_t)

   Blob<char>ca;//BlobPtr<char>and operator==<char>are friends
   
//However, using: the using:
 
  partNo<std::string>books;//books is a pair<T,unisgned>
   books=std::make_pair(std::string("sjd"),13);
    std::cout<<books.second;//13


}