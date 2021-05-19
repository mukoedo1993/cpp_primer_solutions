#include<iostream>

/*Class-Template Partial Specializations*/
//A class template partial specialization is itself a template. Users must supp;y
//arguments for those template parameters that are not fixed by the specialization.

/*
//original,most general template


*/
template<class T>struct Remove_reference{
    typedef T type;
};

template<class T>struct Remove_reference<T&>{
    typedef T type;//lvalue references
};

template<class T>struct Remove_reference<T&&>{
    typedef T type;//rvalue references
};
//Because a partial specialization is a template, we start, as usual,



/*Specializing members but not the class*/
//Rather than specializing the whole template, we can specialize just specific member 
//functions. e.g.: 

template<typename T>struct Foo{
    Foo(const T&t=T()):mem(t){}
    void Bar(){std::cout<<"\ngeneral Foo<T>::Bar()!\n";}
    T mem;
};

template<>//we're specializing a template
 void Foo<int>::Bar()//we're specializing the Bar member of Foo<int>
{
    std::cout<<"\n void Foo<int>::Bar()\n";
    //do whatever speicalized processing that applies to ints
}


int main(){
     int i;
     //decltype(42) is int, uses the original template
     Remove_reference<decltype(42)>::type a;
     //decltype(i) is int&,use first T& partial specialization
     Remove_reference<decltype(i)>::type b;

     //decltype(std::move(i))is int&&, use second(i.e., T&&)partial specialization
     Remove_reference<decltype(std::move(i))>::type c;


     Foo<std::string>fs;//instantiates Foo<string>::Foo()
     fs.Bar();//instantiates Foo<string>::Bar()

     Foo<int>fi;//instantiates Foo<int>::Foo()
     fi.Bar();//instantiates Foo<int>::Foo()
     //When we use Foo with any type other than int, members are instantiated as usual.
     //If we use the Bar member of Foo<int>, then we get our specialized definition.
}

//Result:
/*

general Foo<T>::Bar()!

 void Foo<int>::Bar()

*/