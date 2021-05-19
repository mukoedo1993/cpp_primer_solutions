#include<iostream>
#include<array>
#include<memory>
#include<algorithm>
#include<vector>
#include<list>
using std::list;
using std::vector;
/*Mmeber templates of ordinary nontemplate classes*/
//As an example of an ordinary class that has a member template, 
// we'll define a class that is similar to the default deleter type used
//by unique_ptr
class DebugDelete{
    public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}
    template<class T>void operator()(T *p)const &
    {os<<"const & deleting unique_ptr"<<std::endl;delete p;}
     template<class T>void operator()(T *p)&&
    {os<<"&& deleting unique_ptr"<<std::endl;delete p;}
    private:
    std::ostream &os;
};
//Because calling a DebugDelete object delete its given pointer, we can also use
//DebugDelete as the deleter of a 


/*Member Template of class templates*/
//We can also define a member template of a class template. In this case, both the class
//and the member have their own, independent, template parameters.

//As an example, we will give our Blob class a constructor that will take two iterators
//denoting a range of elements to copy. Because we'd like to support iterators...
template<class T>class Blob{
    //...
    public:
    template<typename It>Blob(It b,It e);
    void print_all()
    {
        for(auto it=data->cbegin();it!=data->cend();it++)
        std::cout<<*it<<" ";
        std::cout<<std::endl;
    }
    private:
     std::shared_ptr<vector<T>>data;
};

template<typename T>
template<typename It>Blob<T>::Blob(It b,It e):data(std::make_shared <vector<T>>(b,e) )
{
}

//THe parameter list 
int main()
{
    int vector=3;
    double *p=new double;
    DebugDelete d;//an object that can act like a delete expression
    d(p);//calls DebugDelete::operator()(delete*), which deletes p.
    int *ip=new int;
    //calls operator ()(int*) on a temporary DebugDelete a object
    DebugDelete()(ip);//Here, we call a temporary object of DebugDelete
   
   int b[3]={1,2,3};auto *c=&b;
   std::shared_ptr<int>a0(new int[10],std::default_delete<int[]>());
   std::shared_ptr<int>a(a0);
    std::cout<<a.use_count()<<" at line: "<<__LINE__<<std::endl;
  std::unique_ptr<int[]>a_(new int[10]);
  *(a_.get())=3;
 // a_++;//error: we just override the a_'s deleter function. a_ is just A shared_ptr<int> that
  //points to int[].
  auto b1=a_.get();
  b1++;*(b1)=4;


  std::for_each(a_.get(),a_.get()+10,[&a_](int i){std::cout<<i<<" ";});
  std::cout<<std::endl;
  //Those two for_each are equivalent: 
   std::for_each(a_.get(),a_.get()+10,[&](int i){std::cout<<i<<" ";});
  std::cout<<std::endl;
  

  std::for_each(a.get(),a.get()+10,[a](int i){std::cout<<i<<" "
  <<a.use_count()<<
  " ";});//the a's use_count is always 2, because we catch it.
  std::cout<<a.use_count()<<std::endl;//i time only here.

   /*
   Because calling a DebugDelete object that deletes the given pointer,
   we can also use DebugDelete as the deleter pf a unique_ptr. To override the deleter
   of a unique_ptr, we supply the type of the deleter inside brackets and supply an object
   of the deleter type to the constructor
   */
   //destroying the objectto which p points
   //instantiates DebugDelete::operator()(int *p){delete p;}
   std::unique_ptr<int,DebugDelete>p1(new int,DebugDelete());
   //destroying the object tp which sp1 points
   //instantiates DebugDelete::operator()<string>(string*)
   std::unique_ptr<std::string, DebugDelete>sp1(new std::string, DebugDelete());
   
    /*Instantiation and Member Templates*/
    int ia[]={-0,-1,2,-3,4,5,6,7,8,9};
     std::vector<long>vi={0,1,2,3,4,5,6,7,8,9};
     //instantiates the Blob<int>constructor that has
     //two vector<int>::iterator parameters
     Blob<int>a_ichi(std::begin(ia),std::end(ia));
     std::cout<<std::endl;
    a_ichi.print_all();
     
     list<const char*>l_w={"now","is","the","time"};
       Blob<int>a_ni(vi.cbegin(),vi.cend());
       a_ni.print_all();std::cout<<std::endl;
       Blob<std::string>a_san(l_w.cbegin(),l_w.cend());
       a_san.print_all();std::cout<<std::endl;
}

/*

const & deleting unique_ptr
&& deleting unique_ptr
2 at line: 66
3 4 0 0 0 0 0 0 0 0 
3 4 0 0 0 0 0 0 0 0 
0 3 0 3 0 3 0 3 0 3 0 3 0 3 0 3 0 3 0 3 2

0 -1 2 -3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 

now is the time 

const & deleting unique_ptr
const & deleting unique_ptr

*/