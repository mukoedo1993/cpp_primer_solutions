#include<iostream>
template<typename T>int compare(const T&v1,const T&v2)
{
    if(v1<v2)return -1;
    if(v1>v2)return 1;
    return 0;
}



//In some situations, it is not possible for the compiler to deduce the
//types of the template arguments.
//In others, we want to allow the user to control the template instantiation.
//Both cases arise most often when a function return type differs from any of those
//used in parameter list.


/*Specifying an explicit template argument*/
//T1 cannot be deduced; it doesn;t appear in the function parameter list
template<class T1,typename T2,class T3>T1 sum(T2 b,T3 c)
{
    T1 a=b+c;
    return a;
}

//poor design, users must explicitly specify all threee template parameters
template<class T1,class T2,typename T3>T3 alternative_sum(T2 b,T1 a)
{
    T3 c=b+a;
    return c;
}


int main()
{
    //In this case, there is no argument whose type can be used to deduce he type of 
    //T1. The caller must provide an explicit template argument for this parameter
    //on each call to sum.

    //T1 is explicitly specified; T2 and T3 are inferred from the argument type
    int i=13;
    long lng=1236;
    auto val3=sum<long long>(i,lng);
  

  //auto value4= alternative_sum<long long>(i,lng);//error: can't infer initial template parameters
  //


   auto value5=alternative_sum<long long,int,long>(i,lng);//ok: all three parameters are explicitly specified

     /*normal conversions apply for explicitly specified arguments*/
     long lng2;
     //compare(lng2,1024);//error: template parameters doesn;t match
     compare<long>(lng2,1024);//ok: intsantiates compare(long,long)
     compare<int>(lng2,1024);//ok: instantiates compare(int,int)
     
}