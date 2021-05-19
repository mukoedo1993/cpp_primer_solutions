#include<memory>
#include<functional>
#include<vector>
#include<fstream>
#include<iostream>
#include<array>
struct cls1{
    
    cls1(size_t sz=0){ int_ptr=new int[sz]();}
    ~cls1(){delete []int_ptr;}
    int* int_ptr;
};

void exercise(int *b,int *e)
{
    std::vector<int>v(b,e);
     cls1 p(v.size());
    std::ifstream in("ints");//this object will be destroyed properly
    
    throw std::invalid_argument("Motherf**ker!");

    //exception occurs here
}

int main()
{
    int coco[5]={1,2,3,4,5};
    try{
    int* coco1=const_cast<int*>(coco);
    exercise(coco1,coco1+4);
    }catch(std::invalid_argument iva)
    {
        std::cerr<<"catched!\n";//catched!
    }
     
    std::cout<<coco[0]<<coco[4];//15
}