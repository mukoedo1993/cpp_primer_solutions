#include<stdexcept>
#include<iostream>
#include<vector>
using namespace std;
void fcn()
{
     std::cout<<__LINE__<<std::endl;
    throw overflow_error("manmade error:(");
}
void fcn1()
{
    std::cout<<__LINE__<<std::endl;
    throw runtime_error("manmade error2.\n");
}


void fcn2()
{
    std::cout<<__LINE__<<std::endl;
    throw exception();
}

int main()
{
    int a=3;
    
    try{
     
     fcn();
    }catch(overflow_error eobj){
      cerr<<"store1\n";
     
    }catch(const runtime_error &re)
    {
     cerr<<"store2\n";
    
    }catch(exception){
cerr<<"store3\n";
    }
    //7
    //store1

     try{
     
     fcn1();
    }catch(overflow_error eobj){
      cerr<<"store1\n";
     
    }catch(const runtime_error &re)
    {
     cerr<<"store2\n";
    
    }catch(exception){
cerr<<"store3\n";
    }
    //12
    //store2

  
     try{
     
     fcn2();
    }catch(overflow_error eobj){
      cerr<<"store1\n";
     
    }catch(const runtime_error &re)
    {
     cerr<<"store2\n";
    
    }catch(exception){
cerr<<"store3\n";
    }  
    //19
    //store3
}