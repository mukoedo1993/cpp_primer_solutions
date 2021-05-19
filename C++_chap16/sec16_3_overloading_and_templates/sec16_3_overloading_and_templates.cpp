#include<iostream>
#include<sstream>
/*Overloading and Templates*/


//Function matching is affected by the presence of function templates
//in the following ways:
//1: The candidate functions for a call include any function-template instantiation
//for which template argument deduction succeeds.
//2: The candidate function templates are always viable, because template argument
//deduction will have eliminated any templates that are not viable.
//3: As usual, if exactly one function provides a better match than any of the others,
//that function is selected. However, if there are several functions that provide an
//equally good match, then:

//3_1: If there is only one nontemplate function in the set of equally good matches,
//the nontemplate function is called.

//3_2: If there are non notemplate function in the set, but there are multiple function
//templates, and one of these templates is more specialized than  any of others, 
//the more specialized function template is called.
//Otherwise, the call is ambiguous.

/*Writing overloaded templates*/
template<class T1,class T2>void fcn(T1 t1,T2 t2)
{
   std::cout<<"template<class T1,class T2>void fcn(T1 t1,T2 t2)\n";
}

template<class T>void fcn(T t1,T t2)
{
    std::cout<<"\ntemplate<class T>void fcn(T t1,T t2)\n";
}

/*Writing Overloaded Templates*/
//print any type we don't otherwise handle
template<typename T>std::string debug_rep(const T&t)
{
    std::cout<<"\n\template<typename T>std::string debug_rep(const T&t)\n";
    std::ostringstream ret;
    ret<<t;//use T's output operator to print a representation of t
    return ret.str();//return a copy of the string to which ret is bound
}

//print pointers as their pointer type, followed by the object to which the pointer 
//points
//NB: this function will not work properly with char*
template<class T>std::string debug_rep(T *p)
{
    std::cout<<"\ntemplate<class T>std::string debug_rep(T *p)\n";
    std::ostringstream ret;
    ret<<" pointer: "<<p;//print the pointer's own value:
    if(p)
    ret<<" "<<debug_rep(*p);//print the value to which p points
    else
    {
        ret<<" nullptr ";//or indicate that the p is null
    }
    return ret.str();//return a copy of the string to which ret is bounded

    
}

std::string debug_rep(const std::string &s)
{
    return '"'+s+'"';
}

//convert character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char*p)
{
    return debug_rep(std::string(p));
}

int main()
{
   fcn(1.34,1.56);//rules 3_2: fcn(T,T)is more specialized than fcn(T1,T2).
   fcn<double>(1.34,1.56);//
   fcn<double,double>(1.34,1.56);


   std::string s("hi");
   std::cout<<debug_rep(s)<<std::endl;
   //const T&t and const string&t are equally well. So, the non tmeplate function wins out
   //here.

   //If we call:
   std::cout<<debug_rep(&s)<<std::endl;
   //rule3: a const change in low-level is inferior to an exact match.
   //debug_rep(const string*&)<debug_rep(string*)


   const std::string *sp=&s;
   std::cout<<debug_rep(sp)<<std::endl;
   //debug_rep(const string *)VS debug_rep(const string *&) both are exactly matches.
   //But Type of lhs is string*, Type of rhs is const string*. lhs is better than rhs.
   //rule 3_2: because lhs  (const T&) could be called on essentially any type,
   //but const T* are much narrower.


   /*Overloaded Templates and conversions*/
   std::cout<<debug_rep("hi world")<<std::endl;
   //3 types:
   //debug_rep(const T&),with T bound to char[10]
   //debug_rep(T*),with T bound to const char
    //debug_rep(const string&). Here user_defined conversion form char[10] to string is
    //required.

   
}

/*


template<class T>void fcn(T t1,T t2)

template<class T>void fcn(T t1,T t2)
template<class T1,class T2>void fcn(T1 t1,T2 t2)
"hi"

template<class T>std::string debug_rep(T *p)

        emplate<typename T>std::string debug_rep(const T&t)
 pointer: 0x7fffffffe170 hi

template<class T>std::string debug_rep(T *p)

        emplate<typename T>std::string debug_rep(const T&t)
 pointer: 0x7fffffffe170 hi
"hi world"

*/