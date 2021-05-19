#include<type_traits>
#include<iostream>
#include<vector>
#include<memory>
template<typename T>
  auto Move(T &&t)->typename std::remove_reference<T>::type&&
  { 
           
      return  static_cast<typename std::remove_reference<T>::type&&>(t);

  }
template<class T,typename... Args>
auto Make_shared( Args&&... args)->std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

class B{
    public:
    void fcn(const int&){std::cout<<"fcn(const int&)\n";}
    void fcn(int&&){std::cout<<"fcn(int&&)\n";}
};
struct B1{
    public:
    B1(int,int,int){}
};

int main()
{
    int i=5;
    const int i1=6;
   // Move(i);
 B().fcn(Move(i));
 B().fcn(i);
 B().fcn(Move(i1));
 std::string str1="nimas",str2;
 str2=Move(str1);
 std::cout<<str1<<"str1";//It doesn't print here.
auto it=Make_shared<B1>(3,4,5);
std::cout<<it.use_count();
}