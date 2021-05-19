
#include <iostream> 
using namespace std; 
  
class Test 
{ 
public: 
    Test()  { cout << "Constructor is executed\n"; } 
    ~Test() { cout << "Destructor is executed\n";  } 
   // friend void fun(Test t); 
}; 
void fun(Test t) 
{ 
    std::cout<<"first fun() statement: ";//before this line, there is niether constr nor destr called in the fun()
    Test(); //constructor and destructor of a temporary object is called
    std::cout<<"second fun() statement: ";
    t.~Test(); //destructor of t called
    std::cout<<"Just before the end of the fun.\n";
    //destructor of t called
} 
int main() 
{ 
     std::cout<<"Line 24: ";
    Test(); //temporary object: constr and destr are called.
    std::cout<<"Line 26: ";
    Test t; //default constructor
    std::cout<<"Line 28: ";
    fun(t); 
    std::cout<<"Instantly after the end of fun()\n";
    return 0; 
} 