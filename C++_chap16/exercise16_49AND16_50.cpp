#include<iostream>
using std::cout;

template<class T>void f(T)
{
    cout<<"\ntemplate<class T>void f(T)\n";
}

template<typename T>void f (const T*)
{
    cout<<"\ntemplate<typename T>void f (const T*)\n";
}

template<typename T>void g(T)
{
    cout<<"\ntemplate<typename T>void g(T)\n";
}

template<class T>void g(T*)
{
    cout<<"\ntemplate<class T>void g(T*)\n";
}

int main()
{
    int i=42,*p=&i;
    const int ci=43,*p2=&ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);//template<class T>void f(T) (T* is better than const T*, as soon as the latter
    //one required a low-level const converging.)
    f(ci);
    f(p2);
}

/*


template<typename T>void g(T)

template<class T>void g(T*)

template<typename T>void g(T)

template<class T>void g(T*)

template<class T>void f(T)

template<class T>void f(T)

template<class T>void f(T)

template<typename T>void f (const T*)

*/