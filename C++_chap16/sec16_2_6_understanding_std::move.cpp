#include<iostream>
#include<type_traits>
using std::string;

/*How std::move is defined*/
//We could reconstruct std::move like this:
template<typename T>
typename std::remove_reference<T>::type&& move1(T&& t)
{
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

template<typename T>constexpr
 typename std::remove_reference<T>::type&& move4(T&& orig)
{
    return static_cast<typename std::remove_reference<T>::type&&>(orig);
}

int main()
{
  string s1("hi!"),s2;
  s2=move1(s1);
  std::cout<<s2<<". "<<s1<<". \n";//hi!. . \n
  //We could see,
}