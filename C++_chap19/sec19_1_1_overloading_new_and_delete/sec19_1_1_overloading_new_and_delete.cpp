#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<new>
  /*The operator new and operator delete interface*/
    /*
    The library defines eight overloaded versions of operator new and delete functions.
    The first four support the versions of new that can throw a bad_alloc exception. 
    The next four support nonthrowing versions of new:
    */

   //these versions might throw an exception
  // void *operator new(size_t);//allocate an object
   //void *operator new[](size_t);//allocate an array
   //void *operator delete(void*)noexcept;//free an object
   //void *operator delete[](void*)noexcept;//free an object
   
    //versions that promise not to throw
    //void *operator new(size_t,nothrow_t&);//allocate an object
   //void *operator new[](size_t,nothrow_t&);//allocate an array
   //void *operator delete(void*,nothrow_t&)noexcept;//free an object
   //void *operator delete[](void*,nothrow_t&)noexcept;//free an object

   struct B{
       B(){}
       int *i_ptr;
       void *operator new(size_t size,int)
       {
             std::cout<<"B::operator new(size_t,int)\n";
           if(void *mem=malloc(size))
           return mem;
           else
           throw std::bad_alloc();
       }
       void operator delete (void *mem,int)
       {
           free(mem);
           std::cout<<"B::operator delete(void*,int) !\n";
         }
   };

   struct B1{
       B1(){}
       void *operator new(size_t sz,const std::nothrow_t&)noexcept{
          std::cout<<"call static B1::operator new(size_t sz,nothrow_t&)\n";
           if(void *mem=malloc(sz))
           return mem;
           else
           {
               throw std::bad_alloc();
           }
       }
           void operator delete(void* mem,const std::nothrow_t&,int)noexcept{
               std::cout<<"call static B1::free(mem,const std::nothrow_t,int)\n";
               free(mem);
           }
           void operator delete(void *mem)
           {
               std::cout<<"call static B1::free(mem)\n";
               free(mem);
           }
           
       };
 
   
int main()
{
    //new expressions
    std::string *sp=new std::string("a value");
    std::string *arr=new std::string[10];

    //When we use a delete expression to dlete a dynamically
    //allocated object.
    delete sp;//destroy *sp and free the memory to which sp points
    delete []arr;//destroy the elements in the array and free the memory
   sp=arr=nullptr;
/*
Applications can define operator new and operator delete functions in the 
global scope and/or as member functions. When the compiler sees a new or 
delete expression, it looks for the corresponding operator function to call. 
If the scope of the class, including any base classes. If the class has a member
operator new or operator delete, that function is used by the new or delete expression.
Otherwise, the compiler looks for a matching function in the global scope. If the compiler
finds a user-defined version, it uses that function to execute the new or delete expression. 
Otherwise, the standard library version is used.
::new
::delete
*/

  B (*it)[13]=static_cast<B(*)[13]>(B::operator new(13,15));//we define a dynamic 
  //ptr that points an array of 13 B.
  
  //B::operator delete(it,17);
 B::operator delete(it,17);
  
  B1 *it1=static_cast<B1*>(B1::operator new(1,std::nothrow));
  B1::operator delete (it1,std::nothrow,16);

   B1 *it2=static_cast<B1*>(B1::operator new(1,std::nothrow));
  delete it2;//B1::operator delete(void*);

  B1(*it3)[6]=static_cast<B1(*)[6]>(B1::operator new(6,std::nothrow));
  delete it3;
}

//Result:
/*
B::operator new(size_t,int)
B::operator delete(void*,int) !
call static B1::operator new(size_t sz,nothrow_t&)
call static B1::free(mem,const std::nothrow_t,int)
call static B1::operator new(size_t sz,nothrow_t&)
call static B1::free(mem)
call static B1::operator new(size_t sz,nothrow_t&)
*/
